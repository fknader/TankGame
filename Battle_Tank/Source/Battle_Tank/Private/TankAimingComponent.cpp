// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAimingComponent.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
	//Barrel->Get
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	
	///Instead of using GetComponentLocation: Create a socket at the end of the barrel, called "Projectile"
	///and then use GetSocketLocation.
	auto StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	
	if (!Barrel) { return; }
	FVector TossVelocity;
	if (UGameplayStatics::SuggestProjectileVelocity(
		this, 
		TossVelocity, 
		StartLocation, 
		HitLocation, 
		LaunchSpeed, 
		false,
		0.f,
		0.f,
		ESuggestProjVelocityTraceOption::DoNotTrace)) 
	{
		///GetSafeNormal "normalizes" a vector (enuring you dont divide by zero) - by making it a unit vector
		///ie strip off the length, making it length 1 - but maintaining the Direction. 
		///Effectively getting the Direction component
		auto AimDirection = TossVelocity.GetSafeNormal();
		auto ThisTankName = GetOwner()->GetName();

		UE_LOG(LogTemp, Warning, TEXT(" %s aiming at %s"), *ThisTankName, *AimDirection.ToString())
	}

}

