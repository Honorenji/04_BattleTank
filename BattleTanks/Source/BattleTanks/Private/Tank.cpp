// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"


// Sets default values
ATank::ATank()
{
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));

}



// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	if (!BarrelToSet) { return; }
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	if (!TurretToSet) { return; }
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	bool  bIsReloaded = (FPlatformTime::Seconds() - LastFireTime > ReloadTimeInSeconds);
	if (Barrel && bIsReloaded)
	{
		// Spawn a projectile at the end of the barrel's socket
		auto Shot = GetWorld()->SpawnActor<AProjectile>(
			Projectile,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		Shot->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}

