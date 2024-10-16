
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "EventAndDelegate/JMSDelegateDefine.h"
#include "JMSGameInstance.generated.h"

UCLASS()
class BASIC_API UJMSGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	FDelegateSignature DefaultDelegateSignature;	
	
};
