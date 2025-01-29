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
	TArray<AActor*> NpcAreas;

	UPROPERTY()
	TSubclassOf<class AMy_NpcAreas> NpcAreasClass;

public:
	AMy_MainGameMode();
	
protected:
	virtual void BeginPlay() override;

public:
	TArray<AActor*> GetNpcAreas();

	
};
