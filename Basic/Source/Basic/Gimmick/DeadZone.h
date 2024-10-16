// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DeadZone.generated.h"

UCLASS()
class BASIC_API ADeadZone : public AActor
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* DeadZone;


protected:
	virtual void PostInitializeComponents() override;

	UFUNCTION()
	virtual void OnOverlapDeadZoneMesh(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
									 class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
									 const FHitResult& SweepResult);

public:	
	// Sets default values for this actor's properties
	ADeadZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
