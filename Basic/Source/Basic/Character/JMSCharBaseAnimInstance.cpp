

#include "JMSCharBaseAnimInstance.h"
#include "../JMSDebugMecros.h"
#include "JMSCharBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"


DEFINE_LOG_CATEGORY(Headcooler);

//	ENGINE_API void BlueprintThreadSafeUpdateAnimation(float DeltaTime);
// 나중엔 이걸로 애니메이션 구현
	
// AnimInstance가 초기화 될 때 레퍼런스를 저장
void UJMSCharBaseAnimInstance::NativeInitializeAnimation()
{
	// 캐릭터 Reference 저장
	JMSCharBase = Cast<AJMSCharBase>(TryGetPawnOwner());

	if(JMSCharBase != nullptr)
	{
		// Character Movement Reference 저장
		JMSCharMovementComponent = JMSCharBase->GetCharacterMovement();
	}
	// HCHECK(JMSCharBase);
	// HCHECK(JMSCharMovementComponent);
	
}

// Animation 업데이트 루프
void UJMSCharBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if(JMSCharMovementComponent)
	{
		JMSCharVelocity = JMSCharMovementComponent->Velocity;
		JMSCharSpeed = UKismetMathLibrary::VSizeXY(JMSCharVelocity);

		//GEngine->AddOnScreenDebugMessage(-1,1,FColor::Blue,FString::Printf(TEXT("Speed %f"),JMSCharSpeed));
		
		JMSShouldMove = false;
		bool Acceleration = !JMSCharMovementComponent->GetCurrentAcceleration().Equals(FVector::ZeroVector,0);
		if(JMSCharSpeed > 3.0f && Acceleration)
		{
			JMSShouldMove = true;
		}

		JMSCharIsFalling = JMSCharMovementComponent->IsFalling();
	}
}
