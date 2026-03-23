// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleMoveActor.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <GameFramework/PlayerController.h>
#include <Engine/World.h>

// Sets default values
ASimpleMoveActor::ASimpleMoveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASimpleMoveActor::BeginPlay()
{
	Super::BeginPlay();
	SetUpInputComponent();
}

//Agregarle el mapping context al player controller
void ASimpleMoveActor::SetUpInputComponent()
{
	UE_LOG(LogTemp, Warning, TEXT("Binding Action"));
	//1. Obtener el Player Controller
	APlayerController* playerController = GetWorld()->GetFirstPlayerController();
	if (!playerController) {

		UE_LOG(LogTemp, Warning, TEXT("No controller Found"));
		return;
	}

	//2. Obtener el controller 0 de forma local
	ULocalPlayer* localPlayer = playerController->GetLocalPlayer();
	if (localPlayer) 
	{
		//3. Obtener el system de input de ese especifico controller
		UEnhancedInputLocalPlayerSubsystem* inputSubsystem = localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

		if (inputSubsystem != nullptr && _context != nullptr) 
		{
			//inputSubsystem->ClearAllMappings(); // Borra todos los mapping context

			//4. Si no tiene el mapping context, lo agrega.
			if (!inputSubsystem->HasMappingContext(_context)) 
			{
				inputSubsystem->AddMappingContext(_context,1);

				UE_LOG(LogTemp, Warning, TEXT("Including Context"));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Alredy Included Context"));
			}
		}
	}

	EnableInput(playerController); //Activando los inputs del actor
	UEnhancedInputComponent* inComponent = Cast<UEnhancedInputComponent>(InputComponent); //Obtener el enhanced input que todos los actores tienen

	if (inComponent != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("InComponent Found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("InComponent No Found"));
	}
	//Si se tiene el input correspondiente, hacer el bind con el componente
	if (_moveAction && inComponent != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Binding Action"));
		inComponent->BindAction(_moveAction,  //Input para hacer el bind
								ETriggerEvent::Triggered, //El tipo trigger
								this, //El actor que va a estar escuchando
								&ASimpleMoveActor::Move); //La funcion que se va a llamar cuando se active el input
	}

}

void ASimpleMoveActor::Move(const FInputActionValue& actionValue)
{

	UE_LOG(LogTemp, Warning, TEXT("Moving"));
	//bool pressing = actionValue.Get<bool>(); //Simple Button or Action
	FVector2D moveValue = actionValue.Get<FVector2D>();
	FVector moveVector = FVector::ZeroVector;

	moveValue *= _speed;

	moveVector.X = moveValue.X;
	moveVector.Y = moveValue.Y;
	AddActorWorldOffset(moveVector, true);
}

// Called every frame
void ASimpleMoveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

