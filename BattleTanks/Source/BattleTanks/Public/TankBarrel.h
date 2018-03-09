// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * Allows for the launching of projectiles.
 * Projectiles must inherit from <Projectile>
 * Use the set reference method to set a reference to this component.
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 5;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevationDegrees = 40;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevationDegrees = 0;

	
	
	
	
};
