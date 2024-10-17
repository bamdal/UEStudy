// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MulticastDelegateParamListener.generated.h"

class USpotLightComponent;

UCLASS()
class BASIC_API AMulticastDelegateParamListener : public AActor
{
	GENERATED_BODY()

public:
	FDelegateHandle DelegateHandle1;
	FDelegateHandle DelegateHandle2;

	UPROPERTY()
	USpotLightComponent* SpotLight;

private:
	int32 RotateSpeed;

public:
	int32 GetRotateSpeed() { return RotateSpeed; }
	void SetRotateSpeed(int32 Speed) { RotateSpeed = Speed; };

	void SetLightColor(FLinearColor Color);
	void SetLightColorAndRotate(FLinearColor Color, int32 Speed);

public:
	// Sets default values for this actor's properties
	AMulticastDelegateParamListener();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
