// Fill out your copyright notice in the Description page of Project Settings.


#include "AncientIsle/Interactive/Statue.h"

// Sets default values
AStatue::AStatue()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StatueMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Statue Mesh"));
	StatueMesh->SetupAttachment(RootComponent);

	GemColliderTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Gem Collider Trigger"));
	GemColliderTrigger->SetupAttachment(StatueMesh);

}

// Called when the game starts or when spawned
void AStatue::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStatue::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

