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
	OutOfAmmo,
	Reloading,
	Aiming,
	Locked
};

// Forward Declaration.
class UTankBarrel; 
class UTankTurret;
class AProjectile;

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

	UFUNCTION(BlueprintCallable, Category = "Fire")
	void Fire(); 
	
	UFUNCTION(BlueprintCallable, Category = "Fire")
	int32 GetRoundsLeft() const;

	void AimAt(FVector);

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	EFiringState GetFiringState() const;

	

protected:

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Locked;

private:	

	virtual void BeginPlay() override;

	void AimTowards(FVector);

	bool IsBarrelMoving();


	FVector AimDirection;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> Projectile = nullptr;

	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Fire")
	float LaunchSpeed = 8000;

	UPROPERTY(EditDefaultsOnly, Category = "Fire")
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Fire")
	int32 RoundsLeft = 3;

	double LastFireTime = 0;

		
	
};
