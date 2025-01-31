// Fill out your copyright notice in the Description page of Project Settings.


#include "Ai/My_BTTaskProcessTheTask.h"

#include "My_NpcAreas.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UMy_BTTaskProcessTheTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	auto OwningActor = Cast<AController>(OwnerComp.GetOwner())->GetPawn();
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();

	auto SelectedArea =Cast<AMy_NpcAreas>(BlackboardComponent->GetValueAsObject(SelectedAreaKey.SelectedKeyName));
	if (SelectedArea)
	{
		if (SelectedArea->Implements<UMy_InteractInterface>())
		{
			IMy_InteractInterface* InteractInterface = Cast<IMy_InteractInterface>(SelectedArea);
			InteractInterface->Interact(OwningActor);
			BlackboardComponent->SetValueAsBool(bIstTheTaskDoneKey.SelectedKeyName,true);
		}
	}
	
	return EBTNodeResult::Succeeded;
	
	
}
