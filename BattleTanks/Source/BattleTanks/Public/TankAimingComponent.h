// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"

// Enum to state FiringState
UENUM()
enum class EFiringState : uint8
{
	Invalid,
	Reloading,
	Aiming,
	Locked
};

// Forward Declaration.
class UTankBarrel; 
class UTankTurret;

// Hold barrel's property and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector, float);

protected:

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

private:	
	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;

	void AimTowards(FVector);

		
	
};
