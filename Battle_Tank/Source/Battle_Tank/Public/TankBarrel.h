// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
///Add the Classgroup and Meta data to makew this class available in the Blueprint
///What we will do is replace the staticmesh "Barrel" with this TankBarrel

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLE_TANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 20; //guess a reasonable value
	
	UPROPERTY(EditAnywhere)
	float MinElevation = 0.f;

	UPROPERTY(EditAnywhere)
	float MaxElevation = 40.f;

	
};
