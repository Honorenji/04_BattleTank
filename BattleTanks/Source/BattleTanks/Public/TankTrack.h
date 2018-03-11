// Copyright Lunatinc

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Used to set the maximum driving force of the tank. 
 * Applies forces to the tank.
 * Use the set reference method to set a reference to this component.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// Set a throttle between -1 and 1
	UFUNCTION(BlueprintCallable)
	void SetThrottle(float Throttle);
	
	// Max Force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 40000000; // assume 40 tonne tank with 1g acceleration
	
};
