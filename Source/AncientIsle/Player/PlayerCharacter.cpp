// Fill out your copyright notice in the Description page of Project Settings.


#include "AncientIsle/Player/PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	PlayerCamera->AttachTo(RootComponent);

	CarryItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Carry Item Mesh"));
	CarryItemMesh->AttachTo(PlayerCamera);
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

	PlayerInputComponent->BindAction("Primary", IE_Pressed, this, &APlayerCharacter::PickupItem);
	PlayerInputComponent->BindAction("Primary", IE_Released, this, &APlayerCharacter::DropItem);

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

void APlayerCharacter::PickupItem()
{
	if (ItemActor) //If a gem is already being carried, abort
	{
		return;
	}

	FVector Start = PlayerCamera->GetComponentLocation();
	FVector End = ((PlayerCamera->GetForwardVector() * TraceDistance) + Start);

	FHitResult Hit;
	FCollisionQueryParams TraceParams;

	bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams);

	DrawDebugLine(GetWorld(), Start, End, FColor::Orange, false, 0.1f);

	if(bHit)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Orange, FString::Printf(TEXT("Trace Hit: %s "), *Hit.GetActor()->GetName()));

		if (Hit.GetActor()->ActorHasTag("Item")) //If the actor is a gem, then equip to the player 'carry mesh' and disable the mesh
		{
			ItemActor = Hit.GetActor();

			//Find the item's mesh
			TArray<UStaticMeshComponent*> Components;
			ItemActor->GetComponents<UStaticMeshComponent>(Components);
			for (int32 i = 0; i < Components.Num(); i++)
			{
				UStaticMeshComponent* StaticMeshComponent = Components[i];
				UStaticMesh* StaticMesh = StaticMeshComponent->GetStaticMesh();

				if (StaticMesh != nullptr)
				{
					//Match the material and mesh to the picked up item
					CarryItemMesh->SetStaticMesh(StaticMesh);
					CarryItemMesh->SetMaterial(0, StaticMeshComponent->GetMaterial(0));
					break;
				}
			}

			ItemActor->SetActorHiddenInGame(true); //Hide the original item that has been picked up
		}
	}
}

void APlayerCharacter::DropItem()
{
	if (ItemActor) //If the item is valid (is being carried), then enable the original item object and change the position to the location of the carry item mesh
	{
		ItemActor->SetActorHiddenInGame(false);
		CarryItemMesh->SetStaticMesh(NULL);
		ItemActor->SetActorLocation(CarryItemMesh->GetComponentLocation());
		ItemActor = nullptr;
	}
}
