// Fill out your copyright notice in the Description page of Project Settings.


#include "AimCmpt.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Barrel.h"
#include "Turret.h"
#include "Projectile.h"

// Sets default values for this component's properties
UAimCmpt::UAimCmpt()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAimCmpt::BeginPlay()
{
	Super::BeginPlay();
	LastFire = GetWorld()->GetTimeSeconds();
	// ...
	
}


// Called every frame
void UAimCmpt::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAimCmpt::init(UBarrel* SetBarrel, UTurret* SetTurret)
{
	Barrel = SetBarrel;
	Turret = SetTurret;
}

void UAimCmpt::AimDirection(FVector OutHitPosition)
{
	if (!ensure(Barrel)) { return; }
	if (!ensure(Turret)) { return; }

	FVector OutTossVelocity(0);
	FVector Start = Barrel->GetSocketLocation(FName("Projectile"));

	if (UGameplayStatics::SuggestProjectileVelocity(this, OutTossVelocity, Start, OutHitPosition, TossSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		AimOrientation = OutTossVelocity.GetSafeNormal();
		AimMovement(AimOrientation);
	}
}

void UAimCmpt::AimMovement(FVector AimOrientation)
{
	if (!ensure(Barrel && Turret)) { return; }

	auto BarrelRot = Barrel->GetForwardVector().Rotation();
	auto Rotator = AimOrientation.Rotation() - BarrelRot;
	Barrel->Elevate(Rotator.Pitch);
	Turret->Rotate(Rotator.Yaw);
}

void UAimCmpt::Fire()
{
	if (!ensure(Barrel)) { return; }
	if (!ensure(ProjectileBP)) { return; }

	if (((GetWorld()->GetTimeSeconds() - LastFire) > Reload))
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBP, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));
		Projectile->Launch(TossSpeed);
		LastFire = GetWorld()->GetTimeSeconds();
	}
}
