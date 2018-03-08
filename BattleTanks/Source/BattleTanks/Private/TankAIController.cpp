// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	if (Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn())
		&& Cast<ATank>(GetPawn()))
	{
		// TODO Go to player

		// Aim at Player
		Cast<ATank>(GetPawn())->AimAt(
			Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn())->GetActorLocation());

		// TODO Fire if ready
		Cast<ATank>(GetPawn())->Fire(); // TODO limit fire rate
	}
}


