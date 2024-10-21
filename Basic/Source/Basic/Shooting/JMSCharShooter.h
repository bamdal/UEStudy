// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JMSCharBase.h"
#include "JMSCharShooter.generated.h"

class AJMSGun;
/**
 *  총쓰는 캐릭터
 */
UCLASS()
class BASIC_API AJMSCharShooter : public AJMSCharBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AJMSGun> JMSGunClass;
	
	UPROPERTY()
	AJMSGun* Gun;

public:
	UPROPERTY(EditAnywhere, Category= Input)
	UInputAction* IA_Shoot;

	void Shoot();
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	
};
