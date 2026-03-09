// Fill out your copyright notice in the Description page of Project Settings.


#include "CInventoryManager.h"

// Sets default values
ACInventoryManager::ACInventoryManager()
{

}

// Called when the game starts or when spawned
void ACInventoryManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACInventoryManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//DELEGATE
void ACInventoryManager::CoinAdd_Implementation(int coinAmount)
{
	_coins += coinAmount;
	OnCoinUpdated.Broadcast(_coins);
}

