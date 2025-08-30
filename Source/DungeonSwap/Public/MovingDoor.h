// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingDoor.generated.h"

UCLASS()
class DUNGEONSWAP_API AMovingDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void MoveDoor(float DeltaTime);

	UPROPERTY(EditAnywhere, Category="Moving Door")
	FVector DoorVelocity;

	UPROPERTY(EditAnywhere, Category="Moving Door")
	float MoveDistance;

	int Delay;

	UPROPERTY(EditAnywhere, Category="Moving Door")
	FVector StartLocation;

};
