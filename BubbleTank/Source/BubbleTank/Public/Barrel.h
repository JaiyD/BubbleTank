// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Barrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BUBBLETANK_API UBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float ElevationSpeed);

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 10;// elevation degrees per second
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 40;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = 0;

};
