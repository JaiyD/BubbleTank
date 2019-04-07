// Fill out your copyright notice in the Description page of Project Settings.


#include "PController.h"
#include "Engine/World.h"
#include "AimCmpt.h"


void APController::BeginPlay()
{
	Super::BeginPlay();
	auto Aim = GetPawn()->FindComponentByClass<UAimCmpt>();
	//AimFound(Aim);
}

void APController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimDirection();
}

void APController::AimDirection()
{
	if (!GetPawn()) { return; }//use get pawn whenver you need get controlled tank

	FVector OutHitPosition;
	if (RayPosition(OutHitPosition))
	{
		UE_LOG(LogTemp, Warning, TEXT("aiming at %s"), *OutHitPosition.ToString())
	}
}

bool APController::RayPosition(FVector& OutHitPosition) const
{
	int32 ScreenX, ScreenY;
	GetViewportSize(ScreenX, ScreenY);
	FVector2D ReticlePosition = FVector2D(ScreenX * ReticleX, ScreenY * ReticleY);

	FVector Direction;
	if (GetDirection(ReticlePosition, Direction))
	{
		VectorHitPosition(Direction, OutHitPosition);
	}

	return true;
}

bool APController::GetDirection(FVector2D ReticlePosition, FVector& WorldDirection) const
{
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(ReticlePosition.X, ReticlePosition.Y, WorldLocation, WorldDirection);
}

bool APController::VectorHitPosition(FVector Direction, FVector& OutHitPosition) const
{
	FHitResult Hit;
	auto Start = PlayerCameraManager->GetCameraLocation();
	auto End = Start + Direction * Range;

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECollisionChannel::ECC_Visibility))
	{
		OutHitPosition = Hit.Location;
		return true;
	}
	OutHitPosition = FVector(0.0);
	return false;
}