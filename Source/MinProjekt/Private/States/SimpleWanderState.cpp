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

	if (_sm->bMoveUp)
	{
		_target = _sm->TopPosition;
	}
	else
	{
		_target = _sm->BottomPosition;
	}

	/*_waitTime = 3.0f;
	_dir = FMath::VRand();
	_dir.Z = 0;
	_dir.Normalize();*/
}

TSharedPtr<BaseState> SimpleWanderState::OnUpdate(float DeltaTime)
{
	auto owner = _sm->GetOwner();
	if (IsValid(owner))
	{
		FVector Current = owner->GetActorLocation();
		FVector Direction = (_target - Current).GetSafeNormal();
		owner->AddActorWorldOffset(Direction * _speed * DeltaTime);

		float Distance = FVector::Dist(Current, _target);

		if (Distance < 10.f)
		{
			_sm->bMoveUp = !_sm->bMoveUp;
			return _sm->_idleState;
		}

		return _sm->_wanderState;
	}

	return nullptr;

	/*if (_waitTime < 0)
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

	return _sm->_wanderState;*/
}

void SimpleWanderState::OnExit()
{
	UE_LOG(LogTemp, Log, TEXT("Exiting Wander State"));
}
