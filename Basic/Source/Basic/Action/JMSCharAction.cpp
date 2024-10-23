// Fill out your copyright notice in the Description page of Project Settings.


#include "JMSCharAction.h"

#include "EnhancedInputComponent.h"

void AJMSCharAction::BeginPlay()
{
	Super::BeginPlay();
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
