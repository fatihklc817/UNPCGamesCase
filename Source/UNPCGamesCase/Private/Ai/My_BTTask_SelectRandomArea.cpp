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

	auto OwningActor = Cast<AController>(OwnerComp.GetOwner())->GetPawn();

	BlackboardComponent->SetValueAsInt(QueueIndexKey.SelectedKeyName,9999);
	BlackboardComponent->SetValueAsVector(SpawnLocationKey.SelectedKeyName,OwningActor->GetActorLocation());
	
	
	AMy_MainGameMode* MyGameMode =Cast<AMy_MainGameMode>(UGameplayStatics::GetGameMode(this));

	if (MyGameMode)
	{
		int32 RandomIndex = FMath::RandRange(0,MyGameMode->GetNpcAreas().Num()-1);								//select a random npc area 
		AMy_NpcAreas* SelectedArea = Cast<AMy_NpcAreas>(MyGameMode->GetNpcAreas()[RandomIndex]);

		if (SelectedArea)
		{
			BlackboardComponent->SetValueAsObject(SelectedAreaKey.SelectedKeyName,SelectedArea);						//assign it to blackboard data
			BlackboardComponent->SetValueAsBool(IsAreaSelectedKey.SelectedKeyName,true);
			
			
			
			BlackboardComponent->SetValueAsVector(AreaLocationKey.SelectedKeyName,SelectedArea->GetCustomerStandPoint()->GetComponentLocation());
			
			return EBTNodeResult::Succeeded;
		}
		
		return EBTNodeResult::Failed;
		
	}
	
	return EBTNodeResult::Failed;
}
