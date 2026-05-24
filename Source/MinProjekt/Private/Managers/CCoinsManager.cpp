// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/CCoinsManager.h"

void UCCoinsManager::AddCoins(float _coins)
{
	coins = coins + _coins;
}

void UCCoinsManager::SubstractCoins(float _coins)
{
	coins = coins - _coins;
}

float UCCoinsManager::GetCoins()
{
	return coins;
}
