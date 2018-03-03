// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	if (!GetControlledTank()) UE_LOG(LogTemp, Warning, TEXT("TankAIController could not posses tank!"))
	else UE_LOG(LogTemp, Warning, TEXT("TankAIController possessed: %s"), *GetControlledTank()->GetName())
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


