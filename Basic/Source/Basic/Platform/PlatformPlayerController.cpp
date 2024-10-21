// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformPlayerController.h"

#include "Blueprint/UserWidget.h"


void APlatformPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void APlatformPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	GetWorld()->GetTimerManager().ClearTimer(RestartTimer);
}


void APlatformPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	if(bIsWinner)
	{
		// 승리
		UUserWidget* WinScreen = CreateWidget(this,WinScreenClass);
		if(WinScreen != nullptr)
		{
			WinScreen->AddToViewport();
		}
	}
	else
	{
		// 패배
		UUserWidget* LoseScreen = CreateWidget(this,LoseScreenClass);
		int i =0;
		if(LoseScreen != nullptr)
		{
			LoseScreen->AddToViewport();
		}
	}

	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel,RestartDelay);
	
}
