// Fill out your copyright notice in the Description page of Project Settings.


#include "AncientIsle/Player/PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	PlayerCamera->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MouseY", this, &APlayerCharacter::LookUp);
	PlayerInputComponent->BindAxis("MouseX", this, &APlayerCharacter::LookRight);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::PlayerJump);

}

void APlayerCharacter::MoveForward(float axis)
{
	if (!bDisablePlayer)
	{
		AddMovementInput(GetActorForwardVector(), axis);
	}
}

void APlayerCharacter::MoveRight(float axis)
{
	if(!bDisablePlayer)
	{
		AddMovementInput(GetActorRightVector(), axis);
	}
}

void APlayerCharacter::LookUp(float axis)
{
	if(!bDisablePlayer)
	{
		AddControllerPitchInput(axis);
	}
}

void APlayerCharacter::LookRight(float axis)
{
	if(!bDisablePlayer)
	{
		AddControllerYawInput(axis);
	}
}

void APlayerCharacter::PlayerJump()
{
	if (!bDisablePlayer)
	{
		Jump();
	}
}
