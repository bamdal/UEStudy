// Fill out your copyright notice in the Description page of Project Settings.


#include "Fountain.h"	// 클래스 헤더(보통 맨 처음 선언)

// 클래스 헤더내 전방선언 한것 중 CoreMinimal.h or EngineMinimal.h에 포함 안된것들
#include "Components/PointLightComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AFountain::AFountain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	SetRootComponent(Body);

	// BP에서 변경 불가능한 부모 자식 관계 설정
	Water = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Water"));
	Water->SetupAttachment(Body);
	Water->SetRelativeLocation(FVector(0, 0, 135.0f));

	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
	Light->SetupAttachment(Body);
	Light->SetRelativeLocation(FVector(0, 0, 135.0f));
	
	Splash = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Splash"));
	Splash->SetupAttachment(Body);
	Splash->SetRelativeLocation(FVector(0, 0, 135.0f));
	// 경로 못찾게 되면 크래시 날 수 있수 있고 에디터에서 수정이 안된다.
	/*static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Body(TEXT("/Game/EX10_CPP/Fountain/SM_Fountain.SM_Fountain"));
	if(SM_Body.Succeeded())
	{
		Body->SetStaticMesh(SM_Body.Object);
	}*/

	Movement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("Movement"));
	Movement->RotationRate =FRotator(0.0f,30.0f,0.0f);
	
}

// 액터 기본 오버라이딩 함수들
// Called when the game starts or when spawned
void AFountain::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFountain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

