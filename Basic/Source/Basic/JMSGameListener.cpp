// Fill out your copyright notice in the Description page of Project Settings.


#include "JMSGameListener.h"
#include "Components/PrimitiveComponent.h"
#include "JMSGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"


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
	SpringArm = UserPawn->FindComponentByClass<USpringArmComponent>();
		
	UJMSGameInstance* JMSGI = Cast<UJMSGameInstance>(GetWorld()->GetGameInstance());
	if (JMSGI != nullptr)
	{
		JMSGI->PlayerDieSingnatureDelegate.BindUObject(this,&AJMSGameListener::PlayerDie);
		JMSGI->PlayerClearSingnatureDelegate.BindUObject(this,&AJMSGameListener::GameClear);
	}
	
}

// Called every frame
void AJMSGameListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CameraLocation = SpringArm->GetComponentLocation();
	FVector TargetLocation = UserPawn->GetActorLocation();


	SpringArm->SetWorldRotation(UKismetMathLibrary::FindLookAtRotation(CameraLocation,TargetLocation));
}

// 플레이어 사망시 불림
void AJMSGameListener::PlayerDie()
{

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

void AJMSGameListener::GameClear()
{
	if(GameClearWidget != nullptr)
	{
		GameClearWidget->AddToViewport();	
	}
}
