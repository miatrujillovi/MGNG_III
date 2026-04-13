// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "CSaveAudioSettings.generated.h"

/**
 * 
 */
UCLASS()
class MINPROJEKT_API UCSaveAudioSettings : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float mainVolume;

	UPROPERTY()
	float musicVolume;

	UPROPERTY()
	float sfxVolume;
	
};
