// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Turret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BUBBLETANK_API UTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//responsible for rotating the turret
	void Rotate(float RotationSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxRotationDegrees = 25; // rotation per second
};
