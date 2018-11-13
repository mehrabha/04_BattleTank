// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetPlayerTank();

	if (ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI controller found player: %s"), *ControlledTank->GetName());
	} else {
		UE_LOG(LogTemp, Warning, TEXT("AI controller can't find a player"));
	}
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {
		AimTowardsPlayer();
	}
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (PlayerPawn) {
		return Cast<ATank>(PlayerPawn);
	} else {
		return nullptr;
	}
}

// Make this tank aim at player location
void ATankAIController::AimTowardsPlayer() {
	auto AITank = GetControlledTank();
	auto PlayerLocation = GetPlayerTank()->GetActorLocation();

	if (AITank) {
		AITank->AimAtLocation(PlayerLocation);
	}
}
