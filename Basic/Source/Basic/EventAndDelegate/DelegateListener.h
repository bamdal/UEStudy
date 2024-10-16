
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateListener.generated.h"

class UPointLightComponent;

UCLASS()
class BASIC_API ADelegateListener : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	UPointLightComponent* PointLight;
	
	UFUNCTION()
	void EnableLight();
	
	
public:	
	ADelegateListener();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	virtual void Tick(float DeltaTime) override;
	
};
