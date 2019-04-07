// Fill out your copyright notice in the Description page of Project Settings.


#include "MPController.h"
#include "Engine/World.h"
#include "AimCmpt.h"

void AMPController::BeginPlay()
{
	Super::BeginPlay();

}

void AMPController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTo();
}

void AMPController::AimTo()
{
	if (!GetPawn()) { return; }
	auto AimC = GetPawn()->FindComponentByClass<UAimCmpt>();
	if (!ensure(AimC)) { return; }

	FVector OutHitPosition;
	if (RayPosition(OutHitPosition))
	{
		AimC->AimDirection(OutHitPosition);
		UE_LOG(LogTemp, Warning, TEXT("aiming at %s"), *(OutHitPosition.ToString()))
	}
}

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

bool AMPController::GetDirection(FVector2D ReticlePosition, FVector& WorldDirection) const
{
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(ReticlePosition.X, ReticlePosition.Y, WorldLocation, WorldDirection);
}

bool AMPController::VectorPosition(FVector SightDirection, FVector& OutHitPosition) const
{
	FHitResult Hit;
	auto Start = PlayerCameraManager->GetCameraLocation();
	auto End = Start + SightDirection * Range;
	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECollisionChannel::ECC_Visibility))
	{
		OutHitPosition = Hit.Location;
		return true;
	}
	OutHitPosition = FVector(0.0);
	return false;
}