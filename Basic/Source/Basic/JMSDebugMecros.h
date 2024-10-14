#pragma once

#include "DrawDebugHelpers.h"

#define JMSDRAW_SPHERE(Location) \
if(GetWorld()) \
	DrawDebugSphere(GetWorld(), Location, 25.0f, 12, FColor::Red, true);

#define JMSDRAW_SPHERE_COLOR(Location,Color) \
if(GetWorld()) \
	DrawDebugSphere(GetWorld(), Location, 50.0f, 12, Color, true);

// Tick에서 사용
#define JMSDRAW_SPHERE_SingleFrame(Location) \
if(GetWorld()) \
	DrawDebugSphere(GetWorld(), Location, 25.0f, 12, FColor::Red, false,-1.0f);


#define JMSDRAW_LINE(StartLocation, EndLocation)\
if(GetWorld()) \
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Blue, true, -1.0f,0,1.0f);

// Tick에서 사용
#define JMSDRAW_LINE_SingleFrame(StartLocation, EndLocation)\
if(GetWorld()) \
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Blue, false, -1.0f,0,1.0f);

#define JMSDRAW_POINT(Location) \
if(GetWorld()) \
	DrawDebugPoint(GetWorld(), Location, 15, FColor::Red,true);

// Tick에서 사용
#define JMSDRAW_POINT_SingleFrame(Location) \
if(GetWorld()) \
	DrawDebugPoint(GetWorld(), Location, 15, FColor::Red,false,-1.0f);


#define JMSDRAW_VECTOR(StartLocation, EndLocation) \
if (GetWorld()) \
{ \
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Blue, true, 100); \
	DrawDebugPoint(GetWorld(), EndLocation, 15, FColor::Red, true); \
}

// Tick에서 사용
#define JMSDRAW_VECTOR_SingleFrame(StartLocation, EndLocation) \
if (GetWorld()) \
{ \
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Blue, false, -1.0f,0,1.0f); \
	DrawDebugPoint(GetWorld(), EndLocation, 15, FColor::Red,false,-1.0f); \
}