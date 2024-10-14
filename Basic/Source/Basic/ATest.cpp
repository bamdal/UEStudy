// Fill out your copyright notice in the Description page of Project Settings.


#include "ATest.h"
#include "DebugMecros.h"
// Sets default values
AATest::AATest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AATest::BeginPlay()
{
	Super::BeginPlay();
	
	if (GetWorld())
	{
		FVector Location = GetActorLocation();
		JMSDRAW_SPHERE(Location);

		FVector Start, End;
		Start = Location;
		End = GetActorForwardVector() * 1000;

		JMSDRAW_VECTOR(Start, End);
		//JMSDRAW_POINT(End);

		//DrawDebugLine(GetWorld(), Start, End, FColor::Blue, true, 100);

		
		//DrawDebugSphere(GetWorld(), GetActorLocation(), 50.0f, 12, FColor::Green, true);
	}

}

// Called every frame
void AATest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

