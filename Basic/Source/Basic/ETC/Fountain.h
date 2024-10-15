// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"			// UE 기본 헤더
#include "GameFramework/Actor.h"	// GameFramework안에 있는 액터 헤더파일이ㅣ 부모클래스임을 알림
#include "Fountain.generated.h"		// UHT 기본 생성

class UStaticMeshComponent;	// 전방선언
class UPointLightComponent;
class UParticleSystemComponent;
class URotatingMovementComponent;

// UE 클래스 매크로 (리플랙션 시스템)
UCLASS()
class BASIC_API AFountain : public AActor
{
	GENERATED_BODY()	// 클래스 바디 매크로 (리플랙션 시스템)
	
// 씬 컴포넌트 계층구조(상속받은 BP에서 삭제 불가)
public:	
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Body;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Water;

	UPROPERTY(VisibleAnywhere)
	UPointLightComponent* Light;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* Splash;

	UPROPERTY(VisibleAnywhere)
	class URotatingMovementComponent* Movement;
	
public:	
	// Sets default values for this actor's properties
	AFountain();
	// Called every frame	
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	

};
