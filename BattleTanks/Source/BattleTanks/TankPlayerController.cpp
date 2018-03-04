// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



ATankPlayerController::ATankPlayerController()
{
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (!GetControlledTank()) { UE_LOG(LogTemp, Warning, TEXT("TankPlayerController could not posses tank!"));}

	AimAtCrosshair();
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimAtCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

// Aim the ControlledTank's barrel to where the crosshair intersects with the world.
void ATankPlayerController::AimAtCrosshair()
{
	if (!GetControlledTank()) { return; }
	// TODO Implement pointing ControlledTank to crosshair's intersection

	FVector HitLocation; // out parameter
	if (GetSightRayHitLocation(HitLocation)) // side effect: performs a line-trace
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
				// TODO Aim controlled tank to hit location
	}
}

// Get world location if linetrace through crosshair, true if hit landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;
}


