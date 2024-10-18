
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

	FDelegateSignatureParam1 DefaultDelegateSignatureParam1;
	FDelegateSignatureParam2 DefaultDelegateSignatureParam2;
	FMulticastDelegateSignature MulticastDelegateSignature;
	
	FMulticastDelegateSignatureParam1 MulticastDelegateSignatureParam1;
	FMulticastDelegateSignatureParam2 MulticastDelegateSignatureParam2;

	FGameClearDelegate PlayerClearSingnatureDelegate;
	FGameOverDelegate PlayerDieSingnatureDelegate;

		
};
