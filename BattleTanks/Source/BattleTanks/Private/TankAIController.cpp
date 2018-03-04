// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/Actor.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	if (!GetControlledTank()) UE_LOG(LogTemp, Warning, TEXT("TankAIController could not posses tank!"))
	else UE_LOG(LogTemp, Warning, TEXT("TankAIController possessed: %s"), *GetControlledTank()->GetName())

    if (!GetPlayerTank()) UE_LOG(LogTemp, Warning, TEXT("TankAIController could not find the player tank!"))
	else UE_LOG(LogTemp, Warning, TEXT("TankAICOntroller spotted the player: %s"), *GetPlayerTank()->GetName())
}

void ATankAIController::Tick(float DeltaTime)
{
	if (GetPlayerTank() && GetControlledTank())
	{
		// TODO Go to player

		// Aim at Player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// TODO Fire if ready
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


