// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseEquippable.generated.h"

/**
 * 장착 가능한 아이템들이 상속받는 클래스
 */
UCLASS()
class BASIC_API ABaseEquippable : public AActor
{
	GENERATED_BODY()

private:
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

	/**
	 * 아이템 장착 함수
	 * @param SocketName 
	 */
	UFUNCTION(BlueprintCallable)
	void OnEquipped();

	/**
	 * 아이템 해제 함수
	 */
	UFUNCTION(BlueprintCallable)
	void UnEquipped();


	UPROPERTY(VisibleDefaultsOnly)
	bool IsEquipped = false;

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FName AttachSocketName;
	
	void SetIsEquipped(bool Equip){IsEquipped = Equip;}
	bool GetIsEquipped(){return IsEquipped;}

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
