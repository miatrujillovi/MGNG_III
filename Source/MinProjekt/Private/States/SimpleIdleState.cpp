// Fill out your copyright notice in the Description page of Project Settings.


#include "States/SimpleIdleState.h"
#include "States/SimpleStateMachine.h"

SimpleIdleState::SimpleIdleState()
{
}

SimpleIdleState::~SimpleIdleState()
{
}

void SimpleIdleState::OnEnter()
{
	UE_LOG(LogTemp, Log, TEXT("Entering Idle State"));
	_waitTime = 3.0f;
}

TSharedPtr<BaseState> SimpleIdleState::OnUpdate(float DeltaTime)
{
	if (_sm->bShouldMove) 
	{
		_sm->bShouldMove = false;
		return _sm->_wanderState;
	}

	return _sm->_idleState;


	/*if (_waitTime < 0)
	{
		return _sm->_wanderState;
	}
	_waitTime -= DeltaTime;

	return _sm->_idleState;*/
}

void SimpleIdleState::OnExit()
{
	UE_LOG(LogTemp, Log, TEXT("Exiting Idle State"));
}
