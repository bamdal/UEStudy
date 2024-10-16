

#include "DelegateParamTrigger.h"

#include "Basic/JMSGameInstance.h"
#include "Components/CapsuleComponent.h"

ADelegateParamTrigger::ADelegateParamTrigger()
{
	PrimaryActorTick.bCanEverTick = true;

	TriggerZone = CreateDefaultSubobject<UCapsuleComponent>(TEXT("TriggerZone"));
	TriggerZone->InitCapsuleSize(200.0f,350.0f);
	RotateSpeed = 0;
}

void ADelegateParamTrigger::BeginPlay()
{
	Super::BeginPlay();


}

void ADelegateParamTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ADelegateParamTrigger::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	auto Message = FString::Printf(TEXT("%s BeginOverlap"),*(OtherActor->GetName()));
	GEngine->AddOnScreenDebugMessage(-1,1,FColor::Red,Message);
	
	UWorld* World = GetWorld();
	if(World != nullptr)
	{
		UJMSGameInstance* JMSGI = Cast<UJMSGameInstance>(World->GetGameInstance());
		if(JMSGI != nullptr)
		{
			JMSGI->DefaultDelegateSignatureParam1.ExecuteIfBound(LightColor);
			
		}
	}
}

void ADelegateParamTrigger::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	auto Message = FString::Printf(TEXT("%s EndOverlap"),*OtherActor->GetName());
	GEngine->AddOnScreenDebugMessage(-1,1,FColor::Blue,Message);
	
	UWorld* World = GetWorld();
	if(World != nullptr)
	{
		UJMSGameInstance* JMSGI = Cast<UJMSGameInstance>(World->GetGameInstance());
		if(JMSGI != nullptr)
		{
			JMSGI->DefaultDelegateSignatureParam2.ExecuteIfBound(FLinearColor(1.0f,0.0f,0.0f),RotateSpeed);
			
		}
	}
}
