// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AimCmpt.generated.h"

class UBarrel;
class UTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUBBLETANK_API UAimCmpt : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAimCmpt();

	void AimAt(FVector OutHitPosition);
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void init(UBarrel* SetBarrel, UTurret* SetTurret);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	void AimMovement(FVector AimOrientation);

	UBarrel* Barrel = nullptr;
	UTurret* Turret = nullptr;

	FVector AimOrientation;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 10000.0;
};
