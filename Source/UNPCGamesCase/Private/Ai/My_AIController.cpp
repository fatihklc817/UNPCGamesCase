// Fill out your copyright notice in the Description page of Project Settings.


#include "Ai/My_AIController.h"

#include "My_NpcAreas.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/ArrowComponent.h"
#include "GameModes/My_MainGameMode.h"
#include "Kismet/GameplayStatics.h"

void AMy_AIController::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(BehaviorTree);
	

	AMy_MainGameMode* MyGameMode =Cast<AMy_MainGameMode>(UGameplayStatics::GetGameMode(this));
	
	if (MyGameMode)
	{
		int32 RandomIndex = FMath::RandRange(0,MyGameMode->GetNpcAreas().Num()-1);								//select a random npc area 
		AMy_NpcAreas* SelectedArea = Cast<AMy_NpcAreas>(MyGameMode->GetNpcAreas()[RandomIndex]);
		
		if (!SelectedArea->GetIsAreaBusy())
		{
			GetBlackboardComponent()->SetValueAsVector("MoveToLocation", SelectedArea -> GetCustomerStandPoint()->GetComponentLocation());
			SelectedArea->ACustomerArrived(this);
		}
		else
		{
			FVector test = SelectedArea -> GetCustomerStandPoint()->GetComponentLocation() + SelectedArea->GetCustomerStandPoint()->GetForwardVector() * -160 * SelectedArea->GetNumOfCustomersInQueue();
			UE_LOG(LogTemp, Warning, TEXT("masa doluuuuuu seçilen locasyon %s"),*test.ToString());
			UE_LOG(LogTemp, Warning, TEXT("queue size  %d"),SelectedArea->GetNumOfCustomersInQueue());
			GetBlackboardComponent()->SetValueAsVector("MoveToLocation", test);
		}
		
	}
	
	
	
}

UBehaviorTree* AMy_AIController::GetBehaviourTree()
{
	return BehaviorTree;
}
