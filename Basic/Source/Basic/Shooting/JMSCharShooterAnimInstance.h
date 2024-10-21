// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JMSCharBaseAnimInstance.h"
#include "JMSCharShooterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class BASIC_API UJMSCharShooterAnimInstance : public UJMSCharBaseAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = AO)
	float Angle = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = AO)
	float AimPitch = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = Shooter)
	bool IsDead = false;

protected:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
};
