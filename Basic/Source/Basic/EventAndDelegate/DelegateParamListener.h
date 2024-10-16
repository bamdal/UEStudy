// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateParamListener.generated.h"

class USpotLightComponent;

UCLASS()
class BASIC_API ADelegateParamListener : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY()
	USpotLightComponent* SpotLight;

private:
	int32 RotateSpeed;

public:
	int32 GetRotateSpeed() { return RotateSpeed; }
	void SetRotateSpeed(int32 bState) { RotateSpeed = bState; }

	UFUNCTION()
	void SetLightColor(FLinearColor LightColor);
	UFUNCTION()
	void SetLightColorAndRotate(FLinearColor LightColor, int32 Speed);
	
	
public:	
	// Sets default values for this actor's properties
	ADelegateParamListener();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
