// Fill out your copyright notice in the Description page of Project Settings.


#include "JMS_StatemanagerComponent.h"

#include "Action/JMSEnumFile.h"


// Sets default values for this component's properties
UJMS_StatemanagerComponent::UJMS_StatemanagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UJMS_StatemanagerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

void UJMS_StatemanagerComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	OnStateBegin.Unbind();
	OnStateEnd.Unbind();
	OnCharacterActionBegin.Unbind();
	OnCharacterActionEnd.Unbind();
}


// Called every frame
void UJMS_StatemanagerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UJMS_StatemanagerComponent::SetState(E_CharacterState NewState)
{
	if (CurrentState != NewState)
	{
		OnStateEnd.Execute(CurrentState);
		CurrentState = NewState;
		OnStateBegin.Execute(CurrentState);
	}
}

E_CharacterState UJMS_StatemanagerComponent::GetCurrentState()
{
	return CurrentState;
}

void UJMS_StatemanagerComponent::ResetState()
{
	SetState(E_CharacterState::Nothing);
}

bool UJMS_StatemanagerComponent::IsCurrentStateEqulToAny(TArray<E_CharacterState> StateToCheack)
{
	return StateToCheack.Contains(CurrentState);
}

void UJMS_StatemanagerComponent::SetCurrentAction(E_CharacterAction NewAction)
{
	if(NewAction != CurrentCharacterAction)
	{
		OnCharacterActionEnd.Execute(CurrentCharacterAction);
		CurrentCharacterAction = NewAction;
		OnCharacterActionBegin.Execute(CurrentCharacterAction);
	}
	
}

E_CharacterAction UJMS_StatemanagerComponent::GetCurrentAction()
{
	return CurrentCharacterAction;
}

void UJMS_StatemanagerComponent::ResetCurrentAction()
{
	CurrentCharacterAction = E_CharacterAction::Nothing;
}
