// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankBarrel.h"
#include "CoreMinimal.h"
#include "Engine/Classes/GameFramework/Actor.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;  // UTankBarrel : UStaticMeshComponent

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	// Called from Tank class
	void AimAtLocation(FVector WorldLocation, float Speed);

private:
	UTankBarrel* Barrel = nullptr;

	void MoveBarrel(FVector AimDirection);
};
