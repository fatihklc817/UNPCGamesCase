// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/My_MainGameMode.h"

#include "My_NpcAreas.h"
#include "Kismet/GameplayStatics.h"


AMy_MainGameMode::AMy_MainGameMode()
{
	NpcAreasClass = AMy_NpcAreas::StaticClass();
}

void AMy_MainGameMode::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(this,NpcAreasClass,NpcAreas);
	
	for (auto npcAreaActor : NpcAreas)
	{
		//UE_LOG(LogTemp, Warning, TEXT("npc area %s"), *npcAreaActor->GetName());
	}
}

TArray<AActor*> AMy_MainGameMode::GetNpcAreas()
{
	return NpcAreas;
}
