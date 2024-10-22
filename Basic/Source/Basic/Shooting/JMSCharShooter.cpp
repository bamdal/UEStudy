// Fill out your copyright notice in the Description page of Project Settings.


#include "JMSCharShooter.h"

#include "EnhancedInputComponent.h"
#include "JMSDebugMecros.h"
#include "JMSGun.h"
#include "JMS_ShooterGameModeBase.h"
#include "Components/CapsuleComponent.h"


void AJMSCharShooter::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;;
	// 총을 스폰 시켜 스켈레톤의 소켓에 부착
	Gun = GetWorld()->SpawnActor<AJMSGun>(JMSGunClass);
	if(Gun != nullptr)
	{
		Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform,TEXT("WeaponSocket"));
		Gun->SetOwner(this);
	}
	
}

void AJMSCharShooter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//  총 쏘기 위한 추가 입력
	if(UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Looking
		EnhancedInputComponent->BindAction(IA_Shoot,ETriggerEvent::Started,this,&AJMSCharShooter::Shoot);
	}
	
}

// 총알 발사 함수
void AJMSCharShooter::Shoot()
{
	if(Gun != nullptr)
	{
		// 총 발사 함수 호출
		Gun->PullTrigger();
	}
}

/**
 * 사망시 true 생존시 false
 * @return 해당 캐릭터의 HP가 0 이하면 true 아니면 false
 */
bool AJMSCharShooter::IsDead() const
{
	return Health <= 0;
}

float AJMSCharShooter::GetHealthPercent() const
{
	if(MaxHealth > 0)
	{
		return Health / MaxHealth;
	}
	return 0;
}

/**
 * 
 * @param DamageAmount 맞은 데미지
 * @param DamageEvent 데미지 이벤트정보
 * @param EventInstigator 데미지를 일으킨 컨트롤ㄹ러
 * @param DamageCauser 데미지를 일으킨 액터
 * @return 
 */
float AJMSCharShooter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
                                  AActor* DamageCauser)
{
	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageToApply = FMath::Min(Health,DamageToApply);	// 0미만으로 HP는 떨어지지 않는다.
	Health -= DamageToApply;
	HLOG(Warning,TEXT("Current Health : %f / %f"),Health,MaxHealth);

	if(IsDead())
	{

		AJMS_ShooterGameModeBase* GameMode = GetWorld()->GetAuthGameMode<AJMS_ShooterGameModeBase>();
		if(GameMode != nullptr)
		{
			GameMode->PawnKilled(this);
		}
		
		// 내부에 Controller->UnPossess(); 로 컨트롤러 분리를 한다
		this->DetachFromControllerPendingDestroy();

		// 캡슐 콜리전 무효화
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		
		// 내가 죽었는지, 적을 모두 섬멸했는지
	}
	
	return  DamageToApply;
}
