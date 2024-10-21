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

protected:
	virtual void BeginPlay() override;
};
