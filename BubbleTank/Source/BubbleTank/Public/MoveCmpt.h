// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "MoveCmpt.generated.h"

class UTrack;

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BUBBLETANK_API UMoveCmpt : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	//responsible for the movement of the tank
	UFUNCTION(BlueprintCallable, Category = Input)
	void Moving(float Speed);
	UFUNCTION(BlueprintCallable, Category = Input)
	void Turning(float Speed);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Init(UTrack* LeftTrackSet, UTrack* RightTrackSet);

	//pathfinding method for AI
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

private:
	UTrack* LeftTrack = nullptr;
	UTrack* RightTrack = nullptr;
};
