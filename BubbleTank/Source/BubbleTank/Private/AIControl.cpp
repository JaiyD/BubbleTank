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

	auto Player = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto Possessed = GetPawn();

	if (!ensure(Player && Possessed)) { return; }

	//move
	MoveToActor(Player, radius);

	auto AimC = Possessed->FindComponentByClass<UAimCmpt>();
	AimC->AimDirection(Player->GetActorLocation());
	AimC->Fire();

}