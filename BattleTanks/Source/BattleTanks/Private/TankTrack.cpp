// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

/*
* Set the Throttle of the track to a max of 1 and a min of -1.
* 1 is forwards, -1 is backwards.
*/
void UTankTrack::SetThrottle(float Throttle)
{
	UE_LOG(LogTemp, Warning, TEXT("%s received an input of %f."), *GetName(), Throttle)
}


