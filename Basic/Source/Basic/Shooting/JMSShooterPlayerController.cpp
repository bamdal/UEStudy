// Fill out your copyright notice in the Description page of Project Settings.


#include "JMSShooterPlayerController.h"

#include "Blueprint/UserWidget.h"

void AJMSShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	if(bIsWinner)
	{
		UUserWidget* WinScreen = CreateWidget(this,WinScreenClass);
		if(WinScreen != nullptr)
		{
			WinScreen->AddToViewport();
		}
	}
	else
	{
		UUserWidget* LoseScreen = CreateWidget(this,LoseScreenClass);
		if(LoseScreen != nullptr)
		{
			LoseScreen->AddToViewport();
		}
	}


	
	GetWorldTimerManager().SetTimer(RestartTimerHandle, this, &AJMSShooterPlayerController::RestartLevel,RestartDelay);
}

void AJMSShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUD = CreateWidget(this, HUDClass);
	if(HUD != nullptr)
	{
		HUD->AddToViewport();
		
	}
	
}
