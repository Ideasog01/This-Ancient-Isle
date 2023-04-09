// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

#include "Gem.generated.h"

struct FResourceProperties;

UENUM(BlueprintType)
enum GemType //The types of resources
{
	Blue UMETA(DisplayName = "Blue"),
	Orange UMETA(DisplayName = "Orange"),
	Green UMETA(DisplayName = "Green"),
	Purple UMETA(DisplayName = "Purple"),
	Red UMETA(DisplayName = "Red")
};

UCLASS()
class ANCIENTISLE_API AGem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* GemMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* BoxComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	TEnumAsByte<GemType> GetGemType();

private:

	UPROPERTY(EditAnywhere, Category = Type)
	TEnumAsByte<GemType> Type; //The type of gem, red, blue etc

};
