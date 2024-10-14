#pragma once

#include "DrawDebugHelpers.h"

#define JMSDRAW_SPHERE(Location) \
if(GetWorld()) \
	DrawDebugSphere(GetWorld(), Location, 50.0f, 12, FColor::Red, true);

#define JMSDRAW_LINE(StartLocation, EndLocation)\
if(GetWorld()) \
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Blue, true, 100);

#define JMSDRAW_POINT(Location) \
if(GetWorld()) \
	DrawDebugPoint(GetWorld(), Location, 15, FColor::Red,true);

#define JMSDRAW_VECTOR(StartLocation, EndLocation) \
if (GetWorld()) \
{ \
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Blue, true, 100); \
	DrawDebugPoint(GetWorld(), EndLocation, 15, FColor::Red, true); \
}