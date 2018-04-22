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
	
private:

	virtual void BeginPlay() override;
	void Tick(float DeltaTime);
	ATank * GetControlledTank() const;
	///Start tank moving barrel towards cross hairs
	void AimTowardsCrossHairs();
	///Get the location where a line trace thru the cross hairs hits an actor (landscape, tank, whatever)
	///Uses an OUT parameter "HitLocation"
	bool GetSightRayHitLocation(FVector & HitLocation) const;
	UPROPERTY(EditAnywhere)
	float CrossHairsXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairsYLocation = 0.3333;
	float LineTraceRange = 1000000.0;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
};
