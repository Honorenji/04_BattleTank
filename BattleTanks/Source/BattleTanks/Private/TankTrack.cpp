// Copyright Lunatinc

#include "TankTrack.h"
#include "Components/PrimitiveComponent.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	// UE_LOG(LogTemp, Warning, TEXT("%s ticking."), *GetName());

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
	UE_LOG(LogTemp, Warning, TEXT("I'm hit! Call for back-up!"));
}

void UTankTrack::CustomTick(float DeltaTime)
{
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

	// Work-out the required acceleration this frame to correct
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
	Throttle = FMath::Clamp<float>(Throttle, -1, 1);

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


