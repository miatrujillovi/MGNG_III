// Fill out your copyright notice in the Description page of Project Settings.


#include "States/SimpleStateMachine.h"
#include "States/SimpleIdleState.h"
#include "States/SimpleWanderState.h"

// Sets default values for this component's properties
USimpleStateMachine::USimpleStateMachine()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USimpleStateMachine::BeginPlay()
{
	Super::BeginPlay();
	InitializeState();
	// ...
	
}


void USimpleStateMachine::InitializeState()
{
	_idleState = MakeShareable<BaseState>(new SimpleIdleState());
	_wanderState = MakeShareable<BaseState>(new SimpleWanderState());
	_idleState->SetStateMachine(this);
	_wanderState->SetStateMachine(this);

	_currentState = _lastState = _idleState;
}

// Called every frame
void USimpleStateMachine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	_currentState = _currentState->OnUpdate(DeltaTime);

	if (_currentState != _lastState) 
	{
		_lastState->OnExit();
		_currentState->OnEnter();
		_lastState = _currentState;
	}
	// ...
}

