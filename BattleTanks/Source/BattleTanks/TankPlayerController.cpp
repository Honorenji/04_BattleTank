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
				// TODO Aim controlled tank to hit location
	}
}

// Get world location if linetrace through crosshair, true if hit landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("Screen Location: %s"), *ScreenLocation.ToString());
	// "De-project" the screen position of the crosshair to a world direction
	  
	// Line-trace along that look direction, and see what we hit (up to max range)
	OutHitLocation = FVector(1.0);
	return true;
}


