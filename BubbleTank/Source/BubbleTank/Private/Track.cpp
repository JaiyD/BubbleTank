// Fill out your copyright notice in the Description page of Project Settings.


#include "Track.h"
//set the default values for the track's properties
UTrack::UTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTrack::BeginPlay()
{
	Super::BeginPlay();
	//adding an onhit component to the track, explained below
	OnComponentHit.AddDynamic(this, &UTrack::OnHit);
}

void UTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
//OnHit comopnent ticked every frame to see whenever the track is hitting the ground in order to control the driving of the tanks
void UTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	Drive();
	Slipping();
	CurrentSpeed = 0;//reset so that the tanks don't continue on forever
}

//Force to counteract the slipping of the tanks
void UTrack::Slipping()
{

	auto Slip = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto Time = GetWorld()->GetDeltaSeconds();
	auto Acceleration = -Slip / Time * GetRightVector();//opposite of what is needed

	auto Root = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());//applying the force on the tracks
	auto Force = (Root->GetMass() * Acceleration) / 2;//two tracks with F=ma
	Root->AddForce(Force);
}

//Setting the speed of the tracks
void UTrack::SetSpeed(float Speed)
{
	CurrentSpeed = FMath::Clamp<float>(CurrentSpeed + Speed, -1, 1);//clamping the speed from -1 to 1
}
//Used to drive the tank through the trackks
void UTrack::Drive()
{
	FVector Force = this->GetForwardVector() * this->CurrentSpeed * this->DrivingForce;//the forced needed
	auto ForceLocation = GetComponentLocation();
	auto RootComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());//location of the force, in the tracks
	RootComponent->AddForceAtLocation(Force, ForceLocation);
}

