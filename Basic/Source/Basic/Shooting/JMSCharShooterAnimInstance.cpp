// Fill out your copyright notice in the Description page of Project Settings.


#include "JMSCharShooterAnimInstance.h"

#include "JMSCharBase.h"
#include "JMSCharShooter.h"
#include "Kismet/KismetMathLibrary.h"

void UJMSCharShooterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if(JMSCharBase != nullptr)
	{
		// 내 캐릭터의 움직임은 내 방향키 입력에 맞춰 변화할 필요가 있으므로 로컬 좌표계를 통해 연산할 필요가 있다.
		// 월드에서 내가 어느 방향을 보는지는 필요하지 않고 내 기준으로 어느방향으로 이동하는지가 필수기에 로컬로 전환을 해준다.
		FVector ITVector = UKismetMathLibrary::InverseTransformDirection(JMSCharBase->GetActorTransform(),
																	JMSCharBase->GetVelocity());
		FRotator Rot = UKismetMathLibrary::Conv_VectorToRotator(ITVector);
		// Z축을 기준으로 회전값 판단
		Angle= Rot.Yaw;

		// 에임 피치
		// 내 캐릭터와 인풋간에 회전 간격 차이
		Rot = UKismetMathLibrary::NormalizedDeltaRotator(JMSCharBase->GetControlRotation(),JMSCharBase->GetActorRotation());
		AimPitch = Rot.Pitch;

		// 캐릭터에 Health를 토대로 IsDead 체크
		AJMSCharShooter* JMSCharShooter = Cast<AJMSCharShooter>(JMSCharBase);
		if(JMSCharShooter != nullptr)
		{
			IsDead = JMSCharShooter->IsDead();
		}
	}
}
