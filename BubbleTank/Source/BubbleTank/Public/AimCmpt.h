// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AimCmpt.generated.h"

class UBarrel;
class UTurret;
class AProjectile;

UENUM()
enum class EFireState : uint8
{
	Reloading,
	Loaded
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUBBLETANK_API UAimCmpt : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAimCmpt();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = Status)
	EFireState FiringState = EFireState::Reloading;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimDirection(FVector OutHitPosition);
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void init(UBarrel* SetBarrel, UTurret* SetTurret);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

private:
	void AimMovement(FVector AimOrientation);

	UBarrel* Barrel = nullptr;
	UTurret* Turret = nullptr;

	FVector AimOrientation;

	float LastFire = 0;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float Reload = 3;
	UPROPERTY(EditAnywhere, Category = Firing)
	float TossSpeed = 8000.0;
	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBP;
		
};
