// Fill out your copyright notice in the Description page of Project Settings.


#include "JMSShooterAIController.h"

#include "Kismet/GameplayStatics.h"

void AJMSShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	// BT 실행
}

void AJMSShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	//플레이어 폰이 시야에 온다면
	if(LineOfSightTo(PlayerPawn) == true)
	{
		// 추적 설정
		SetFocus(PlayerPawn);

		// 액터를 향해 이동
		MoveToActor(PlayerPawn,200);	// 2미터 반경 까지만 움직임
	}
	else
	{
		// 추적 클리어
		ClearFocus((EAIFocusPriority::Gameplay));

		// 멈추기
		StopMovement();
	}
}
