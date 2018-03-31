// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"


// Sets default values
ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ensure(AimingComponent))
	{
		AimingComponent->CustomTick(DeltaTime);
	}
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	AimingComponent = FindComponentByClass<UTankAimingComponent>();
}
