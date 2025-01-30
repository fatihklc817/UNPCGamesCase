// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "My_BTTask_SelectRandomArea.generated.h"

/**
 * 
 */
UCLASS()
class UNPCGAMESCASE_API UMy_BTTask_SelectRandomArea : public UBTTaskNode
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Ai")
	FBlackboardKeySelector SelectedAreaKey;
	
	UPROPERTY(EditAnywhere, Category="Ai")
	FBlackboardKeySelector AreaLocationKey;

	UPROPERTY(EditAnywhere, Category="Ai")
	FBlackboardKeySelector SpawnLocationKey;

	UPROPERTY(EditAnywhere, Category="Ai")
	FBlackboardKeySelector IsAreaSelectedKey;
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
