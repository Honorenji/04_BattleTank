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
		GetControlledTank()->AimAt(HitLocation);
	}
}

// Get world location if linetrace through crosshair, true if hit landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		// Line-trace along that look direction, and see what we hit (up to max range)
		return GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}
	return false; 
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	// "De-project" the screen position of the crosshair to a world direction
	FVector CameraWorldLocation;
	return (DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection)
		);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility))
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0);
	return false; // No hit found


}


