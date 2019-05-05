// Fill out your copyright notice in the Description page of Project Settings.


#include "Track.h"

UTrack::UTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTrack::BeginPlay()
{
	Super::BeginPlay();

	OnComponentHit.AddDynamic(this, &UTrack::OnHit);
}

void UTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	Drive();
	Slipping();
	CurrentSpeed = 0;
}

//force to counteract the slipping of the tanks
void UTrack::Slipping()
{

	auto Slip = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto Time = GetWorld()->GetDeltaSeconds();
	auto Acceleration = -Slip / Time * GetRightVector();//opposite of what is needed

	auto Root = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto Force = (Root->GetMass() * Acceleration) / 2;//two tracks with F=ma
	Root->AddForce(Force);
}


void UTrack::SetSpeed(float Speed)
{
	CurrentSpeed = FMath::Clamp<float>(CurrentSpeed + Speed, -1, 1);
}

void UTrack::Drive()
{
	FVector Force = this->GetForwardVector() * this->CurrentSpeed * this->DrivingForce;
	//auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto RootComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	RootComponent->AddForceAtLocation(Force, ForceLocation);
}

