

#include "DelegeteTrigger.h"

#include "Basic/JMSGameInstance.h"
#include "Components/SphereComponent.h"


ADelegeteTrigger::ADelegeteTrigger()
{
	PrimaryActorTick.bCanEverTick = true;

	TriggerZone = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerZone"));
}

void ADelegeteTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADelegeteTrigger::Tick(float DeltaTime)	
{
	Super::Tick(DeltaTime);

}


void ADelegeteTrigger::NotifyActorBeginOverlap(AActor* OtherActor)
{
	UWorld* World = GetWorld();
	if(World != nullptr)
	{
		UJMSGameInstance* JMSGI = Cast<UJMSGameInstance>(World->GetGameInstance());
		if(JMSGI != nullptr)
		{
			JMSGI->DefaultDelegateSignature.ExecuteIfBound();
			
		}
	}
}

void ADelegeteTrigger::NotifyActorEndOverlap(AActor* OtherActor)
{
	
}