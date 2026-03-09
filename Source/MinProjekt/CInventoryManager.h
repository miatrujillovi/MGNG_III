// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CInventoryManager.generated.h"

//DELEGATE
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCoinAdded, int32, cointAmount);

UCLASS()
class MINPROJEKT_API ACInventoryManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACInventoryManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int _coins;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//BlueprintNativeEvent: Lets you do an override. The first one appears directly in the blueprint and the second will be the one on C++
	//ForceAsFunction forces the override custom event to be a function on the blueprint
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Meta = (ForceAsFunction))
	void CoinAdd(int coinAmount);
	virtual void CoinAdd_Implementation(int coinAmount);

	//DELEGATE
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Inventory")
	FOnCoinAdded OnCoinUpdated;

};
