// Fill out your copyright notice in the Description page of Project Settings.


#include "Ai/My_BTTaskRemoveAiFromQueue.h"

#include "My_NpcAreas.h"
#include "Ai/My_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UMy_BTTaskRemoveAiFromQueue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	auto OwningActor = Cast<AController>(OwnerComp.GetOwner())->GetPawn();
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();

	auto SelectedArea =Cast<AMy_NpcAreas>( BlackboardComp->GetValueAsObject(SelectedAreaKey.SelectedKeyName));

	if (SelectedArea->GetCustomersQueueArray().Contains(OwningActor))
	{
		SelectedArea->GetCustomersQueueArray().Remove(OwningActor);
		UE_LOG(LogTemp, Warning, TEXT("*********actor çıkarıldı kalan aktor sayısı %d"),SelectedArea->GetNumOfCustomersInQueue());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("************ actor listede yok kiii çıkarılamadııı"));
	}
	
	SelectedArea->SetIsAreaBusy(false);
	
	for (auto AIActor : SelectedArea->GetCustomersQueueArray())
	{
		auto AiActorBlackboardComp = Cast<AMy_AIController>(AIActor->GetController())->GetBlackboardComponent();
		auto index = AiActorBlackboardComp->GetValueAsInt(QueueIndexKey.SelectedKeyName);
		AiActorBlackboardComp->SetValueAsInt(QueueIndexKey.SelectedKeyName,index -1);
	}
	
	
	return EBTNodeResult::Succeeded;
	
}
