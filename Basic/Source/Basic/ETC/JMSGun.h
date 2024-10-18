// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JMSGun.generated.h"

UCLASS()
class BASIC_API AJMSGun : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	// 총기 매쉬
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;

	// 나이아가라 이펙트 있으면 그걸로 해도 된다.

	// 총구 이펙트
	UPROPERTY(EditAnywhere)
	UParticleSystem* MuzzleFlash;

	// 타점 이펙트
	UPROPERTY(EditAnywhere)
	UParticleSystem* ImpactEffect;

	// 총 발사 사운드
	UPROPERTY(EditAnywhere)
	USoundBase* MuzzleSound;

	// 타점 사운드
	UPROPERTY(EditAnywhere)
	USoundBase* ImpactSound;
	
public:	
	// Sets default values for this actor's properties
	AJMSGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
