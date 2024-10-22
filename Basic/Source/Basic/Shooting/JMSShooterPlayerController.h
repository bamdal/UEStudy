// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "JMSShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BASIC_API AJMSShooterPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	// CrossHead class
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDClass;

	// CrossHead UI Property
	UPROPERTY()
	UUserWidget* HUD;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> WinScreenClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> LoseScreenClass;

	FTimerHandle RestartTimerHandle;

	UPROPERTY(EditAnywhere)
	float RestartDelay =3;
	
public:
	virtual void GameHasEnded(class AActor* EndGameFocus, bool bIsWinner) override;
	
protected:
	virtual void BeginPlay() override;
};
