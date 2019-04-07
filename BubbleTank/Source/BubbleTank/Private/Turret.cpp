// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"
#include "Engine/World.h"

void UTurret::Rotate(float RotationSpeed)
{
	RotationSpeed = FMath::Clamp<float>(RotationSpeed, -1.0, 1.0);
	auto RotationShift = RotationSpeed * MaxRotation * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationShift;
	SetRelativeRotation(FRotator(0, Rotation, 0));
}

