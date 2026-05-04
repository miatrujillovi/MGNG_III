// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CAudioLibrary.generated.h"

class USoundBase; //Forward Declaration

UENUM(BlueprintType)
enum class EAudioTag : uint8 
{
	Unknown = 0,
	Town1,
	Town2,
	What
};

USTRUCT(BlueprintType) //Estructura de Datos
struct FLibraryEntry 
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EAudioTag Tag = EAudioTag::Unknown;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<USoundBase> Sound;
};

/**
 * 
 */
UCLASS()
class MINPROJEKT_API UCAudioLibrary : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FLibraryEntry> Entries;
};
