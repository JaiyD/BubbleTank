// Fill out your copyright notice in the Description page of Project Settings.


#include "MPController.h"
#include "Engine/World.h"
#include "AimCmpt.h"

void AMPController::BeginPlay()
{
	Super::BeginPlay();
	//getting the aim component
	auto AimC = GetPawn()->FindComponentByClass<UAimCmpt>();
	if (!ensure(AimC)) { return; }

	FoundAimCmpt(AimC);
}

void AMPController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTo();
}
//Used to help aim the tankk
void AMPController::AimTo()
{
	if (!GetPawn()) { return; }
	auto AimC = GetPawn()->FindComponentByClass<UAimCmpt>();
	if (!ensure(AimC)) { return; }

	FVector OutHitPosition;
	if (RayPosition(OutHitPosition))
	{
		AimC->AimDirection(OutHitPosition);
	}
}
//Getting the position to help the aiming
bool AMPController::RayPosition(FVector& OutHitPosition) const
{
	int32 ScreenSizeX, ScreenSizeY;
	GetViewportSize(ScreenSizeX, ScreenSizeY);
	auto ReticlePosition = FVector2D(ScreenSizeX * ReticleX, ScreenSizeY * ReticleY);

	FVector SightDirection;
	if (GetDirection(ReticlePosition, SightDirection))
	{
		VectorPosition(SightDirection, OutHitPosition);
	}
	return true;
}
//The direction on the screen
bool AMPController::GetDirection(FVector2D ReticlePosition, FVector& WorldDirection) const
{
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(ReticlePosition.X, ReticlePosition.Y, WorldLocation, WorldDirection);
}
//Vector of the aim
bool AMPController::VectorPosition(FVector SightDirection, FVector& OutHitPosition) const
{
	FHitResult Hit;
	auto Start = PlayerCameraManager->GetCameraLocation();
	auto End = Start + SightDirection * Range;
	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECollisionChannel::ECC_Visibility))
	{
		OutHitPosition = Hit.Location;//if the aim intercepts an obstacle
		return true;
	}
	OutHitPosition = FVector(0.0);//if the aim intercepts nothing, set to 0
	return false;
}