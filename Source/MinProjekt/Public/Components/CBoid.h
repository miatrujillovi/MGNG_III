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
	FVector Flee(FVector MyPosition, FVector TargetPosition, float Impetu);

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
};
