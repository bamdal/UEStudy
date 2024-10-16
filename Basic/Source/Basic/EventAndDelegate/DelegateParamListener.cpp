// Fill out your copyright notice in the Description page of Project Settings.


#include "DelegateParamListener.h"

#include "Basic/JMSGameInstance.h"
#include "Components/SpotLightComponent.h"

// Sets default values
ADelegateParamListener::ADelegateParamListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpotLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotLight"));
	SetRootComponent(SpotLight);
	SpotLight->SetIntensity(100000.0f);
	RotateSpeed = 0.0f;
}

// Called when the game starts or when spawned
void ADelegateParamListener::BeginPlay()
{
	Super::BeginPlay();

	UJMSGameInstance* JMSGI = Cast<UJMSGameInstance>(GetWorld()->GetGameInstance());
	if(JMSGI != nullptr)
	{
		JMSGI->DefaultDelegateSignatureParam1.BindUObject(this,&ThisClass::SetLightColor);
		JMSGI->DefaultDelegateSignatureParam2.BindUObject(this,&ThisClass::SetLightColorAndRotate);
			
	}
	
}

// Called every frame
void ADelegateParamListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(GetRotateSpeed() > 0.0f	)
	{
		// 초당 설정된 RotateSpeed만큼 Yaw회전
		AddActorLocalRotation(FRotator(-GetRotateSpeed() * DeltaTime,GetRotateSpeed() * DeltaTime,-GetRotateSpeed() * DeltaTime*0.5f));
	}
}


void ADelegateParamListener::SetLightColor(FLinearColor LightColor)
{
	SpotLight->SetLightColor(LightColor);
	SetRotateSpeed(0);
}

void ADelegateParamListener::SetLightColorAndRotate(FLinearColor LightColor, int32 Speed)
{
	SpotLight->SetLightColor(FColor::Red);
	SetRotateSpeed(Speed);
}
