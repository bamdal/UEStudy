// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "JMS_StatemanagerComponent.generated.h"


enum class E_CharacterAction : uint8;
enum class E_CharacterState : uint8;

DECLARE_DELEGATE_OneParam(FOnStateBegin,E_CharacterState)
DECLARE_DELEGATE_OneParam(FOnStateEnd,E_CharacterState)
DECLARE_DELEGATE_OneParam(FOnCharacterActionBegin,E_CharacterAction)
DECLARE_DELEGATE_OneParam(FOnCharacterActionEnd,E_CharacterAction)
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BASIC_API UJMS_StatemanagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	void SetState(E_CharacterState NewState);
	E_CharacterState GetCurrentState();
	void ResetState();
	bool IsCurrentStateEqulToAny(TArray<E_CharacterState> StateToCheack);
	void SetCurrentAction(E_CharacterAction NewAction);
	E_CharacterAction GetCurrentAction();
	void ResetCurrentAction();


	// 델리게이트
	FOnStateBegin OnStateBegin;
	FOnStateEnd OnStateEnd;
	FOnCharacterActionBegin OnCharacterActionBegin;
	FOnCharacterActionEnd OnCharacterActionEnd;
private:
	E_CharacterState CurrentState;
	E_CharacterAction CurrentCharacterAction;

public:
	// Sets default values for this component's properties
	UJMS_StatemanagerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
