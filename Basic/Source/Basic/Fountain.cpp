// Fill out your copyright notice in the Description page of Project Settings.


#include "Fountain.h"
#include "GameFramework/RotatingMovementComponent.h"

// Sets default values
AFountain::AFountain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	SetRootComponent(Body);


	Water = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Water"));
	Water->SetupAttachment(Body);
	Water->SetRelativeLocation(FVector(0, 0, 135.0f));

	//
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Body(TEXT("/Game/EX10_CPP/Fountain/SM_Fountain.SM_Fountain"));
	if(SM_Body.Succeeded())
	{
		Body->SetStaticMesh(SM_Body.Object);
	}

	Movement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("Movement"));
	Movement->RotationRate =FRotator(0.0f,30.0f,0.0f);
	
}

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

