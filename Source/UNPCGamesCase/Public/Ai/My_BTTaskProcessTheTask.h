// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "My_BTTaskProcessTheTask.generated.h"

/**
 * 
 */
UCLASS()
class UNPCGAMESCASE_API UMy_BTTaskProcessTheTask : public UBTTaskNode
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,Category="Ai")
	FBlackboardKeySelector SelectedAreaKey;

	UPROPERTY(EditAnywhere,Category="Ai")
	FBlackboardKeySelector bIstTheTaskDoneKey;
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
