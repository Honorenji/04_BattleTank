// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (!GetControlledTank()) UE_LOG(LogTemp, Warning, TEXT("TankPlayerController could not posses tank!"))
	else UE_LOG(LogTemp,Warning, TEXT("TankPlayerController possessed: %s"), *GetControlledTank()->GetName())
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


