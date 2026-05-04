// Fill out your copyright notice in the Description page of Project Settings.


#include "CMyGameInstance.h"
#include "../CAudioManager.h"
#include "CRespawnManager.h"
#include "../Data/CAudioLibrary.h"
#include "../Data/CRespawnLibrary.h"

void UCMyGameInstance::Init()
{
	Super::Init();

	UCAudioManager* audio = UGameInstance::GetSubsystem<UCAudioManager>(this);
	if (audio) 
	{
		UCAudioLibrary* library = Library.IsNull() ? nullptr : Library.LoadSynchronous();
		audio->SetAudioLibrary(library);
	}

	UCRespawnManager* respawn = UGameInstance::GetSubsystem<UCRespawnManager>(this);
	if (respawn)
	{
		UCRespawnLibrary* RespawnLibrary = respawnLibrary.IsNull() ? nullptr : respawnLibrary.LoadSynchronous();
		respawn->SetRespawnLibrary(RespawnLibrary);
	}
}

void UCMyGameInstance::OnStart()
{
	Super::OnStart();


}
