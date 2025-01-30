// Fill out your copyright notice in the Description page of Project Settings.


#include "Ai/My_BTTaskProcessTheTask.h"

#include "My_NpcAreas.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UMy_BTTaskProcessTheTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();

	auto SelectedArea =Cast<AMy_NpcAreas>(BlackboardComponent->GetValueAsObject(SelectedAreaKey.SelectedKeyName));
	if (SelectedArea)
	{
		SelectedArea->CurrentCustomerDoneItsTask();
	}
	
	return EBTNodeResult::Succeeded;
	
	
}
