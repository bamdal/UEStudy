
#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "JMSCharBaseAnimInstance.generated.h"

class AJMSCharBase;
class UCharacterMovementComponent;

UCLASS()
class BASIC_API UJMSCharBaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	AJMSCharBase* JMSCharBase;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	UCharacterMovementComponent* JMSCharMovementComponent;
	
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	FVector JMSCharVelocity;
	
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	float JMSCharSpeed;
	
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	bool JMSShouldMove;
	
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	bool JMSCharIsFalling;
	
protected:
	// Event Blueprint Initialize Animation 이벤트 노드 역할
	virtual void NativeInitializeAnimation() override;

	// Event Blueprint Initialize Update Animation 이벤트 노드 역할
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
};
