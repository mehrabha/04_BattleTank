// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) {
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAtLocation(FVector WorldLocation, float Speed) {
	if (!Barrel) { return; }

	FVector OutVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("ProjectileSpawn"));

	bool bSuccess = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutVelocity,
		StartLocation,
		WorldLocation,
		Speed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if(bSuccess) {
		auto AimDirection = OutVelocity.GetSafeNormal();

		MoveBarrel(AimDirection);

		/*
		UE_LOG(
			LogTemp,
			Warning,
			TEXT("%s is aiming at %s"),
			*GetOwner()->GetName(),  // Tank Name
			*AimDirection.ToString()
		);
		*/
	}
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection) {
	//  Get difference between current and desired rotation
	FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimRotation = AimDirection.Rotation();
	FRotator DeltaRotation = AimRotation - BarrelRotation;

	// Elevate to desired world rotation
	Barrel->Elevate(5);
}

