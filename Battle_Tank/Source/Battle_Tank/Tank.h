// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Public/TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLE_TANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	void AimAt(FVector HitLocation);
	
	//Make this callable by the blueprint
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

protected:
	UTankAimingComponent * TankAimingComponent = nullptr;

private:	
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//expose to Blueprint in a new category, "Firing"
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 10000;	//guess what is a reasonable cm/sec speed.
	
};
