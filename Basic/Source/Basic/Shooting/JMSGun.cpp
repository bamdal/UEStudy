// Fill out your copyright notice in the Description page of Project Settings.


#include "JMSGun.h"

#include "JMSShooterPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "../JMSDebugMecros.h"
#include "Engine/DamageEvents.h"

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
	// 발사 상태 변환
	// bool bSuccess = GunTrace(Hit, ShootDirection);
	bool bSuccess = GunTrace(Hit, ShootDirection);
	if (bSuccess)
	{
		// 타격 이펙트, 사운드 출력
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.Location, ShootDirection.Rotation());
		UGameplayStatics::SpawnSoundAtLocation(GetWorld(), ImpactSound, Hit.Location);

		AActor* HitActor = Hit.GetActor();
		if(HitActor != nullptr)	// 액터 객체에 맞았다면
		{
			// 데미지 산출공식(어디 맞은건지 생략)
			FPointDamageEvent DamageEvent(Damage,Hit,ShootDirection,nullptr);
			AController* OwnerController = GetOwnerController();
			HitActor->TakeDamage(Damage,DamageEvent,OwnerController,this);
		}
	}

	// Hit.GetAcotr()로 맞은 액터를 가져온다.
}

// 카메라에서 총알 날아가기
bool AJMSGun::GunTrace(FHitResult& Hit, FVector& ShootDirection)
{
	// 총알을 날려야 한다 (벡터연산) -> 라인트레이스를 써야 한다.
	
	AController* OwnerController = GetOwnerController();
	if (OwnerController == nullptr) 
	{
		return false;
	}


	// 카메라가 보고있는 ViewPortSize 가져오기
	/*
	FVector2D ViewPortSize;
	if (GEngine && GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize(ViewPortSize);
	}
	FVector2D CrosshairLocation(ViewPortSize.X / 2.0f, ViewPortSize.Y / 2.0f);
	*/


	FVector Start;
	FRotator Rotation;
	// 컨트롤러의 주인이 보는 뷰포트값 설정
	OwnerController->GetPlayerViewPoint(Start, Rotation);
	ShootDirection = -Rotation.Vector();
	FVector End ;
	// 총을 쏜 주체가 플레이어라면
	if(AJMSShooterPlayerController* PlayerController = Cast<AJMSShooterPlayerController>(OwnerController))
	{
		End = Start + Rotation.Vector() * MaxRange;
		// 발사 시작 시점을 총구로 설정
		if(Mesh != nullptr)
		{
			Start = Mesh->GetSocketLocation(TEXT("MuzzleFlash"));
		}
	}
	else
	{
		End = Start + Rotation.Vector() * MaxRange;
	}


	

	DrawDebugCamera(GetWorld(),Start, Rotation,90,2,FColor::Red,true);
	JMSDRAW_VECTOR(Start,End);

	// 쿼리를 날릴떄 나는 제외 시키키
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this); // 나 자신(총) 제외
	Params.AddIgnoredActor(GetOwner()); // 캐릭터 제외
	// 채널 3번에 들어간것대로 라인트래이스를 진행해 맞으면 true 안맞으면 false를 리턴
	return GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECollisionChannel::ECC_EngineTraceChannel3, Params);
}

// 총구에서 총알 날라가기
bool AJMSGun::GunTrace2(FHitResult& Hit, FVector& ShootDirection)
{

	AController* OwnerController = GetOwnerController();
	if (OwnerController == nullptr)
	{
		return false;
	}
	
	FVector Location;
	FRotator Rotation;
	OwnerController->GetPlayerViewPoint(Location, Rotation);
	ShootDirection = -Rotation.Vector();

	// 유저 컨트롤러와 AI컨트롤러일때 분기
	if(Mesh != nullptr)
	{
		Location = Mesh->GetSocketLocation(TEXT("MuzzleFlash"));
	}
	FVector End = Location + Rotation.Vector() * MaxRange;

	JMSDRAW_VECTOR(Location,End);
	
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this); // 나 자신(총) 제외
	Params.AddIgnoredActor(GetOwner()); // 캐릭터 제외
	// 채널 3번에 들어간것대로 라인트래이스를 진행해 맞으면 true 안맞으면 false를 리턴
	return GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_EngineTraceChannel3, Params);

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
