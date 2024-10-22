// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "JMS_ShooterGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class BASIC_API AJMS_ShooterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	/**
	 * 해당 폰이 사망했다
	 * @param PawnKilled 
	 */
	virtual void PawnKilled(APawn* PawnKilled);
	
private:
	/**
	 * 게임 종료 함수
	 * true : 모든 적대개체 제거
	 * false : 플레이어 사망
	 * @param bIsPlayerWin true 승리 false 패배 
	 */
	void EndGame(bool bIsPlayerWin);
};
