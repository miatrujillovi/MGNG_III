// Fill out your copyright notice in the Description page of Project Settings.


#include "CAudioManager.h"
#include <Sound/SoundBase.h>
#include <Components/AudioComponent.h>
#include <Kismet/GameplayStatics.h>
#include "MinProjekt/CSaveAudioSettings.h"

void UCAudioManager::Initialize(FSubsystemCollectionBase& collection)
{
	Super::Initialize(collection);

	LoadSettings();
}

void UCAudioManager::Deinitialize()
{
	Super::Deinitialize();
}

void UCAudioManager::PlayMusic(USoundBase* _sound, bool _loop, float _pitch)
{
	if (!_sound || !GetGameInstance()) return;

	if (!audioComponent) 
	{
		audioComponent = UGameplayStatics::SpawnSound2D(GetGameInstance(), 
																_sound, 
																mainVolume * musicVolume, 
																_pitch,
																0.0f,
																nullptr,
																_loop,
																false);
	}
	else 
	{
		audioComponent->SetSound(_sound);
		audioComponent->SetVolumeMultiplier(mainVolume * musicVolume);
		audioComponent->SetPitchMultiplier(_pitch);
		audioComponent->Play();
	}
}

void UCAudioManager::ChangeMusic(USoundBase* _sound)
{
	if (!_sound || !GetGameInstance()) return;

	if (audioComponent)
	{
		audioComponent->SetSound(_sound);
		audioComponent->Play();
	}
}

void UCAudioManager::PlaySFX(USoundBase* _sound, float _pitch)
{
	if (!_sound || !GetGameInstance()) return;

	UGameplayStatics::PlaySound2D(GetGameInstance(),
									_sound,
									mainVolume * sfxVolume,
									_pitch);
}

void UCAudioManager::SetMainVolume(float _volume)
{
	mainVolume = FMath::Clamp(_volume, 0.0f, 1.0f);
	mainVolume = _volume;
	SaveSettings();

	if (audioComponent) 
	{
		audioComponent->SetVolumeMultiplier(mainVolume * musicVolume);
	}
}

void UCAudioManager::SetMusicVolume(float _volume)
{
	musicVolume = FMath::Clamp(_volume, 0.0f, 1.0f);
	musicVolume = _volume;
	SaveSettings();

	if (audioComponent)
	{
		audioComponent->SetVolumeMultiplier(mainVolume * musicVolume);
	}
}

void UCAudioManager::SetSFXVolume(float _volume)
{
	sfxVolume = FMath::Clamp(_volume, 0.0f, 1.0f);
	sfxVolume = _volume;
	SaveSettings();
}

void UCAudioManager::LoadSettings()
{
	if (UGameplayStatics::DoesSaveGameExist("CAudioSettings", 0)) 
	{
		UCSaveAudioSettings* save = Cast<UCSaveAudioSettings>(UGameplayStatics::LoadGameFromSlot("CAudioSettings", 0));

		if (save) 
		{
			mainVolume = save->mainVolume;
			musicVolume = save->musicVolume;
			sfxVolume = save->sfxVolume;

			if (audioComponent)
			{
				audioComponent->SetVolumeMultiplier(mainVolume * musicVolume);
			}
		}
	}
	else 
	{
		SaveSettings();
	}
}

void UCAudioManager::SaveSettings()
{
	UCSaveAudioSettings* save = Cast<UCSaveAudioSettings>(UGameplayStatics::CreateSaveGameObject(UCSaveAudioSettings::StaticClass()));

	if (save) 
	{
		save->mainVolume = mainVolume;
		save->musicVolume = musicVolume;
		save->sfxVolume = sfxVolume;
		UGameplayStatics::SaveGameToSlot(save, "CAudioSettings", 0);
	}
}
