// Fill out your copyright notice in the Description page of Project Settings.


#include "Ai/MyB_TTaskSetIsAreaBusy.h"

#include "My_NpcAreas.h"
#include "Ai/My_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UMyB_TTaskSetIsAreaBusy::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	//this classs iss wronnnggg UNUSED !!!


	
	auto OwningActor = Cast<AMy_AIController>(OwnerComp.GetOwner())->GetPawn();
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp->GetValueAsInt(QueueIndexKey.SelectedKeyName) == 0)
	{
		Cast<AMy_NpcAreas>(BlackboardComp->GetValueAsObject(SelectedAreaKey.SelectedKeyName))->ACustomerArrivedToInside(OwningActor);
		
	}
	
	return EBTNodeResult::Succeeded;
}
