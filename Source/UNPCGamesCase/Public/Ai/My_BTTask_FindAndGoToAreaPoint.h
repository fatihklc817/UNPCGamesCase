// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "My_BTTask_FindAndGoToAreaPoint.generated.h"

/**
 * 
 */
UCLASS()
class UNPCGAMESCASE_API UMy_BTTask_FindAndGoToAreaPoint : public UBTTaskNode
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector SelectedAreaKey;

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector MoveToLocationKey;

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector QueueIndexKey;

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector bIsIndexSettedKey;
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
