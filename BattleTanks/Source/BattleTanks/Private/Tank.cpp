// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"


// Sets default values
ATank::ATank()
{

}

void ATank::Initialise(
	UTankAimingComponent * TankAimingComponentToSet,
	UTankBarrel* BarrelToSet)
{
	TankAimingComponent = TankAimingComponentToSet;
	Barrel = BarrelToSet;
}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool  bIsReloaded = (FPlatformTime::Seconds() - LastFireTime > ReloadTimeInSeconds);
	if (bIsReloaded)
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

