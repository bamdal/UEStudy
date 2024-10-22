// Fill out your copyright notice in the Description page of Project Settings.


#include "JMS_ShooterGameModeBase.h"

#include "EngineUtils.h"
#include "JMSDebugMecros.h"
#include "JMSShooterAIController.h"

// 나 또는 AI가 죽었을떄
void AJMS_ShooterGameModeBase::PawnKilled(APawn* PawnKilled)
{
	HLOG(Warning, TEXT("PawnKilled"));

	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
	// 플레이어 사망
	if (PlayerController != nullptr)
	{
		// 패배
		EndGame(false);
		return;
	}

	// AI 사망
	for(AJMSShooterAIController* Controller : TActorRange<AJMSShooterAIController>(GetWorld()))
	{
		// AI 가 남아있다
		if(!Controller->IsDead())
		{
			return;
		}
	}

	// 승리
	EndGame(true);
}

void AJMS_ShooterGameModeBase::EndGame(bool bIsPlayerWin)
{
	// LEVEL에 AIController 개수를 파악 -> 비효율적
	// 개별 Pool을 만들어서 관리하고 그 PoolContainer에서 관리해야한다.
	for(AController* Controller : TActorRange<AController>(GetWorld()))
	{
		if(bIsPlayerWin && Controller->IsPlayerController())
		{
			// 승리
			Controller->GameHasEnded(Controller->GetPawn(),bIsPlayerWin);
		}
		else
		{
			// 패배
			Controller->GameHasEnded(Controller->GetPawn(),bIsPlayerWin);
		}
	} 
}
