// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseState.h"
#include "CoreMinimal.h"

/**
 * 
 */
class MINPROJEKT_API SimpleWanderState : public BaseState
{
public:
	SimpleWanderState();
	~SimpleWanderState();

	void OnEnter() override;
	TSharedPtr<BaseState> OnUpdate(float DeltaTime) override;
	void OnExit() override;

protected:
	float _waitTime = 0;
	FVector _dir;
	float _speed = 250;
};
