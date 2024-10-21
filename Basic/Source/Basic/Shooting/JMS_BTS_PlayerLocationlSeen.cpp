// Fill out your copyright notice in the Description page of Project Settings.


#include "JMS_BTS_PlayerLocationlSeen.h"

#include "AIController.h"
#include "Kismet/GameplayStatics.h"

UJMS_BTS_PlayerLocationlSeen::UJMS_BTS_PlayerLocationlSeen()
{
	NodeName= "Update Player Location if Seen";
}

void UJMS_BTS_PlayerLocationlSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	// 플레이어 폰 유무
	if(PlayerPawn != nullptr)
	{
		return;
	}

	// BT 컴포넌트 유무
	if(OwnerComp.GetAIOwner() == nullptr)
	{
		return;
	}

	if(OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn) == true)
	{
		// BT에 바인딩한 블랙보드 키에 폰을 설정
	}
	else
	{
		// 지우기
	}
}
