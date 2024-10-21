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

	UPROPERTY(EditAnywhere)
	float MaxHealth = 100;
	
	UPROPERTY(EditAnywhere)
	float Health = MaxHealth;

public:
	UPROPERTY(EditAnywhere, Category= Input)
	UInputAction* IA_Shoot;

	void Shoot();

	UFUNCTION(BlueprintPure)
	bool IsDead() const;

	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	
protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	
};
