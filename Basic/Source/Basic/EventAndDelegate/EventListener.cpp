

#include "EventListener.h"

#include "EventTrigger.h"

AEventListener::AEventListener()
{
	PrimaryActorTick.bCanEverTick = true;

	EventTriggerObj = nullptr;
	bIsRotationState = false;	// 정지
	
	TestMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TestMesh"));
	SetRootComponent(TestMesh);
}

void AEventListener::BeginPlay()
{
	Super::BeginPlay();
	
	// 트리거 이벤트 바인딩 (유니티에서 Action으로 만든다음 연결해두는것이랑 같음)
	if(EventTriggerObj != nullptr)
	{
		EventTriggerObj->OnEvent1.AddUObject(this,&ThisClass::OnEvent1Triggered);
		EventTriggerObj->OnEvent2.AddUObject(this,&AEventListener::OnEvent2Triggered);
	}
}

void AEventListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(GetIsRotationState() == true)
	{
		// 초당 100도 씩 Yaw회전
		static const int32 RotateSpeed = 100;
		AddActorLocalRotation(FRotator(0,RotateSpeed * DeltaTime,0));
	}
}

void AEventListener::OnEvent1Triggered()
{
	SetIsRotationState(true);
}

void AEventListener::OnEvent2Triggered()
{
	SetIsRotationState(false);
}