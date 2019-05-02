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
	UTrack();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = Input)
	void SetSpeed(float Throttle);

	UPROPERTY(EditDefaultsOnly)
	float DrivingForce = 140000000.0;//newtons

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void Drive();

	float CurrentSpeed = 0;
	
};
