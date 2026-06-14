// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CBoid.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MINPROJEKT_API UCBoid : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable)
	FVector Seek(FVector MyPosition, FVector TargetPosition, float Impetu);

	UFUNCTION(BlueprintCallable)
	FVector SeekRadius(FVector MyPosition, FVector TargetPosition, float Radius, float Impetu);

	UFUNCTION(BlueprintCallable)
	FVector Flee(FVector MyPosition, FVector TargetPosition, float Impetu);

	UFUNCTION(BlueprintCallable)
	FVector FleeRadius(FVector MyPosition, FVector TargetPosition, float Radius,  float Impetu);

	UFUNCTION(BlueprintCallable)
	FVector Arrive(FVector MyPosition, FVector TargetPosition, float TargetRadius, float MaxSpeed);

	UFUNCTION(BlueprintCallable)
	FVector FollowPath(FVector MyPosition, TArray<AActor*> PathPoints, float TargetRadius, float MaxSpeed, float Impetu);

	UFUNCTION(BlueprintCallable)
	void Inertia(float deltaSeconds);

	UFUNCTION(BlueprintCallable)
	void SetForces(FVector NewForces);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Seek")
	AActor* SeekTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Seek")
	float SeekImpetu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flee")
	AActor* FleeTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flee")
	float FleeImpetu;

	UPROPERTY(BlueprintReadOnly)
	FVector Forces;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inertia")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inertia")
	FVector OldForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inertia")
	float Mass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrive")
	AActor* ArriveTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrive")
	float ArriveTargetRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrive")
	float ArriveMaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Follow Path")
	TArray<AActor*> FollowPathTargets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Follow Path")
	float FollowPathTargetRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Follow Path")
	float FollowPathMaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Follow Path")
	float FollowPathImpetu;

	bool bPathCompleted = false;

	UPROPERTY()
	int32 CurrentIndex = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Seek Radius")
	AActor* SeekRadiusTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Seek Radius")
	float SeekRadiusImpetu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Seek Radius")
	float SeekRadiusRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flee Radius")
	AActor* FleeRadiusTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flee Radius")
	float FleeRadiusImpetu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flee Radius")
	float FleeRadiusRadius;
};
