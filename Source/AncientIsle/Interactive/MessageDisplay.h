// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"

#include "MessageDisplay.generated.h"

UCLASS()
class ANCIENTISLE_API AMessageDisplay : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMessageDisplay();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* TriggerBox;

	UFUNCTION(BlueprintCallable)
	FString GetMessageContent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	FString messageContent;

};
