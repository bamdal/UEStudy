#pragma once

UENUM(BlueprintType)
enum class my_enum : uint8
{
	Nothing UMETA(DisplayName = "Nothing") ,
	Attacking UMETA(DisplayName = "Attacking") ,
	GeneralActionState UMETA(DisplayName = "GeneralActionState") ,
	Dead UMETA(DisplayName = "Dead") ,
	Disabled UMETA(DisplayName = "Disabled") ,
};
