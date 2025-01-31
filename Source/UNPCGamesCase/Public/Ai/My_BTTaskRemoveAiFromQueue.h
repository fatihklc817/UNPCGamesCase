// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "My_BTTaskRemoveAiFromQueue.generated.h"

/**
 * 
 */
UCLASS()
class UNPCGAMESCASE_API UMy_BTTaskRemoveAiFromQueue : public UBTTaskNode
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector SelectedAreaKey;

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector QueueIndexKey;
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
