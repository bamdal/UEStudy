// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "JMSShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class BASIC_API AJMSShooterAIController : public AAIController
{
	GENERATED_BODY()

private:
	// Enemy AI용 BT
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* EnemyBT;

protected:
	virtual void BeginPlay() override;
	
public:
	virtual void Tick(float DeltaTime) override;
	
};
