// Fill out your copyright notice in the Description page of Project Settings.


#include "Barrel.h"
#include "Engine/World.h"

//Elevating the barrel
void UBarrel::Elevate(float ElevationSpeed)
{
	ElevationSpeed = FMath::Clamp<float>(ElevationSpeed, -1.0, 1.0);//clamping the speed at -1 to 1
	auto EleShift = ElevationSpeed * MaxElevationDegrees * GetWorld()->DeltaTimeSeconds;
	auto NewElevation = RelativeRotation.Pitch + EleShift;//calculating the elevation
	auto Elevation = FMath::Clamp<float>(NewElevation, MinElevation, MaxElevation);//clamping the elevation
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}