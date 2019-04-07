// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"

void UTurret::Rotate(float RotationSpeed)
{
	RotationSpeed = FMath::Clamp<float>(RotationSpeed, -1.0, 1.0);
	auto RotShift = RotationSpeed * MaxRotationDegrees * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotShift;
	SetRelativeRotation(FRotator(0, Rotation, 0));
}