// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputActionValue.h"
#include "SimpleMoveActor.generated.h"

//Forward declaration: Adelantarle al codigo que va a existir algo. Tambien funciona con clases
//void FutureFunction();
class UInputAction;
class UInputMappingContext;
class UInputComponent;
class UCameraComponent;

UCLASS()
class MINPROJEKT_API ASimpleMoveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASimpleMoveActor();

	virtual void Tick(float deltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SetUpInputComponent();

	//Punteros de Unreal: Apunta a objetos especificos de Unreal y lo controla Unreal (No es necesario eliminarlo ya que lo hace Unreal)
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> _context;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> _moveAction;


public:	
	UPROPERTY(EditAnywhere, Category = "Input")
	float _speed = 100;

	//El parametro esta pidiendole al pointer que traiga el valor original al que apunta. El const evita que lo "modifiquemos" y generemos un error.
	void Move(const FInputActionValue& actionValue);
};
