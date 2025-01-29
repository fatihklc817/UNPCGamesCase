// Fill out your copyright notice in the Description page of Project Settings.


#include "Ai/My_AIController.h"

#include "My_NpcAreas.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameModes/My_MainGameMode.h"
#include "Kismet/GameplayStatics.h"

void AMy_AIController::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(BehaviorTree);

	APawn* MyPawn = UGameplayStatics::GetPlayerPawn(this,0);

	AMy_MainGameMode* MyGameMode =Cast<AMy_MainGameMode>(UGameplayStatics::GetGameMode(this));
	
	if (MyGameMode)
	{
		UE_LOG(LogTemp, Warning, TEXT("my game mode alındı hacı dayı"));
		
		int32 RandomIndex = FMath::RandRange(0,MyGameMode->GetNpcAreas().Num()-1);
		UE_LOG(LogTemp, Warning, TEXT("random int im seçildi dayı %d"),RandomIndex);
		
		AMy_NpcAreas* SelectedArea = Cast<AMy_NpcAreas>(MyGameMode->GetNpcAreas()[RandomIndex]);

		for (auto npcAreaActor : MyGameMode->GetNpcAreas())
		{
			UE_LOG(LogTemp, Warning, TEXT("npc area %s"), *npcAreaActor->GetName());
		}

		UE_LOG(LogTemp, Warning, TEXT("seçilen locasyon %s"),*SelectedArea->GetCustomerStandPoint().GetLocation().ToString());
		GetBlackboardComponent()->SetValueAsVector("MoveToLocation", SelectedArea -> GetCustomerStandPoint().GetLocation());
		
	}
	
	
	
}
