// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/TankAIController.h"
#include "Engine/World.h"




void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* atank = GetPlayerTank();
	if (atank) {
		UE_LOG(LogTemp, Warning, TEXT("Player Tank = %s"), *atank->GetName())
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No Player Tank or Controller"))
	}
}
ATank * ATankAIController::GetControlledTank() const {

	return Cast<ATank>(this->GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	///Get the Player Tank controller and then the Tank itself
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

