// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI controlled tank: %s"), *ControlledTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI not controlling a tank"));
	}
}

ATank* ATankAIController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

