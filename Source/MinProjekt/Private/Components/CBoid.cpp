// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CBoid.h"
#include "Math/UnrealMathUtility.h"
#include "Managers/CCoinsManager.h"
#include <Kismet/GameplayStatics.h>

FVector UCBoid::Seek(FVector MyPosition, FVector TargetPosition, float Impetu)
{
	FVector movePosition = TargetPosition - MyPosition;
	movePosition.Normalize(0.0001);

	FVector Force = movePosition * Impetu;

	//INERTIA
	Forces = Force;

	return Force;
}

FVector UCBoid::SeekRadius(FVector MyPosition, FVector TargetPosition, float Radius, float Impetu)
{
	//1.- Get current Distance
	float Distance = FVector::Dist(MyPosition, TargetPosition);

	//2.- If distance is on radius, dont move.
	if (Distance < Radius)
	{
		return FVector::ZeroVector;
	}

	//3.- Calculate direction.
	FVector Direction = (TargetPosition - MyPosition).GetSafeNormal();

	FVector Force = Direction * Impetu;

	//INERTIA
	Forces = Force;

	return Force;
}

FVector UCBoid::Flee(FVector MyPosition, FVector TargetPosition, float Impetu)
{
	FVector Direction = (MyPosition - TargetPosition).GetSafeNormal();

	FVector Force = Direction * Impetu;

	//INERTIA
	Forces = Force;

	return Force;
}

FVector UCBoid::FleeRadius(FVector MyPosition, FVector TargetPosition, float Radius, float Impetu)
{
	//1.- Get current Distance
	float Distance = FVector::Dist(MyPosition, TargetPosition);

	//2.- If distance is on radius, dont move.
	if (Distance > Radius)
	{
		return FVector::ZeroVector;
	}

	//3.- Calculate direction.
	FVector Direction = (MyPosition - TargetPosition).GetSafeNormal();

	FVector Force = Direction * Impetu;

	//INERTIA
	Forces = Force;

	return Force;
}

FVector UCBoid::Arrive(FVector MyPosition, FVector TargetPosition, float TargetRadius, float MaxSpeed)
{
	//1.- Direction to Target
	FVector ToTarget = TargetPosition - MyPosition;

	//2.- Distance
	float Distance = ToTarget.Size();

	//3.- Check Arrival
	if (Distance < KINDA_SMALL_NUMBER)
	{
		return FVector::ZeroVector;
	}

	//4.- Normalize Vector
	FVector Direction = ToTarget.GetSafeNormal();

	float DesiredSpeed;

	//5.- If inside radius, it slows down gradually
	if (Distance > TargetRadius)
	{
		DesiredSpeed = MaxSpeed;
	}
	else 
	{
		DesiredSpeed = MaxSpeed * (Distance / TargetRadius);
	}

	//INERTIA
	Forces = Direction * DesiredSpeed;

	return Forces;
}

FVector UCBoid::FollowPath(FVector MyPosition, TArray<AActor*> PathPoints, float TargetRadius, float MaxSpeed, float Impetu)
{
	if (PathPoints.Num() == 0)
	{
		return FVector::ZeroVector;
	}

	//1.- Gets index of all elements in Array
	CurrentIndex = FMath::Clamp(CurrentIndex, 0, PathPoints.Num() - 1);

	//2.- Selects the next point in the path.
	FVector Target = PathPoints[CurrentIndex]->GetActorLocation();

	//3.- Gets the Distance to the next Point
	float Distance = FVector::Dist(MyPosition, Target);

	//4.- If it arrives to the radius of the point, change target.
	if (Distance < TargetRadius) 
	{
		CurrentIndex++;

		CurrentIndex = FMath::Clamp(CurrentIndex, 0, PathPoints.Num() - 1);
	}

	//5.- Bool to detect if we're on the last point.
	bool bFinalIndex = (CurrentIndex == PathPoints.Num() - 1);

	//6.- If on last point, use arrive. Otherwise, use Seek to reach point
	if (bFinalIndex) 
	{
		float DistanceToFinal = FVector::Dist(MyPosition, PathPoints[CurrentIndex]->GetActorLocation());

		//7.- If it reaches the final destination. Add a Coin.
		if (DistanceToFinal < TargetRadius)
		{
			UCCoinsManager* CoinsManager = GetWorld()->GetGameInstance()->GetSubsystem<UCCoinsManager>();

			if (CoinsManager)
			{
				CoinsManager->AddCoins(1);

				/*if (AActor* Owner = GetOwner())
				{
					Owner->SetLifeSpan(0.01f);
				}*/
			}

			return FVector::ZeroVector;
		}

		return Arrive(MyPosition, PathPoints[CurrentIndex]->GetActorLocation(), TargetRadius, MaxSpeed);
	}

	return Seek(MyPosition, PathPoints[CurrentIndex]->GetActorLocation(), Impetu);
}

void UCBoid::Inertia(float deltaSeconds)
{
	FVector InertiaForce = FMath::Lerp(OldForce, Forces, deltaSeconds * Mass);

	OldForce = InertiaForce;

	FVector DeltaLocation = InertiaForce * deltaSeconds;

	if (AActor* Owner = GetOwner())
	{
		Owner->AddActorWorldOffset(DeltaLocation);
	}
}

void UCBoid::SetForces(FVector NewForces)
{
	Forces = NewForces;
}

