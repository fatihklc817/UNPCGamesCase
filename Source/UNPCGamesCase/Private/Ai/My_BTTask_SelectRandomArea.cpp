// Fill out your copyright notice in the Description page of Project Settings.


#include "Ai/My_BTTask_SelectRandomArea.h"

#include "My_NpcAreas.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/ArrowComponent.h"
#include "GameModes/My_MainGameMode.h"
#include "Kismet/GameplayStatics.h"

EBTNodeResult::Type UMy_BTTask_SelectRandomArea::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	BlackboardComponent->SetValueAsVector(SpawnLocationKey.SelectedKeyName,FVector::ZeroVector);
	UE_LOG(LogTemp, Warning, TEXT("spawn location setlendi %s"),*BlackboardComponent->GetValueAsVector(SpawnLocationKey.SelectedKeyName).ToString());  //log
	
	AMy_MainGameMode* MyGameMode =Cast<AMy_MainGameMode>(UGameplayStatics::GetGameMode(this));

	if (MyGameMode)
	{
		int32 RandomIndex = FMath::RandRange(0,MyGameMode->GetNpcAreas().Num()-1);								//select a random npc area 
		AMy_NpcAreas* SelectedArea = Cast<AMy_NpcAreas>(MyGameMode->GetNpcAreas()[RandomIndex]);

		if (SelectedArea)
		{
			BlackboardComponent->SetValueAsObject(SelectedAreaKey.SelectedKeyName,SelectedArea);						//assign it to blackboard data
			BlackboardComponent->SetValueAsBool(IsAreaSelectedKey.SelectedKeyName,true);
			
			UE_LOG(LogTemp, Warning, TEXT("selected area is setlendi : %s "),*SelectedArea->GetName());			//log
			
			BlackboardComponent->SetValueAsVector(AreaLocationKey.SelectedKeyName,SelectedArea->GetCustomerStandPoint()->GetComponentLocation());		
			return EBTNodeResult::Succeeded;
		}
		
		return EBTNodeResult::Failed;
		
	}
	
	return EBTNodeResult::Failed;
}
