// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"


// Sets default values
ATank::ATank()
{

}

float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}

float ATank::TakeDamage(
	float DamageAmount, 
	FDamageEvent const & DamageEvent, 
	AController * EventInstigator,
	AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);
	UE_LOG(LogTemp, Warning, TEXT("Damage Amount send: %f, Damage to be applied: %d."), DamageAmount, DamageToApply);

	CurrentHealth -= DamageToApply;
	UE_LOG(LogTemp, Warning, TEXT("%s has %d HP left."), *GetName(), CurrentHealth);
	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}
	return DamageToApply;
}
