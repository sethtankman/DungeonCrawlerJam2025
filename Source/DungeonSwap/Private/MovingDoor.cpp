// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingDoor.h"

// Sets default values
AMovingDoor::AMovingDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingDoor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(Delay <= 0)
		AMovingDoor::MoveDoor(DeltaTime);
	Delay--;
}

void AMovingDoor::MoveDoor(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + (DoorVelocity * DeltaTime);
	SetActorLocation(CurrentLocation);
	float DistanceMoved = FVector::Dist(CurrentLocation, StartLocation);

	if (DistanceMoved > MoveDistance)
	{
		Delay = 100;
		DoorVelocity = -DoorVelocity;
		FVector MoveDirection = DoorVelocity.GetSafeNormal();
		StartLocation = StartLocation - MoveDirection * MoveDistance;
	}
}

