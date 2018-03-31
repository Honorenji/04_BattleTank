// Copyright Lunatinc

#include "TankTrack.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/World.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrack::BeginPlay()
{
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::OnHit(
	UPrimitiveComponent * HitComponent, 
	AActor * OtherActor, 
	UPrimitiveComponent * OtherComp, 
	FVector NormalImpulse, 
	const FHitResult & Hit)
{
	DriveTrack();
	ApplySidewaysForce();
	CurrentThrottle = 0; // Reset Throttle so tank won't apply force when trigger is released.
}

void UTankTrack::ApplySidewaysForce()
{
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

	// Work-out the required acceleration this frame to correct
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	// Calculate and apply force
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; // Division by two, since there are two tracks on the tank.
	TankRoot->AddForce(CorrectionForce);
}

/*
* Set the Throttle of the track to a max of 1 and a min of -1.
* 1 is forwards, -1 is backwards.
*/
void UTankTrack::SetThrottle(float Throttle)
{

	// Clamp Throttle between 1 and -1 so player can't drive faster.
	CurrentThrottle = FMath::Clamp(CurrentThrottle + Throttle, -1.0f, +1.0f);
}

void UTankTrack::DriveTrack()
{
	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


