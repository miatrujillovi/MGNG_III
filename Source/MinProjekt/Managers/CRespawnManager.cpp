// Fill out your copyright notice in the Description page of Project Settings.


#include "CRespawnManager.h"
#include "../Data/CRespawnLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"

void UCRespawnManager::RespawnPlayer(FName _idLocation) 
{
	if (respawnLibrary)
	{
		for (const auto& entry: respawnLibrary->RespawnPoints)
		{
			if (entry.ID == _idLocation)
			{
				APlayerController* pC = UGameplayStatics::GetPlayerController(GetWorld(), 0);

				if (!pC) return;

				APawn* playerPawn = pC->GetPawn();

				if (playerPawn) 
				{
					playerPawn->SetActorLocationAndRotation(entry.Location, entry.Rotation);
				}
				return;
			}
		}
	}
}

void UCRespawnManager::SetRespawnLibrary(UCRespawnLibrary* _respawnLibrary)
{
	respawnLibrary = _respawnLibrary;

	if (respawnLibrary)
	{
		UE_LOG(LogTemp, Log, TEXT("Respawn Library Set"));
	}
	else 
	{
		UE_LOG(LogTemp, Log, TEXT("Respawn Library failed to Set"));
	}
}

