// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"

#include "Kismet/KismetSystemLibrary.h"
#include "DrawDebugHelpers.h"

#include "PlayerCharacter.generated.h"

UCLASS()
class ANCIENTISLE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDisablePlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Additional Components")
	UCameraComponent* PlayerCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Additional Components")
	UStaticMeshComponent* CarryItemMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
	float CameraRotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Carry Items")
	float TraceDistance = 500;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	void MoveForward(float axis);

	void MoveRight(float axis);

	void LookUp(float axis);

	void LookRight(float axis);

	void PlayerJump();

	void PickupItem();

	void DropItem();

private:

	AActor* ItemActor;
};
