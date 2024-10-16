

#include "DelegateListener.h"

#include "Basic/JMSGameInstance.h"
#include "Components/PointLightComponent.h"

ADelegateListener::ADelegateListener()
{
	PrimaryActorTick.bCanEverTick = true;
	
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	SetRootComponent(PointLight);
	PointLight->SetVisibility(false);
	PointLight->SetLightColor(FLinearColor::Blue);
	PointLight->SetIntensity(10000.0f);


	
}

void ADelegateListener::BeginPlay()
{
	Super::BeginPlay();

	UJMSGameInstance* JMSGI = Cast<UJMSGameInstance>(GetWorld()->GetGameInstance());
	if(JMSGI != nullptr)
	{
		JMSGI->DefaultDelegateSignature.BindUObject(this,&ThisClass::EnableLight);
			
	}
	
}

void ADelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ADelegateListener::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UJMSGameInstance* JMSGI = Cast<UJMSGameInstance>(GetWorld()->GetGameInstance());
	if(JMSGI != nullptr)
	{
		JMSGI->DefaultDelegateSignature.Unbind();
			
	}
}

void ADelegateListener::EnableLight()
{
	PointLight->SetVisibility(true);
}
