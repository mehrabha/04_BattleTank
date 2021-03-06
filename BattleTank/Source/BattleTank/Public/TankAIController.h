// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "AIController.h"
#include "TankAIController.generated.h"


UCLASS()
class BATTLETANK_API ATankAIController : public AAIController {
	GENERATED_BODY()

public:
	void Tick(float DeltaTime) override;

private:
	virtual void BeginPlay() override;
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;
	void AimTowardsPlayer();
};
