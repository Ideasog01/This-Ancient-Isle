// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/StaticMeshComponent.h"

#include "NoteObject.generated.h"

UCLASS()
class ANCIENTISLE_API ANoteObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANoteObject();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Additional Components")
	UStaticMeshComponent* StaticMesh;

	UFUNCTION(BlueprintCallable)
	FString GetAddressee();

	UFUNCTION(BlueprintCallable)
	FString GetMain();

	UFUNCTION(BlueprintCallable)
	FString GetSender();

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Note Content")
	FString Addressee;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Note Content")
	FString Main;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Note Content")
	FString Sender;

};
