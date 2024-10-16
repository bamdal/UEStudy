
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EventTrigger.generated.h"

class UBoxComponent;
// 이벤트 선언 : 이벤트를 소유한 클래스와, 이벤트 클래스를 지정 (이벤트 이름으로 사용)
// 이벤트를 소유한다는건 유일하게 Broadcast() 할 수 있는 클래스란 의미(friend로 설정)
DECLARE_EVENT(AEventTrigger,JMSEvent1)
DECLARE_EVENT(AEventTrigger,JMSEvent2)

UCLASS()
class BASIC_API AEventTrigger : public AActor
{
	GENERATED_BODY()
	

public:
	
	UBoxComponent* TriggerZone;	// 트리거 영역

	JMSEvent1 OnEvent1;			// 이벤트 1 (트리거 영역에 들어갈 때)
	JMSEvent2 OnEvent2;			// 이벤트 2 (트리거 영역 나갈 때)

	// UFUNCTION() 지정 안하면 발동 안함
	UFUNCTION()
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	UFUNCTION()
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
public:	
	AEventTrigger();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
