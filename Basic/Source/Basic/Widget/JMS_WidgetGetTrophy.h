// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "JMS_WidgetGetTrophy.generated.h"

/**
 * 
 */
UCLASS()
class BASIC_API UJMS_WidgetGetTrophy : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual bool Initialize() override;
	void GameClear();
};
