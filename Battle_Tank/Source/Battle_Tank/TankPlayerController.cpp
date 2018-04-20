// Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerController.h"
#include "Battle_Tank.h"

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
///TODO implement aimatCrosshairs
	AimTowardsCrossHairs();
}
void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller running"))
	ATank* myTank = GetControlledTank();

	if (myTank) {
		UE_LOG(LogTemp, Warning, TEXT("Tank  %s is under Control"), *myTank->GetName())
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("No Controlled Tank"))
	}
}

ATank * ATankPlayerController::GetControlledTank() const {

	return Cast<ATank> (GetPawn());
}
//start the barrel moving towards the cross hairs to fire
void ATankPlayerController::AimTowardsCrossHairs() {
	if (!GetControlledTank()) { return; }

}