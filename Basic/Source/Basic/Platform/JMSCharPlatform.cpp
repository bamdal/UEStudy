// Fill out your copyright notice in the Description page of Project Settings.


#include "JMSCharPlatform.h"

#include "GameFramework/CharacterMovementComponent.h"

AJMSCharPlatform::AJMSCharPlatform()
{
}

void AJMSCharPlatform::BeginPlay()
{
	Super::BeginPlay();
}

void AJMSCharPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 서있는 상태에서 기믹에 밀렸을때 충돌로 인해 카메라가 깜빡이는 현상 꼼수로 제거
	FHitResult res;
	GetCharacterMovement()->K2_MoveUpdatedComponent(FVector(0.1, 0, 0.0), GetActorRotation(), res);
	GetCharacterMovement()->K2_MoveUpdatedComponent(FVector(-0.1, 0, 0.0), GetActorRotation(), res);
}
	