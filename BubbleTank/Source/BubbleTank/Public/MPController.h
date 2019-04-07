// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MPController.generated.h"

/**
 * 
 */
UCLASS()
class BUBBLETANK_API AMPController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	void AimTo();
	bool RayPosition(FVector& OutHitLocation) const;
	bool GetDirection(FVector2D ReticlePosition, FVector& WorldDirection) const;
	bool VectorPosition(FVector SightDirection, FVector& OutHitPosition) const;

	UPROPERTY(EditAnywhere)
	float ReticleX = 0.5;
	UPROPERTY(EditAnywhere)
	float ReticleY = 0.3333;
	UPROPERTY(EditAnywhere)
	float Range = 1000000;
};
