// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

#include "MovingPlatform.generated.h"

UCLASS()
class ANCIENTISLE_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* PlatformMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* PlatformCollider;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector pointA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector pointB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float movementDuration;

};
