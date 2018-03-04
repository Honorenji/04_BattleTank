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
	// AimAtCrosshair();
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

	// Get world location if linetrace through crosshair
		// if hit == landscape
			// Aim controlled tank to hit location
}


