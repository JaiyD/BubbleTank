// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveCmpt.h"
#include "Track.h"

void UMoveCmpt::Init(UTrack* LeftTrackSet, UTrack* RightTrackSet)
{
	LeftTrack = LeftTrackSet;
	RightTrack = RightTrackSet;
}

void UMoveCmpt::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankFwrd = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIFwrd = MoveVelocity.GetSafeNormal();
	auto Fwrd = FVector::DotProduct(TankFwrd, AIFwrd);
	auto Rotation = FVector::CrossProduct(TankFwrd, AIFwrd);

	Moving(Fwrd);
	Turning(Rotation.Z);
}

void UMoveCmpt::Moving(float Speed)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetSpeed(Speed);
	RightTrack->SetSpeed(Speed);
}

void UMoveCmpt::Turning(float Speed)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetSpeed(Speed);
	RightTrack->SetSpeed(-Speed);
}