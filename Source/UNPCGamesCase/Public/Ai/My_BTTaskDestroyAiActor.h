// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "My_BTTaskDestroyAiActor.generated.h"

/**
 * 
 */
UCLASS()
class UNPCGAMESCASE_API UMy_BTTaskDestroyAiActor : public UBTTaskNode
{
	GENERATED_BODY()

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
