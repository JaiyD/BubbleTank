// Fill out your copyright notice in the Description page of Project Settings.


#include "AimCmpt.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Barrel.h"
#include "Turret.h"

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


void UAimCmpt::AimAt(FVector OutHitPosition)
{
	FVector OutThrowVelocity(0);
	FVector Start = Barrel->GetSocketLocation(FName("Projectile"));
	if (UGameplayStatics::SuggestProjectileVelocity(this, OutThrowVelocity, Start, OutHitPosition, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		AimOrientation = OutThrowVelocity.GetSafeNormal();
		AimMovement(AimOrientation);
	}
}

void UAimCmpt::AimMovement(FVector AimOrientation)
{
	if (!ensure(Barrel && Turret)) { return; }

	
	FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator Movement = AimOrientation.Rotation() - BarrelRotation;
	Barrel->Elevate(Movement.Pitch);
	Turret->Rotate(Movement.Yaw);

}
