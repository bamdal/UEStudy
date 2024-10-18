// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JMSCharBase.h"
#include "JMSCharShooter.generated.h"

/**
 * 
 */
UCLASS()
class BASIC_API AJMSCharShooter : public AJMSCharBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
};
