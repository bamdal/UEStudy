// Fill out your copyright notice in the Description page of Project Settings.


#include "JMSShooterPlayerController.h"

#include "Blueprint/UserWidget.h"

void AJMSShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUD = CreateWidget(this, HUDClass);
	if(HUD != nullptr)
	{
		HUD->AddToViewport();
		
	}
	
}
