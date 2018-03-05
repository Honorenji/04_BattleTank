// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"


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
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

