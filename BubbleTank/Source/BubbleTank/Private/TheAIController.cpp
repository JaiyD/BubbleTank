// Fill out your copyright notice in the Description page of Project Settings.


#include "TheAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "AimCmpt.h"

void ATheAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATheAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto Player = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto Possessed = GetPawn(); // Get the tank possessing

	if (!ensure(Player && Possessed)) { return; }

	//Move towards player
	//MoveToActor(Player, radius)

	//aim towards player
	auto Aim = Possessed->FindComponentByClass<UAimCmpt>();
	Aim->AimAt(Player->GetActorLocation());

}
