// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SimpleStateMachine.generated.h"

class BaseState;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MINPROJEKT_API USimpleStateMachine : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USimpleStateMachine();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	TSharedPtr<BaseState> _currentState;
	TSharedPtr<BaseState> _lastState;

	void InitializeState();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	TSharedPtr<BaseState> _idleState;
	TSharedPtr<BaseState> _wanderState;
};
