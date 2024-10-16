
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateParamTrigger.generated.h"

class UCapsuleComponent;

UCLASS()
class BASIC_API ADelegateParamTrigger : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY()
	UCapsuleComponent* TriggerZone;

	UPROPERTY(EditAnywhere)
	FLinearColor LightColor;

	UPROPERTY(EditAnywhere)
	int32 RotateSpeed;

	UFUNCTION()
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	UFUNCTION()
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
	
public:	
	ADelegateParamTrigger();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
