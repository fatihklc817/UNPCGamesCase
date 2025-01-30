// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/My_MainGameMode.h"

#include "AIController.h"
#include "My_NpcAreas.h"
#include "Ai/My_AICharacter.h"
#include "Ai/My_AIController.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"


AMy_MainGameMode::AMy_MainGameMode()
{
	NpcAreasClass = AMy_NpcAreas::StaticClass();
}

void AMy_MainGameMode::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(this,NpcAreasClass,NpcAreas);
	
	//auto SpawnedPawn = GetWorld()->SpawnActor<AMy_AICharacter>(AiClass,FVector(0,0,200),FRotator::ZeroRotator);
	//UE_LOG(LogTemp, Warning, TEXT("spawned actor %s"),*SpawnedPawn->GetName());


	
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_AiSPawn,
			[this]()
			{
				auto SpawnedActor = GetWorld()->SpawnActor<AActor>(AiClass,FVector(0,0,0),FRotator::ZeroRotator);
			},
			FMath::RandRange(SpawnAiSecondRange_MinValue,SpawnAiSecondRange_MaxValue),
			true,
			5);
	
}
TArray<AActor*> AMy_MainGameMode::GetNpcAreas()
{
	return NpcAreas;
}
