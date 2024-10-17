// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Trophy.generated.h"

class URotatingMovementComponent;

UCLASS()
class BASIC_API ATrophy : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY()
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY()
	URotatingMovementComponent* RotatingMovement;

protected:
	virtual void PostInitializeComponents() override;

	UFUNCTION()
	virtual void OnOverlapTroPhyMesh(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	                                 class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	                                 const FHitResult& SweepResult);

public:
	// Sets default values for this actor's properties
	ATrophy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
