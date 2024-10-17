// Fill out your copyright notice in the Description page of Project Settings.


#include "DeadZone.h"

#include "Basic/JMSGameInstance.h"
#include "Basic/Widget/JMSUserWidget.h"
#include "Blueprint/UserWidget.h"


// Sets default values
ADeadZone::ADeadZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DeadZone = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DeadZone"));
	SetRootComponent(DeadZone);
	

}

// Called when the game starts or when spawned
void ADeadZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADeadZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADeadZone::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if(DeadZone)
	{
		DeadZone->OnComponentBeginOverlap.AddDynamic(this,&ADeadZone::OnOverlapDeadZoneMesh);
	}
}

void ADeadZone::OnOverlapDeadZoneMesh(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 사망 델리게이트 날리기
	UJMSGameInstance* JMSGI = Cast<UJMSGameInstance>(GetWorld()->GetGameInstance());
	if(JMSGI != nullptr)
	{
		JMSGI->PlayerDieSingnatureDelegate.ExecuteIfBound();
	}


}
