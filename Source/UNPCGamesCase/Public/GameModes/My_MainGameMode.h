// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "My_MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UNPCGAMESCASE_API AMy_MainGameMode : public AGameModeBase
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<AActor*> NpcAreas;																							//to storage all the npc areas in the level

	UPROPERTY()
	TSubclassOf<class AMy_NpcAreas> NpcAreasClass;																		//npc area class to find them

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AMy_AICharacter> AiClass;																			//ai class to spawn 

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<class AMy_BaseIncteractableNpc>> NpcClasses;														//npc classes to spawn


	
	FTimerHandle TimerHandle_AiSPawn;
	FTimerHandle TimerHandle_NpcPawn;				

	UPROPERTY(EditDefaultsOnly)
	float SpawnAiSecondRange_MinValue;																					//the min value for AI spawning second range 
	
	UPROPERTY(EditDefaultsOnly)
	float SpawnAiSecondRange_MaxValue;																					//the max value for AI spawning second range

public:
	AMy_MainGameMode();
	
protected:
	virtual void BeginPlay() override;

public:
	TArray<AActor*> GetNpcAreas();

	
};
