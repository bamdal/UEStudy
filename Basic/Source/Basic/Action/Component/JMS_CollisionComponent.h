// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "JMS_CollisionComponent.generated.h"

DECLARE_DELEGATE_OneParam(FOnHit,const FHitResult&)
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BASIC_API UJMS_CollisionComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	bool IsCollisionEnabled = false;

	UPROPERTY()
	TArray<AActor*> AlreadyActors;

	//콜리전 메쉬
	UPROPERTY()
	TObjectPtr<UPrimitiveComponent> CollisionMeshComponent;

	UPROPERTY(EditAnywhere)
	FName StartSocketName;

	UPROPERTY(EditAnywhere)
	FName EndSocketName;

	const TArray<TEnumAsByte<EObjectTypeQuery>> CollisionObjectType;

	float TraceRadius;



	TArray<FHitResult> LastHits;

	UPROPERTY()
	TArray<AActor*> ActorsToIgnore;
public:
	// 충돌 활성
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void EnableCollision();

	// 충돌 비활성
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void DisableCollision();

	// 충돌 되었던 목록 정리
	void ClearHitActors();

	//콜리전 메쉬 설정 이벤트
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void SetCollisionMesh(UPrimitiveComponent* Component);

	// 콜리전 활성화 명령이 오면 Trace시작되게 설정
	void CollisionTrace();

	UFUNCTION(BlueprintCallable)
	void AddActorToIgnore(AActor* Actor);

	// hit 델리게이트
	FOnHit OnHit;
public:	
	// Sets default values for this component's properties
	UJMS_CollisionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
