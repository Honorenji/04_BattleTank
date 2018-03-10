// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Components/PrimitiveComponent.h"

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


