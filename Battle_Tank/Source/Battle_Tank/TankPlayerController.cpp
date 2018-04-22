// Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerController.h"
#include "Battle_Tank.h"
#include "Engine/World.h"


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

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	///TODO implement aimatCrosshairs
	AimTowardsCrossHairs();
}


ATank * ATankPlayerController::GetControlledTank() const {

	return Cast<ATank> (GetPawn());
}

void ATankPlayerController::AimTowardsCrossHairs() {
	if (!GetControlledTank()) { return; }
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const
{
	//find the cross hair coords
	//De-project the viewport(screen) coords to a world direction
	//line trace along that direction to see what we hit.

	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);	//we now have the viewport size
	FVector2D ScreenLocation = FVector2D(ViewportSizeX*CrossHairsXLocation, ViewportSizeX*CrossHairsYLocation);

	FVector LookDirection;

	if (GetLookDirection( ScreenLocation, LookDirection)) {
		UE_LOG(LogTemp, Warning, TEXT("World Direction is %s"), *LookDirection.ToString())
	}
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {
	FVector WorldLocation;
	return (DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		WorldLocation,
		LookDirection));
}
