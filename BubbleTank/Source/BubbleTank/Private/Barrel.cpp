// Fill out your copyright notice in the Description page of Project Settings.


#include "Barrel.h"
#include "Engine/World.h"

void UBarrel::Elevate(float ElevationSpeed)
{
	ElevationSpeed = FMath::Clamp<float>(ElevationSpeed, -1.0, 1.0);
	auto ElevationShift = ElevationSpeed * MaxElevationDegrees * GetWorld()->DeltaTimeSeconds;
	auto NewElevation = RelativeRotation.Pitch + ElevationShift;
	auto Elevation = FMath::Clamp<float>(NewElevation, MinElevation, MaxElevation);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}