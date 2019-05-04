// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIControl.generated.h"

/**
 * 
 */
UCLASS()
class BUBBLETANK_API AAIControl : public AAIController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	float radius = 3000;//radius for the ai tank around the player tank
	
};
