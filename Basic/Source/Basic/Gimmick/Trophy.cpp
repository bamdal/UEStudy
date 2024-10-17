// Fill out your copyright notice in the Description page of Project Settings.


#include "Trophy.h"

#include "Basic/JMSGameInstance.h"
#include "GameFramework/RotatingMovementComponent.h"


// Sets default values
ATrophy::ATrophy()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRoot);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(DefaultSceneRoot);

	RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));
	RotatingMovement->RotationRate = FRotator(0.0f, 30.0f, 0.0f);
}

// Called when the game starts or when spawned
void ATrophy::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATrophy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float Amplitude = 3.0f;
	float TimeConstant = 5.0f;
	static float RunningTime = 0;
	
	
	RunningTime += DeltaTime;
	float DeltaVal = Amplitude * FMath::Sin(RunningTime * TimeConstant);
	FVector ALoc = FVector(0,0,0);
	ALoc.X = GetActorLocation().X; 
	ALoc.Y = GetActorLocation().Y;
	ALoc.Z = GetActorLocation().Z + DeltaVal;
	SetActorLocation(ALoc);
}


void ATrophy::PostInitializeComponents()
{
	Super::PostInitializeComponents();


	//StaticMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	
	if (StaticMesh)
	{
		StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &ATrophy::OnOverlapTroPhyMesh);
	}
}

void ATrophy::OnOverlapTroPhyMesh(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
                                  class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                  const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue,
	                                 FString::Printf(TEXT("On Overlap Begin -- Name %s"), *OtherActor->GetName()));

	UJMSGameInstance* JMSGI = Cast<UJMSGameInstance>(GetWorld()->GetGameInstance());
	if(JMSGI != nullptr)
	{
		JMSGI->PlayerClearSingnatureDelegate.ExecuteIfBound();
	}

}
