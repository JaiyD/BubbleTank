// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TheAIController.generated.h"

/**
 * 
 */
UCLASS()
class BUBBLETANK_API ATheAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:

	float radius = 4000;
};
