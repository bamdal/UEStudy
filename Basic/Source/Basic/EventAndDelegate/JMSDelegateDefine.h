#pragma once
#include "Delegates/DelegateCombinations.h"	// 델리게이트 매크로가 정의된 헤더

//=====================================================================
// 단일 오브젝트 바인딩용

// 기본 델리게이트
// 하나만 binding이 가능하고 마지막에 들어온 델리게이트만 적용된다

// 리턴없이 호출만 가능
DECLARE_DELEGATE(FDelegateSignature)	

// 기본 델리게이트에 인자들을 전달하는 방법 (9개까지 가능)
// 인자를 1개 받는다
DECLARE_DELEGATE_OneParam(FDelegateSignatureParam1, FLinearColor)
// 인자를 2개 받는다
DECLARE_DELEGATE_TwoParams(FDelegateSignatureParam2, FLinearColor, int32)


// =====================================================================
// 멀티 오브젝트 바인딩용

DECLARE_MULTICAST_DELEGATE(FMulticastDelegateSignature);

// 멀티 오브젝트도 인자 여려개를 받을수 있다.
DECLARE_MULTICAST_DELEGATE_OneParam(FMulticastDelegateSignatureParam1, FLinearColor)
DECLARE_MULTICAST_DELEGATE_TwoParams(FMulticastDelegateSignatureParam2, FLinearColor, int32)
