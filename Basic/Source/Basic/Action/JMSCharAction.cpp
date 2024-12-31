// Fill out your copyright notice in the Description page of Project Settings.


#include "JMSCharAction.h"

#include "EnhancedInputComponent.h"
#include "JMSEnumFile.h"
#include "Component/JMS_CombatComponent.h"
#include "Component/JMS_StatemanagerComponent.h"


AJMSCharAction::AJMSCharAction()
{
	CombatComponent = CreateDefaultSubobject<UJMS_CombatComponent>(TEXT("CombatComponent"));
	AddInstanceComponent(CombatComponent);
	
	StatemanagerComponent = CreateDefaultSubobject<UJMS_StatemanagerComponent>(TEXT("StatemanagerComponent"));
	AddInstanceComponent(StatemanagerComponent);
}


void AJMSCharAction::OnStateBegin(E_CharacterState CharacterState)
{
	if(CharacterState == E_CharacterState::Dead)
	{
		//PerformDeath();
	}


}

/*
void AJMSCharAction::PerformDeath()
{
	EnableRagdoll();
	ApplyHitReactionPhycisVelocity();
	
}

void AJMSCharAction::EnableRagdoll()
{
}

void AJMSCharAction::ApplyHitReactionPhycisVelocity()
{
}
*/

void AJMSCharAction::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
}

void AJMSCharAction::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	// 추가 키 입력
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Looking
		// EnhancedInputComponent->BindAction(IA_Shoot,ETriggerEvent::Started,this,&AJMSCharShooter::Shoot);

		EnhancedInputComponent->BindAction(IA_ToggleAction,ETriggerEvent::Started,this,&AJMSCharAction::ToggleAction);

		EnhancedInputComponent->BindAction(IA_Attack,ETriggerEvent::Started,this,&AJMSCharAction::Attack);
	}
}

void AJMSCharAction::ToggleAction()
{
	
}

void AJMSCharAction::Attack()
{
}



/*
void AJMSCharAction::ContinueAttack()
{
	StatemanagerComponent->SetState(E_CharacterState::Nothing);
}

void AJMSCharAction::ResetAttack()
{
	CombatComponent->ResetAttack();
	StatemanagerComponent->ResetState();
	StatemanagerComponent->SetCurrentAction(E_CharacterAction::Nothing);
}

bool AJMSCharAction::CanReceiveDamage()
{
	return StatemanagerComponent->GetCurrentState() != E_CharacterState::Dead;

}
*/
