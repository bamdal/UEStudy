// Fill out your copyright notice in the Description page of Project Settings.


#include "JMSGameListener.h"

#include "AnimationEditorViewportClient.h"
#include "Components/PrimitiveComponent.h"
#include "JMSGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "../Platform//PlatformPlayerController.h"
#include "Elements/Framework/TypedElementQueryBuilder.h"
#include "Kismet/GameplayStatics.h"
#include "Storage/Bundles/V2/PacketHandle.h"


// Sets default values
AJMSGameListener::AJMSGameListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AJMSGameListener::BeginPlay()
{
	Super::BeginPlay();

	UserPawn = Cast<APawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	
		
	UJMSGameInstance* JMSGI = Cast<UJMSGameInstance>(GetWorld()->GetGameInstance());
	if (JMSGI != nullptr)
	{
		JMSGI->PlayerDieSingnatureDelegate.BindUObject(this,&AJMSGameListener::PlayerDie);
		JMSGI->PlayerClearSingnatureDelegate.BindUObject(this,&AJMSGameListener::GameClear);
	}
	
}

void AJMSGameListener::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	UJMSGameInstance* JMSGI = Cast<UJMSGameInstance>(GetWorld()->GetGameInstance());
	if (JMSGI != nullptr)
	{
		JMSGI->PlayerDieSingnatureDelegate.Unbind();
		JMSGI->PlayerClearSingnatureDelegate.Unbind();
	}
}

// Called every frame
void AJMSGameListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// 플레이어 사망시 불림
void AJMSGameListener::PlayerDie()
{
	//캐릭터가 위젯띄우게 부르기
	if(APlatformPlayerController* PlatformPlayerController = Cast<APlatformPlayerController>(GetWorld()->GetFirstPlayerController()))
	{
		PlatformPlayerController->GameHasEnded(nullptr,false);
	}

	if(false)
	{
		// JMSGameListener에서 위젯 띄우기

			if(UserPawn != nullptr)
        	{
        		
        		
        		UserPawn->UnPossessed();
        		UPrimitiveComponent* UserComp = Cast<UPrimitiveComponent>(UserPawn->GetComponentByClass(UPrimitiveComponent::StaticClass()));
        		if(UserComp != nullptr)
        			UserComp->SetSimulatePhysics(true);
        
        
        	}
        	
        	if(PlayerDieWidget != nullptr)
        	{
        		PlayerDieWidget->AddToViewport();
        	}
        
        	
        	FTimerHandle TimerHandle;
        	GetWorld()->GetTimerManager().SetTimer(TimerHandle,[this]()
        	{	FName CurrentLevelName = FName(GetWorld()->GetName());
        		UGameplayStatics::OpenLevel(GetWorld(), CurrentLevelName);
        		
        	},4.0f,false);
        		
        	
	}


}

void AJMSGameListener::GameClear()
{
	//캐릭터가 위젯띄우게 부르기

	if(APlatformPlayerController* PlatformPlayerController = Cast<APlatformPlayerController>(GetWorld()->GetFirstPlayerController()))
	{
		PlatformPlayerController->GameHasEnded(nullptr,true);
	}

	if(false)
	{
		// JMSGameListener에서 위젯 띄우기

		if(GameClearWidget != nullptr)
		{
			GameClearWidget->AddToViewport();	
		}
	}
	


}
