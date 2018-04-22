// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "Engine/World.h"


// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ATank* target = GetPlayerTank();
	GetControlledTank()->AimAt(target->GetActorLocation());

}



ATank * ATankAIController::GetControlledTank() const {

	return Cast<ATank>(this->GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	///Get the Player Tank controller and then the Tank itself
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
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


