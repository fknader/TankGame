// Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerController.h"
#include "Battle_Tank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* atank = GetControlledTank();
	if (atank) {
//		UE_LOG(LogTemp, Warning, TEXT("Player Tank = %s"), *atank->GetName())
	}
	else {
//		UE_LOG(LogTemp, Warning, TEXT("No Player Tank"))
	}
}

ATank * ATankPlayerController::GetControlledTank() const {

	return Cast<ATank> (GetPawn());
}