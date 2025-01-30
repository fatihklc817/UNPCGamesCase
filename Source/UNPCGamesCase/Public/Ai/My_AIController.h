// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "My_AIController.generated.h"

/**
 * 
 */
UCLASS()
class UNPCGAMESCASE_API AMy_AIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere , Category="AI")
	UBehaviorTree* BehaviorTree;
	
	
	virtual void BeginPlay() override;

	
public:
	UBehaviorTree* GetBehaviourTree();
};
