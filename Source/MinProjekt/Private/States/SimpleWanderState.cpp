// Fill out your copyright notice in the Description page of Project Settings.


#include "States/SimpleWanderState.h"
#include "States/SimpleStateMachine.h"

SimpleWanderState::SimpleWanderState()
{
}

SimpleWanderState::~SimpleWanderState()
{
}

void SimpleWanderState::OnEnter()
{
	UE_LOG(LogTemp, Log, TEXT("Entering Wander State"));
	_waitTime = 3.0f;
	_dir = FMath::VRand();
	_dir.Z = 0;
	_dir.Normalize();
}

TSharedPtr<BaseState> SimpleWanderState::OnUpdate(float DeltaTime)
{
	if (_waitTime < 0) 
	{
		return _sm->_idleState;
	}
	_waitTime -= DeltaTime;
	auto owner = _sm->GetOwner();
	if (IsValid(owner)) 
	{
		FVector move = _dir * _speed * DeltaTime;
		owner->AddActorWorldOffset(move);
	}

	return _sm->_wanderState;
}

void SimpleWanderState::OnExit()
{
	UE_LOG(LogTemp, Log, TEXT("Exiting Wander State"));
}
