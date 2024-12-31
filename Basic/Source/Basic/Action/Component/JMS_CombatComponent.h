// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "JMS_CombatComponent.generated.h"


class ABaseEquippable;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BASIC_API UJMS_CombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetMainWeapon(ABaseEquippable* BaseWeapon);

	UFUNCTION(BlueprintPure)
	ABaseEquippable* GetMainWeapon();

	UFUNCTION(BlueprintCallable)
	void ResetAttack();

	UFUNCTION(BlueprintCallable)
	bool IsCombatEnable();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 AttackCount = 0;
	
private:
	UPROPERTY()
	ABaseEquippable* MainWeapon;

	bool IsCombatEnabled =false;

	bool IsAttackSaved =false;



	float Health = 0;
public:	
	// Sets default values for this component's properties
	UJMS_CombatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
