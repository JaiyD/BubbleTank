// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TheTank.generated.h"

UCLASS()
class BUBBLETANK_API ATheTank : public APawn
{
	GENERATED_BODY()

public:
	//WAS USED TO SETUP THE MOVEMNT AND THE AIM BUT GOT REFACTORED OUT 
	// Sets default values for this pawn's properties
	ATheTank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
