// Fill out your copyright notice in the Description page of Project Settings.


#include "JMSCharShooter.h"

#include "Basic/ETC/JMSGun.h"

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
}
