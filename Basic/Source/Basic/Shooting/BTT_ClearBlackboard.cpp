// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_ClearBlackboard.h"

#include "AIController.h"
#include "JMSCharShooter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTT_ClearBlackboard::UBTT_ClearBlackboard()
{
	NodeName = TEXT("Clear Blackboard");
}

EBTNodeResult::Type UBTT_ClearBlackboard::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
		
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
