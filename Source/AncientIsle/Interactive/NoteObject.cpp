// Fill out your copyright notice in the Description page of Project Settings.


#include "AncientIsle/Interactive/NoteObject.h"

// Sets default values
ANoteObject::ANoteObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

}

FString ANoteObject::GetAddressee()
{
	return Addressee;
}

FString ANoteObject::GetMain()
{
	return Main;
}

FString ANoteObject::GetSender()
{
	return Sender;
}

