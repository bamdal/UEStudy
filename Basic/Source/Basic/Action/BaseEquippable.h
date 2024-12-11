// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseEquippable.generated.h"

class UJMS_CombatComponent;
class UJMS_CollisionComponent;
/**
 * 장착 가능한 아이템들이 상속받는 클래스
 */
UCLASS()
class BASIC_API ABaseEquippable : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY()
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* ItemSkeletalMesh;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ItemStaticMesh;

	// ItemSkeletalMesh, ItemStaticMesh 둘중하나를 리턴할 수 있게 둘다 상속받는 UPrimitiveComponent를 리턴하게 시킴
	/**
	 * 스테틱 메시안에 등록 되었다면 ItemSkeletalMesh, ItemStaticMesh 둘중하나를 리턴
	 * @return ItemSkeletalMesh, ItemStaticMesh 둘중하나 리턴
	 */
	UFUNCTION(BlueprintPure, Category="ItemMesh")
	UPrimitiveComponent* GetItemMesh();

	/**
	 * 소켓의 이름을 넣으면 Attach해주는 함수
	 * @param SocketName 붙힐 소켓의 이름
	 */
	UFUNCTION(BlueprintCallable, Category="ItemMesh")
	void AttachActor(FName SocketName);

	UPROPERTY()
	UJMS_CombatComponent* CombatComponent;

	UPROPERTY(VisibleDefaultsOnly)
	bool IsEquipped = false;

	UPROPERTY()
	UJMS_CollisionComponent* CollisionComponent;

public:
	/**
	 * 아이템 장착 함수 (파생 클래스가 BP일 경우 BlueprintNativeEvent 사용)
	 * @param SocketName 
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnEquipped();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="SocketName")
	FName AttachSocketName;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="SocketName")
	FName HandSocketName;
	
	void SetIsEquipped(bool Equip){IsEquipped = Equip;}
	
	bool GetIsEquipped(){return IsEquipped;}

	/**
 * 아이템 해제 함수
 */
	UFUNCTION(BlueprintCallable)
	void UnEquipped();



protected:
	void OnHit(const FHitResult& Hit);
	
public:
	// Sets default values for this actor's properties
	ABaseEquippable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
