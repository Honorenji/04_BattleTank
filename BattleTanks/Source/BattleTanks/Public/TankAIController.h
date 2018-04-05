// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "AIController.h"
#include "TankAIController.generated.h"

UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:

	UFUNCTION()
	void OnPossedTankDeath();

	virtual void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

	virtual void Tick(float DeltaTime) override;

	// How close can the AI get
	UPROPERTY(EditDefaultsOnly, Category = "AI Behaviour")
	float AcceptanceRadius = 8000;
	
	
};
