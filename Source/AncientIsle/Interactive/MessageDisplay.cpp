// Fill out your copyright notice in the Description page of Project Settings.


#include "AncientIsle/Interactive/MessageDisplay.h"

// Sets default values
AMessageDisplay::AMessageDisplay()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	TriggerBox->SetupAttachment(RootComponent);

}

FString AMessageDisplay::GetMessageContent()
{
	return messageContent;
}

// Called when the game starts or when spawned
void AMessageDisplay::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMessageDisplay::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

