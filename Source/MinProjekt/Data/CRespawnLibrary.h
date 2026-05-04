// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CRespawnLibrary.generated.h"

USTRUCT(BlueprintType)
struct FRespawnPoint 
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName ID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FVector Location;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FRotator Rotation = FRotator::ZeroRotator;
};

UCLASS()
class MINPROJEKT_API UCRespawnLibrary : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FRespawnPoint> RespawnPoints;
};
