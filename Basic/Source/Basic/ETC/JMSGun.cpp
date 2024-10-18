// Fill out your copyright notice in the Description page of Project Settings.


#include "JMSGun.h"
#include "Kismet/GameplayStatics.h"
#include "../JMSDebugMecros.h"

// Sets default values
AJMSGun::AJMSGun()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AJMSGun::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AJMSGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AJMSGun::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh,TEXT("MuzzleFlash"));
	UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh,TEXT("MuzzleFlash"));

	FHitResult Hit;
	FVector ShootDirection;
	bool bSuccess = GunTrace(Hit,ShootDirection);
	if(bSuccess)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),ImpactEffect,Hit.Location,ShootDirection.Rotation());
		UGameplayStatics::SpawnSoundAtLocation(GetWorld(),ImpactSound,Hit.Location);
	}

	// Hit.GetAcotr()로 맞은 액터를 가져온다.
}

bool AJMSGun::GunTrace(FHitResult& Hit, FVector& ShootDirection)
{
	// 총알을 날려야 한다 (벡터연산) -> 라인트레이스를 써야 한다.
	AController* OwnerController = GetOwnerController();
	if (OwnerController == nullptr)
	{
		return false;
	}


	FVector Location;
	FRotator Rotation;
	OwnerController->GetPlayerViewPoint(Location, Rotation);
	ShootDirection = -Rotation.Vector();
	FVector End = Location + Rotation.Vector() * MaxRange;

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);		// 나 자신(총) 제외
	Params.AddIgnoredActor(GetOwner());	// 캐릭터 제외
	// 채널 3번에 들어간것대로 라인트래이스를 진행해 맞으면 true 안맞으면 false를 리턴
	return GetWorld()->LineTraceSingleByChannel(Hit,Location,End,ECollisionChannel::ECC_EngineTraceChannel3,Params);

	
}

AController* AJMSGun::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn != nullptr)
	{
		return OwnerPawn->GetController();
	}

	return nullptr;
}
