// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

/// Forward Declaration
class UTankAimingComponent;
class UTankTrack;

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

private:	
	// Sets default values for this pawn's properties
	ATank();

	UTankAimingComponent* AimingComponent = nullptr;

	UTankTrack* LeftTrack = nullptr;

	UTankTrack* RightTrack = nullptr;

	TArray<UTankTrack*> Tracks;

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;
	
};
