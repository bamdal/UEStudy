// Fill out your copyright notice in the Description page of Project Settings.


#include "JMSShooterAIController.h"

#include "JMSCharShooter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

void AJMSShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	// BT 실행
	if(EnemyBT != nullptr)
	{
		RunBehaviorTree(EnemyBT);

		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
		SetFocus(PlayerPawn);

		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocationKey"),GetPawn()->GetActorLocation());
		
	}
}

void AJMSShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// // BT로 처리한다.
	// APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	// //플레이어 폰이 시야에 온다면
	// if(LineOfSightTo(PlayerPawn) == true)
	// {
	// 	// 추적 설정
	// 	SetFocus(PlayerPawn);
	//
	// 	// 액터를 향해 이동
	// 	MoveToActor(PlayerPawn,200);	// 2미터 반경 까지만 움직임
	// }
	// else
	// {
	// 	// 추적 클리어
	// 	ClearFocus((EAIFocusPriority::Gameplay));
	//
	// 	// 멈추기
	// 	StopMovement();
	// }
}

bool AJMSShooterAIController::IsDead() const
{
	AJMSCharShooter* ControllerdCharacter = Cast<AJMSCharShooter>(GetPawn());
	if(ControllerdCharacter != nullptr)
	{
		return ControllerdCharacter->IsDead();
	}
	return true;
}
