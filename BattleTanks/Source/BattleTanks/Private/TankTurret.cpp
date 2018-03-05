// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	SetRelativeRotation(FRotator(0, (RelativeRotation.Yaw + (RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds)), 0));
}



