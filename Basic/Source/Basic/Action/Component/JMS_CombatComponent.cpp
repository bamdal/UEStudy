// Fill out your copyright notice in the Description page of Project Settings.


#include "JMS_CombatComponent.h"

#include "Action/BaseEquippable.h"


// Sets default values for this component's properties
UJMS_CombatComponent::UJMS_CombatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UJMS_CombatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UJMS_CombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UJMS_CombatComponent::SetMainWeapon(ABaseEquippable* BaseWeapon)
{
	if(MainWeapon)
	{
		MainWeapon->UnEquipped();
		MainWeapon->Destroy();
	}

	MainWeapon = BaseWeapon;
}

ABaseEquippable* UJMS_CombatComponent::GetMainWeapon()
{
	return MainWeapon;
}

void UJMS_CombatComponent::ResetAttack()
{
	AttackCount = 0;
	IsAttackSaved = false;
}

bool UJMS_CombatComponent::IsCombatEnable()
{
	return IsCombatEnabled;
}