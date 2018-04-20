// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
	
private:

	ATank * GetControlledTank() const;
	ATank * GetPlayerTank() const;

	//get a reference to the inherited BeginPlay
	virtual void BeginPlay() override;
	
};
