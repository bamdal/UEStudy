
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EventListener.generated.h"

class UStaticMeshComponent;	
class AEventTrigger;

UCLASS()
class BASIC_API AEventListener : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* TestMesh;
	
	UPROPERTY(EditAnywhere)
	AEventTrigger* EventTriggerObj;

	UFUNCTION()
	void OnEvent1Triggered();
	UFUNCTION()
	void OnEvent2Triggered();

private:
	// true면 회전, false면 정지
	bool bIsRotationState;

public:
	bool GetIsRotationState() { return bIsRotationState; }
	void SetIsRotationState(bool bState) { bIsRotationState = bState; }
	
	
public:	
	AEventListener();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
