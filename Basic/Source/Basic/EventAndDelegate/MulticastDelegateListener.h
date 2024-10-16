// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MulticastDelegateListener.generated.h"

class UPointLightComponent;

UCLASS()
class BASIC_API AMulticastDelegateListener : public AActor
{
	GENERATED_BODY()


public:
	FDelegateHandle DelegateHandle;

	UPROPERTY()
	UPointLightComponent* PointLight;

	UFUNCTION()
	void ToggleLight();

protected:
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;	


	
public:	
	// Sets default values for this actor's properties
	AMulticastDelegateListener();


	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
