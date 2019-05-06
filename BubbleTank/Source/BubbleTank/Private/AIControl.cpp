// Fill out your copyright notice in the Description page of Project Settings.


#include "AIControl.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "AimCmpt.h"

void AAIControl::BeginPlay()
{
	Super::BeginPlay();

}

void AAIControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Tracking the player
	auto Player = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto Possessed = GetPawn();

	if (!ensure(Player && Possessed)) { return; }

	//move the AI towards the player
	MoveToActor(Player, radius);

	//Find the aim component in order to aim and fire at the player
	auto AimC = Possessed->FindComponentByClass<UAimCmpt>();
	AimC->AimDirection(Player->GetActorLocation());
	AimC->Fire();

}