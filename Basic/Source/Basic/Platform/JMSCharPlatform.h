// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JMSCharBase.h"
#include "JMSCharPlatform.generated.h"

/**
 * 
 */
UCLASS()
class BASIC_API AJMSCharPlatform : public AJMSCharBase
{
	GENERATED_BODY()

public:
	AJMSCharPlatform();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
};
