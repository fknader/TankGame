// Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerController.h"
#include "Battle_Tank.h"
#include "Engine/World.h"
#include "Camera/PlayerCameraManager.h"


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
		GetControlledTank()->AimAt(HitLocation);
		//UE_LOG(LogTemp, Warning, TEXT("Hit Location is %s"), *HitLocation.ToString())
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const
{
	//find the cross hair coords
	//De-project the viewport(screen) coords to a world direction
	//line trace along that direction to see what we hit.

	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);	//we now have the viewport size
	FVector2D ScreenLocation = FVector2D(ViewportSizeX*CrossHairsXLocation, ViewportSizeY*CrossHairsYLocation);

	FVector LookDirection;

	if (GetLookDirection( ScreenLocation, LookDirection)) {
		GetLookVectorHitLocation(LookDirection, HitLocation);
		//UE_LOG(LogTemp, Warning, TEXT("World Direction is %s"), *LookDirection.ToString())
		return true;
	}
	//HitLocation = FVector(0.0);
	return false;
}



bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {
	FVector WorldLocation; //not used
	return (DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		WorldLocation,
		LookDirection));
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)) {
		//auto HitComp = HitResult.GetComponent();
		

		HitLocation = HitResult.Location;
		//UE_LOG(LogTemp, Warning, TEXT(" Target is %s "), *HitComp->GetName())
		return true;
	}
	HitLocation = FVector(0.0);
	return false;
}