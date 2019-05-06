// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"

//Rotating the turret according to the aim
void UTurret::Rotate(float RotationSpeed)
{
	RotationSpeed = FMath::Clamp<float>(RotationSpeed, -1.0, 1.0);//clamping the speed from -1 to 1
	auto RotShift = RotationSpeed * MaxRotationDegrees * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotShift;//get the rotation needed
	SetRelativeRotation(FRotator(0, Rotation, 0));
}