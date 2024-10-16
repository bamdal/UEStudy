// Fill out your copyright notice in the Description page of Project Settings.


#include "MulticastDelegateListener.h"

#include "Basic/JMSGameInstance.h"
#include "Components/PointLightComponent.h"

// Sets default values
AMulticastDelegateListener::AMulticastDelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	SetRootComponent(PointLight);
	PointLight->SetVisibility(false);
	
}


// Called when the game starts or when spawned
void AMulticastDelegateListener::BeginPlay()
{
	Super::BeginPlay();
	
	UJMSGameInstance* JMSGI= Cast<UJMSGameInstance>(GetWorld()->GetGameInstance());
	if(JMSGI != nullptr)
	{
		// 핸들 바인드
		DelegateHandle = JMSGI->MulticastDelegateSignature.AddUObject(this, &ThisClass::ToggleLight);
	}
}

void AMulticastDelegateListener::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	UJMSGameInstance* JMSGI= Cast<UJMSGameInstance>(GetWorld()->GetGameInstance());
	if(JMSGI != nullptr)
	{
		// 핸들 리무브
		JMSGI->MulticastDelegateSignature.Remove(DelegateHandle);
	}
}

// Called every frame
void AMulticastDelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMulticastDelegateListener::ToggleLight()
{
	PointLight->ToggleVisibility();
}


