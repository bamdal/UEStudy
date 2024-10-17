// Fill out your copyright notice in the Description page of Project Settings.


#include "MulticastDelegateParamTrigger.h"

#include "Basic/JMSGameInstance.h"
#include "Components/BoxComponent.h"


// Sets default values
AMulticastDelegateParamTrigger::AMulticastDelegateParamTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerZone = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerZone"));
	TriggerZone->SetBoxExtent(FVector(200.0f, 200.0f, 200.0f));
	SetRootComponent(TriggerZone);

	
}

// Called when the game starts or when spawned
void AMulticastDelegateParamTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMulticastDelegateParamTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMulticastDelegateParamTrigger::NotifyActorBeginOverlap(AActor* OtherActor)
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
			JMSGI->MulticastDelegateSignatureParam1.Broadcast(LightColor);
			
		}
	}
}

void AMulticastDelegateParamTrigger::NotifyActorEndOverlap(AActor* OtherActor)
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
				JMSGI->MulticastDelegateSignatureParam2.Broadcast(FLinearColor(1.0f,0.0f,0.0f),RotateSpeed);
			
		}
	}
}