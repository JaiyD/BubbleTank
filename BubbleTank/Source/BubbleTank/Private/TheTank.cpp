// Fill out your copyright notice in the Description page of Project Settings.


#include "TheTank.h"

//was used to setup the movement and the aiming but got refactored out
// Sets default values
ATheTank::ATheTank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATheTank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATheTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATheTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

