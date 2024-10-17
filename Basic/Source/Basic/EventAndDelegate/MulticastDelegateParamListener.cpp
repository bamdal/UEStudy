// Fill out your copyright notice in the Description page of Project Settings.


#include "MulticastDelegateParamListener.h"

#include "Basic/JMSGameInstance.h"
#include "Components/SpotLightComponent.h"


// Sets default values
AMulticastDelegateParamListener::AMulticastDelegateParamListener()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpotLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotLight"));
	SetRootComponent(SpotLight);
	SpotLight->SetIntensity(10000.0f);


	SetRotateSpeed(0);


}

// Called when the game starts or when spawned
void AMulticastDelegateParamListener::BeginPlay()
{
	Super::BeginPlay();
	
	UJMSGameInstance* JMSGI = Cast<UJMSGameInstance>(GetWorld()->GetGameInstance());
	if (JMSGI != nullptr)
	{
		DelegateHandle1 = JMSGI->MulticastDelegateSignatureParam1.AddUObject(this, &ThisClass::SetLightColor);
		DelegateHandle2 = JMSGI->MulticastDelegateSignatureParam2.AddUObject(
			this, &AMulticastDelegateParamListener::SetLightColorAndRotate);
	}
}

void AMulticastDelegateParamListener::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	
	UJMSGameInstance* JMSGI = Cast<UJMSGameInstance>(GetWorld()->GetGameInstance());
	if (JMSGI != nullptr)
	{
		JMSGI->MulticastDelegateSignatureParam1.Remove(DelegateHandle1);
		JMSGI->MulticastDelegateSignatureParam2.Remove(DelegateHandle2);
	}
}

// Called every frame
void AMulticastDelegateParamListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetRotateSpeed() > 0)
	{
		AddActorLocalRotation(FRotator(0.0f, GetRotateSpeed() * DeltaTime, 0.0f));
	}
}


void AMulticastDelegateParamListener::SetLightColor(FLinearColor Color)
{
	SpotLight->SetLightColor(Color);
	SetRotateSpeed(0);
}

void AMulticastDelegateParamListener::SetLightColorAndRotate(FLinearColor Color, int32 Speed)
{
	SpotLight->SetLightColor(Color);
	SetRotateSpeed(Speed);
}
