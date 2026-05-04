// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CMyGameInstance.generated.h"

class UCAudioLibrary;
class UCRespawnLibrary;

/**
 * 
 */
UCLASS()
class MINPROJEKT_API UCMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void OnStart() override; //Ocurre despues de Init

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Audio")
	TSoftObjectPtr<UCAudioLibrary> Library;

	UPROPERTY(EditDefaultsOnly, Category = "Respawn")
	TSoftObjectPtr<UCRespawnLibrary> respawnLibrary;
};
