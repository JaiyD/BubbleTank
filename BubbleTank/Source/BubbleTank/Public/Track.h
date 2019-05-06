// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Track.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BUBBLETANK_API UTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//set the default values for the track's properties
	UTrack();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//setting the speed of the tracks
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetSpeed(float Throttle);
	//force needed to drive the tank through the tracks
	UPROPERTY(EditDefaultsOnly)
	float DrivingForce = 80000000.0;//newtons

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void Slipping();

	void Drive();

	float CurrentSpeed = 0;
	
};
