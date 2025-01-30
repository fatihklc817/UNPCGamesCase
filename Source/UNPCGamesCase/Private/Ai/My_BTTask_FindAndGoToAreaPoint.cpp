// Fill out your copyright notice in the Description page of Project Settings.


#include "Ai/My_BTTask_FindAndGoToAreaPoint.h"

#include "My_NpcAreas.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/ArrowComponent.h"


EBTNodeResult::Type UMy_BTTask_FindAndGoToAreaPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

		UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	
		auto SelectedArea = Cast<AMy_NpcAreas>(BlackboardComponent->GetValueAsObject(SelectedAreaKey.SelectedKeyName));

		if (!ensure(SelectedArea)) return EBTNodeResult::Failed;
		
		if (!SelectedArea->GetIsAreaBusy())
		{
			
			BlackboardComponent->SetValueAsVector(MoveToLocationKey.SelectedKeyName, SelectedArea -> GetCustomerStandPoint()->GetComponentLocation());
			SelectedArea->ACustomerArrived(OwnerComp.GetOwner());
			return EBTNodeResult::Succeeded;
		}
		else
		{
			FVector test = SelectedArea -> GetCustomerStandPoint()->GetComponentLocation() + SelectedArea->GetCustomerStandPoint()->GetForwardVector() * -200 * SelectedArea->GetNumOfCustomersInQueue();
			UE_LOG(LogTemp, Warning, TEXT("masa doluuuuuu seçilen locasyon %s"),*test.ToString());
			UE_LOG(LogTemp, Warning, TEXT("queue size  %d"),SelectedArea->GetNumOfCustomersInQueue());
			BlackboardComponent->SetValueAsVector(MoveToLocationKey.SelectedKeyName, test);
			if (SelectedArea->GetNumOfCustomersInQueue() == 0)
			{
				SelectedArea->ACustomerArrived(OwnerComp.GetOwner());
			}
			return EBTNodeResult::Succeeded;
		}
		
	
	
	return EBTNodeResult::Failed;

	
}
