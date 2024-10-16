// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegeteTrigger.generated.h"

class USphereComponent;

UCLASS()
class BASIC_API ADelegeteTrigger : public AActor
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere)
	USphereComponent* TriggerZone;
	
	UFUNCTION()
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	UFUNCTION()
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	
public:	
	// Sets default values for this actor's properties
	ADelegeteTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
