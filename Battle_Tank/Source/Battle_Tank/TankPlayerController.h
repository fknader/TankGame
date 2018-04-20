// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	ATank * GetControlledTank() const;

	//get a reference to the inherited BeginPlay
	virtual void BeginPlay() override;
	void AimTowardsCrossHairs();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
