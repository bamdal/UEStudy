// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEquippable.h"

#include "MovieSceneTracksComponentTypes.h"
#include "Component/JMS_CollisionComponent.h"
#include "Component/JMS_CombatComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"



// Sets default values
ABaseEquippable::ABaseEquippable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRoot);

	ItemSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ItemSkeletalMesh"));
	ItemSkeletalMesh->SetupAttachment(DefaultSceneRoot);

	ItemStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemStaticMesh"));
	ItemStaticMesh->SetupAttachment(DefaultSceneRoot);

	CollisionComponent = CreateDefaultSubobject<UJMS_CollisionComponent>(TEXT("CollisionComponent"));
	AddInstanceComponent(CollisionComponent);

	AttachSocketName = TEXT("SwordHipAttachSocket");
	HandSocketName = TEXT("WeaponSocket");
}

// Called when the game starts or when spawned
void ABaseEquippable::BeginPlay()
{
	Super::BeginPlay();

	if(CollisionComponent)
	{
		CollisionComponent->OnHit.BindUObject(this,&ABaseEquippable::OnHit);
	}
}

// Called every frame
void ABaseEquippable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseEquippable::OnHit(const FHitResult& Hit)
{
	if(Hit.GetActor())
	{
		
	}
}


UPrimitiveComponent* ABaseEquippable::GetItemMesh()
{
	if (ItemStaticMesh != nullptr)
	{
		UStaticMesh* StaticMesh = ItemStaticMesh->GetStaticMesh();
		// 스테틱 메시안에 등록 되었다면
		if (StaticMesh != nullptr)
		{
			return ItemStaticMesh;
		}
	}

	if (ItemSkeletalMesh != nullptr)
	{
		return ItemSkeletalMesh;
	}
	return nullptr;
}

void ABaseEquippable::AttachActor(FName SocketName)
{
	ACharacter* Character = Cast<ACharacter>(GetOwner());
	// 해당 무기를 소지한 Owner가 있다면
	if (Character != nullptr)
	{
		// FAttachmentTransformRules : Attach할때 조건 입력
		FAttachmentTransformRules Rules(EAttachmentRule::SnapToTarget,true);
		AttachToComponent(Character->GetMesh(),Rules, SocketName);
	}
}

void ABaseEquippable::UnEquipped()
{
	SetIsEquipped(false);
}

void ABaseEquippable::OnEquipped_Implementation()
{
	SetIsEquipped(true);
	AttachActor(AttachSocketName);

	CombatComponent = Cast<UJMS_CombatComponent>(GetOwner()->GetComponentByClass(UJMS_CombatComponent::StaticClass()));

	CombatComponent->SetMainWeapon(this);
	
	FName Bone;
	Bone = AttachSocketName;
	if(CombatComponent->IsCombatEnable())
	{
		Bone = HandSocketName;
	}

	AttachActor(Bone);

	CollisionComponent->SetCollisionMesh(GetItemMesh());
	CollisionComponent->AddActorToIgnore(GetOwner());
	
}
