// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "JMS_BTS_PlayerLocationlSeen.generated.h"

/**
 * 
 */
UCLASS()
class BASIC_API UJMS_BTS_PlayerLocationlSeen : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UJMS_BTS_PlayerLocationlSeen();

protected:
	 virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	
};
