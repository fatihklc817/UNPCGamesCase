// Fill out your copyright notice in the Description page of Project Settings.


#include "Ai/My_BTTaskDestroyAiActor.h"

EBTNodeResult::Type UMy_BTTaskDestroyAiActor::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	auto OwningActor = Cast<AController>(OwnerComp.GetOwner())->GetPawn();

	if (OwningActor)
	{
		OwningActor->Destroy();	
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
