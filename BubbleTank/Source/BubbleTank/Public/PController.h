// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PController.generated.h"

class UAimCmpt
/**
 * 
 */
UCLASS()
class BUBBLETANK_API APController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	//UFUNCTION(BlueprintImplementableEvent, Category = Setup)
	//void AimFound(UAimCmpt* AimCmptRef);

private:
	void AimDirection();
	bool RayPosition(FVector& OutHitPosition) const;
	bool GetDirection(FVector2D ReticlePosition, FVector& Direction) const;
	bool VectorHitPosition(FVector Direction, FVector& OutHitPosition) const;

	UPROPERTY(EditAnywhere)
	float ReticleX = 0.5;
	UPROPERTY(EditAnywhere)
	float ReticleY = 0.333;
	UPROPERTY(EditAnywhere)
	float Range = 1000000;
};
