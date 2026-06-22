// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class USimpleStateMachine;

/**
 * 
 */
class MINPROJEKT_API BaseState
{
public:
	BaseState();
	virtual ~BaseState();

	virtual void OnEnter() = 0;
	virtual TSharedPtr<BaseState> OnUpdate(float DeltaTime) = 0;
	virtual void OnExit() = 0;

	virtual void SetStateMachine(USimpleStateMachine* sm) {
		_sm = sm;
	}

protected:
	USimpleStateMachine* _sm;
};
