// Fill out your copyright notice in the Description page of Project Settings.


#include "ATest.h"
#include "JMSDebugMecros.h"
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

#pragma region 단순 레이저 쏘기
	/*if (GetWorld())
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
}*/
#pragma endregion


	
}

// Called every frame
void AATest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;

	float DeltaVal = Amplitude * FMath::Sin(RunningTime * TimeConstant);
	AddActorWorldOffset(FVector(0.0f,DeltaVal,0.0f));
	
	FVector Location = GetActorLocation();
	JMSDRAW_SPHERE_SingleFrame(Location);
	JMSDRAW_VECTOR_SingleFrame(Location,Location + (GetActorForwardVector() * 100.0f));
	
	
}

