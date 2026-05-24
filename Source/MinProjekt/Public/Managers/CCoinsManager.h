// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CCoinsManager.generated.h"

/**
 * 
 */
UCLASS()
class MINPROJEKT_API UCCoinsManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddCoins(float _coins);

	UFUNCTION(BlueprintCallable)
	void SubstractCoins(float _coins);

	UFUNCTION(BlueprintCallable)
	float GetCoins();

private:
	float coins;
	
};
