// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/JMSCharBase.h"
#include "JMSCharAction.generated.h"

/**
 * 
 */
UCLASS()
class BASIC_API AJMSCharAction : public AJMSCharBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* IA_ToggleAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* IA_Attack;
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void ToggleAction();
	void Attack();
};
