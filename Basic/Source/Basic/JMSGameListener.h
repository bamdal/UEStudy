// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JMSGameListener.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class BASIC_API AJMSGameListener : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	UUserWidget* PlayerDieWidget;

	UPROPERTY(EditAnywhere)
	UUserWidget* GameClearWidget;

	USpringArmComponent* SpringArm;
	
	UPROPERTY()
	APawn* UserPawn;
	
	void PlayerDie();
	void GameClear();

	
	
public:	
	// Sets default values for this actor's properties
	AJMSGameListener();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
