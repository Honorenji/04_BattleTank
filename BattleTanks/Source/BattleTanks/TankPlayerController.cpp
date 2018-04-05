// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"
#include "TankAimingComponent.h"

ATankPlayerController::ATankPlayerController()
{
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
}

void ATankPlayerController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::OnPossedTankDeath);
	}
}

void ATankPlayerController::OnPossedTankDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("YOU DIED. scrub."));
	StartSpectatingOnly();
}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
	AimAtCrosshair();
}

// Aim the ControlledTank's barrel to where the crosshair intersects with the world.
void ATankPlayerController::AimAtCrosshair()
{ 
	// if (!ensure(AimingComponent)) { return; }

	FVector HitLocation; // out parameter
    if (GetSightRayHitLocation(HitLocation)) // side effect: performs a line-trace
	{
		AimingComponent->AimAt(HitLocation);
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
		ECollisionChannel::ECC_Camera))
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0);
	return false; // No hit found
}


