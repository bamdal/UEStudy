// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Shoot.h"

#include "AIController.h"
#include "JMSCharShooter.h"

UBTT_Shoot::UBTT_Shoot()
{
	NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UBTT_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	if(OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	AJMSCharShooter* JMSCharShooter = Cast<AJMSCharShooter>(OwnerComp.GetAIOwner()->GetPawn());
	if(JMSCharShooter == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	JMSCharShooter->Shoot();
	
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
