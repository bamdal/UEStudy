// Fill out your copyright notice in the Description page of Project Settings.


#include "JMSCharShooter.h"

#include "EnhancedInputComponent.h"
#include "JMSGun.h"



void AJMSCharShooter::BeginPlay()
{
	Super::BeginPlay();

	// 총을 스폰 시켜 스켈레톤의 소켓에 부착
	Gun = GetWorld()->SpawnActor<AJMSGun>(JMSGunClass);
	if(Gun != nullptr)
	{
		Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform,TEXT("WeaponSocket"));
		Gun->SetOwner(this);
	}
	
}

void AJMSCharShooter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//  총 쏘기 위한 추가 입력
	if(UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Looking
		EnhancedInputComponent->BindAction(IA_Shoot,ETriggerEvent::Started,this,&AJMSCharShooter::Shoot);
	}
	
}

void AJMSCharShooter::Shoot()
{
	if(Gun != nullptr)
	{
		// 총 발사 함수 호출
		Gun->PullTrigger();
	}
}