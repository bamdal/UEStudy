// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MulticastDelegateTrigger.generated.h"

class UBoxComponent;

UCLASS()
class BASIC_API AMulticastDelegateTrigger : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY()
	UBoxComponent* TriggerZone;

public:
	UFUNCTION()
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	UFUNCTION()
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;




	
public:	
	// Sets default values for this actor's properties
	AMulticastDelegateTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
