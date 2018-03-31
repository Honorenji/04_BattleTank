// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankTrack.h"


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
	if (ensure(LeftTrack && RightTrack))
	{
		LeftTrack->CustomTick(DeltaTime);
		RightTrack->CustomTick(DeltaTime);
	} 
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	AimingComponent = FindComponentByClass<UTankAimingComponent>();
	Tracks = TArray<UTankTrack*>();
	GetComponents<UTankTrack>(Tracks);

	if (!ensure(Tracks[0] && Tracks[1])) { return; }
	LeftTrack = Tracks[0];
	RightTrack = Tracks[1];
	UE_LOG(LogTemp, Warning, TEXT("LeftTrack: %s. RightTrack: %s."), *LeftTrack->GetName(), *RightTrack->GetName());
}
