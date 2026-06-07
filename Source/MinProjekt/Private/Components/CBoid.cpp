// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CBoid.h"
#include "Math/UnrealMathUtility.h"

FVector UCBoid::Seek(FVector MyPosition, FVector TargetPosition, float Impetu)
{
	FVector movePosition = TargetPosition - MyPosition;
	movePosition.Normalize(0.0001);

	FVector Force = movePosition * Impetu;

	//INERTIA
	Forces = Force + Forces;

	return Force;
}

FVector UCBoid::Flee(FVector MyPosition, FVector TargetPosition, float Impetu)
{
	FVector Force = Seek(MyPosition, TargetPosition, Impetu);

	Force = Force * -1;

	//INERTIA
	Forces = Force + Forces;

	return Force;
}

void UCBoid::Inertia(float deltaSeconds)
{
	FVector inertia = FMath::Lerp(Forces, OldForce, Mass);
	OldForce = inertia;
	inertia.Normalize(0.0001);

	float InertiaSpeed = Speed * deltaSeconds;

	FVector DeltaLocation = inertia * InertiaSpeed;

	//Move the Actor
	AActor* Owner = GetOwner();

	if (Owner) 
	{
		Owner->AddActorWorldOffset(DeltaLocation);
	}
}

void UCBoid::SetForces(FVector NewForces)
{
	Forces = NewForces;
}

