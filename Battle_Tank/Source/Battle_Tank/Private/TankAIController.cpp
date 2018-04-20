// Fill out your copyright notice in the Description page of Project Settings.
#include "Engine/World.h"
#include "Public/TankAIController.h"



ATank * ATankAIController::GetPlayerTank() const
{
	ATank* FPCT = Cast<ATank> (GetWorld()->GetFirstPlayerController()->GetPawn());
	
	return FPCT;
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Tank AI Controller %s is running"), *this->GetName() )
	ATank* myTank = GetPlayerTank();

	if (myTank) {
		UE_LOG(LogTemp, Warning, TEXT("Acquired enemy Tank  %s :  "), *myTank->GetName())
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("No  Player Controlled Tank/controller"))
	}
}

ATank * ATankAIController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}
