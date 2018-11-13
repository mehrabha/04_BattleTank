// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn {
	GENERATED_BODY()

public:
	// Called from Controller classes
	void AimAtLocation(FVector WorldLocation);

protected:
	UTankAimingComponent* AimingComponent = nullptr;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

private:	
	// Sets default values for this pawn's properties
	ATank();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

};
