// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

#include "Statue.generated.h"

UCLASS()
class ANCIENTISLE_API AStatue : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AStatue();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StatueMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* GemColliderTrigger;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
