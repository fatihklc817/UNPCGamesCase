// Fill out your copyright notice in the Description page of Project Settings.


#include "Ai/My_AIController.h"

#include "BehaviorTree/BlackboardComponent.h"


void AMy_AIController::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(BehaviorTree);
	
	
	
	
	
}

UBehaviorTree* AMy_AIController::GetBehaviourTree()
{
	return BehaviorTree;
}
