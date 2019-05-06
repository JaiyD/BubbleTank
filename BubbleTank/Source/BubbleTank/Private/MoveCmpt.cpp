// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveCmpt.h"
#include "Track.h"

//Used to link the tracks in the tank blueprint event graph
void UMoveCmpt::Init(UTrack* LeftTrackSet, UTrack* RightTrackSet)
{
	LeftTrack = LeftTrackSet;
	RightTrack = RightTrackSet;
}

//AI pathfinding
void UMoveCmpt::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankFwrd = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIFwrd = MoveVelocity.GetSafeNormal();
	auto Fwrd = FVector::DotProduct(TankFwrd, AIFwrd);//etting the forward or backward speed
	auto Rotation = FVector::CrossProduct(TankFwrd, AIFwrd);//getting the rotation for the tank

	Moving(Fwrd);
	Turning(Rotation.Z);
}

//Move the tank forward or backward
void UMoveCmpt::Moving(float Speed)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetSpeed(Speed);
	RightTrack->SetSpeed(Speed);
}
//Turning the tank right or left
void UMoveCmpt::Turning(float Speed)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetSpeed(Speed);
	RightTrack->SetSpeed(-Speed);
}