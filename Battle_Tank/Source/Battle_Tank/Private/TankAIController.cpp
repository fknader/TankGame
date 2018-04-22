// Fill out your copyright notice in the Description page of Project Settings.

<<<<<<< HEAD

=======
>>>>>>> master
#include "Public/TankAIController.h"
#include "Engine/World.h"


<<<<<<< HEAD
// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ATank* target = GetPlayerTank();
	GetControlledTank()->AimAt(target->GetActorLocation());

}


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

=======

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
>>>>>>> master
