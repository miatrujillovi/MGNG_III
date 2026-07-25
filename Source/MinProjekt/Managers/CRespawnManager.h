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

	UFUNCTION(BlueprintCallable)
	void SetIDLocation(FName NewID);

	UFUNCTION(BlueprintCallable)
	FName GetCurrentIDLocation() const { return CurrentIDLocation; }

private:
	UPROPERTY()
	TObjectPtr<UCRespawnLibrary> respawnLibrary;

	UPROPERTY()
	FName CurrentIDLocation = NAME_None;
};
