// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATest.generated.h"

UCLASS()
class BASIC_API AATest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AATest();
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	UPROPERTY(EditDefaultsOnly)
	int32 EDOVal = 1;
	UPROPERTY(EditInstanceOnly)
	int32 EIOVal = 2;
	UPROPERTY(EditAnywhere)
	int32 EAVal = 3;
	UPROPERTY(VisibleDefaultsOnly)
	int32 VDOVal = 11;
	UPROPERTY(VisibleInstanceOnly)
	int32 VIOVal = 22;
	UPROPERTY(VisibleAnywhere)
	int32 VAVal = 33;
	//UPROPERTY(EditAnywhere)
	//FString TestStr = 'a';


};
