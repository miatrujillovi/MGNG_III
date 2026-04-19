// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CAudioManager.generated.h"

class USoundBase;
class UAudioComponent;

UCLASS()
class MINPROJEKT_API UCAudioManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:	
	virtual void Initialize(FSubsystemCollectionBase& collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable)
	void PlayMusic(USoundBase* _sound, bool _loop = true, float _pitch = 1.0f);

	UFUNCTION(BlueprintCallable)
	void ChangeMusic(USoundBase* _sound);

	UFUNCTION(BlueprintCallable)
	void PlaySFX(USoundBase* _sound, float _pitch = 1.0f);

	UFUNCTION(BlueprintCallable)
	void SetMainVolume(float _volume);

	UFUNCTION(BlueprintCallable)
	void SetMusicVolume(float _volume);

	UFUNCTION(BlueprintCallable)
	void SetSFXVolume(float _volume);

	UFUNCTION(BlueprintCallable)
	float GetMainVolume() const { return mainVolume; }

	UFUNCTION(BlueprintCallable)
	float GetMusicVolume() const { return musicVolume; }

	UFUNCTION(BlueprintCallable)
	float GetSFXVolume() const { return sfxVolume; }

	void LoadSettings();
	void SaveSettings();

private:

	float mainVolume = 1;
	float musicVolume = 1;
	float sfxVolume = 1;

	UPROPERTY()
	TObjectPtr<UAudioComponent> audioComponent;
};
