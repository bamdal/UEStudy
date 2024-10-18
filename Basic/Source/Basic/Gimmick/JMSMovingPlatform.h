#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JMSMovingPlatform.generated.h"

class UStaticMeshComponent;

UCLASS()
class BASIC_API AJMSMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMesh;

private:
	UPROPERTY(EditAnywhere, Category="Moving")
	FVector PlatformVelocity = FVector(100, 0, 0);
	UPROPERTY(EditAnywhere, Category="Moving")
	float MoveDistance = 100;
	UPROPERTY(EditAnywhere, Category="Rotation")
	FRotator RotationVelocity;

	FVector StartLocation;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn() const;
	float GetDistancMoved() const;

public:
	AJMSMovingPlatform();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	UFUNCTION()
	virtual void PlayerOnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
						 UPrimitiveComponent* OtherComp, FVector NormalImpulse,
						 const FHitResult& Hit);

};
