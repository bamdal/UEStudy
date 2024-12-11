// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/JMSCharBase.h"
#include "Interface/JMS_EX_Action.h"
#include "JMSCharAction.generated.h"

enum class E_CharacterState : uint8;
class UJMS_StatemanagerComponent;
class UJMS_CombatComponent;
/**
 * 
 */
UCLASS()
class BASIC_API AJMSCharAction : public AJMSCharBase,public IJMS_EX_Action
{
	GENERATED_BODY()
private:

	int32 CurrentHealth = 0;

	FName PelvisBoneName = TEXT("pelvis");
public:

	UPROPERTY(EditAnywhere)
	int32 MaxHealth = 100;
	
	AJMSCharAction();
	
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* IA_ToggleAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* IA_Attack;

	UFUNCTION()
	void ContinueAttack();
	
	UFUNCTION()
	void ResetAttack();
	
	UFUNCTION()
	bool CanReceiveDamage();

	UPROPERTY()
	UJMS_CombatComponent* CombatComponent;

	UPROPERTY()
	UJMS_StatemanagerComponent* StatemanagerComponent;
	
	UFUNCTION()
	void OnStateBegin(E_CharacterState CharacterState);

	// 사망 시작 처리
	UFUNCTION()
	void PerformDeath();

	UFUNCTION()
	void EnableRagdoll();
	UFUNCTION()
	void ApplyHitReactionPhycisVelocity();
protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void ToggleAction();
	void Attack();
	
	
};
