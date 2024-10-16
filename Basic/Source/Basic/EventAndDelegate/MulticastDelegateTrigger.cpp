// Fill out your copyright notice in the Description page of Project Settings.


#include "MulticastDelegateTrigger.h"

#include "Basic/JMSGameInstance.h"
#include "Components/BoxComponent.h"

// Sets default values
AMulticastDelegateTrigger::AMulticastDelegateTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerZone = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerZone"));
	TriggerZone->SetBoxExtent(FVector(200.0f, 200.0f, 200.0f));
}

// Called when the game starts or when spawned
void AMulticastDelegateTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMulticastDelegateTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMulticastDelegateTrigger::NotifyActorBeginOverlap(AActor* OtherActor)
{
	auto Message = FString::Printf(TEXT("%s BeginOverlap"),*(OtherActor->GetName()));
	GEngine->AddOnScreenDebugMessage(-1,1,FColor::Red,Message);
	
	UWorld* World = GetWorld();
	if(World != nullptr)
	{
		UJMSGameInstance* JMSGI = Cast<UJMSGameInstance>(World->GetGameInstance());
		if(JMSGI != nullptr)
		{
			JMSGI->MulticastDelegateSignature.Broadcast();
			
		}
	}
}

void AMulticastDelegateTrigger::NotifyActorEndOverlap(AActor* OtherActor)
{
	auto Message = FString::Printf(TEXT("%s EndOverlap"),*OtherActor->GetName());
	GEngine->AddOnScreenDebugMessage(-1,1,FColor::Blue,Message);
	
	UWorld* World = GetWorld();
	if(World != nullptr)
	{
		UJMSGameInstance* JMSGI = Cast<UJMSGameInstance>(World->GetGameInstance());
		if(JMSGI != nullptr)
		{
			JMSGI->MulticastDelegateSignature.Broadcast();
			
		}
	}
}
