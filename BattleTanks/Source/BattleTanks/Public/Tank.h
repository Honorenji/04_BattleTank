// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

/// Forward Declaration
class UTankAimingComponent;

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

private:	
	// Sets default values for this pawn's properties
	ATank();

	UTankAimingComponent* AimingComponent = nullptr;

	virtual void Tick(float Deltatime) override;

	virtual void BeginPlay() override;
	
};
