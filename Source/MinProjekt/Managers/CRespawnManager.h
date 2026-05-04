// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CRespawnManager.generated.h"

class UCRespawnLibrary;

UCLASS()
class MINPROJEKT_API UCRespawnManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void RespawnPlayer(FName _idLocation);

	UFUNCTION(BlueprintCallable)
	void SetRespawnLibrary(UCRespawnLibrary* _respawnLibrary);

private:
	UPROPERTY()
	TObjectPtr<UCRespawnLibrary> respawnLibrary;
};
