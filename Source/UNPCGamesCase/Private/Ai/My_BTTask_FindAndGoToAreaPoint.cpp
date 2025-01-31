// Fill out your copyright notice in the Description page of Project Settings.


#include "Ai/My_BTTask_FindAndGoToAreaPoint.h"

#include "My_NpcAreas.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/ArrowComponent.h"


EBTNodeResult::Type UMy_BTTask_FindAndGoToAreaPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

		UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
		auto OwningActor = Cast<AController>(OwnerComp.GetOwner())->GetPawn();
	
		auto SelectedArea = Cast<AMy_NpcAreas>(BlackboardComponent->GetValueAsObject(SelectedAreaKey.SelectedKeyName));

		if (!ensure(SelectedArea)) return EBTNodeResult::Failed;

		if (SelectedArea->GetCustomersQueueArray().Num() == 0)
		{
			BlackboardComponent->SetValueAsInt(QueueIndexKey.SelectedKeyName, 0);
		}
	
		if (!SelectedArea->GetIsAreaBusy() && BlackboardComponent->GetValueAsInt(QueueIndexKey.SelectedKeyName) == 0)
		{
			if (!SelectedArea->GetCustomersQueueArray().Contains(OwningActor))
			{
				SelectedArea->IncrementQueueSize(OwningActor);
			}
			BlackboardComponent->SetValueAsVector(MoveToLocationKey.SelectedKeyName, SelectedArea -> GetCustomerStandPoint()->GetComponentLocation());
			SelectedArea->ACustomerArrivedToInside(OwningActor);
			return EBTNodeResult::Succeeded;
		}
		else
		{
			if (!BlackboardComponent->GetValueAsBool(bIsIndexSettedKey.SelectedKeyName))
			{
				int32 CharQueueIndex = SelectedArea->GetNumOfCustomersInQueue();
				BlackboardComponent->SetValueAsInt(QueueIndexKey.SelectedKeyName, CharQueueIndex);
				BlackboardComponent->SetValueAsBool(bIsIndexSettedKey.SelectedKeyName,true);
			}

			FVector TargetLocation;
			int32 CharQueueIndex = BlackboardComponent->GetValueAsInt(QueueIndexKey.SelectedKeyName);
			
			TArray<FVector>& QueueLocations = SelectedArea->GetQueueLocations();
			
			if (CharQueueIndex >= SelectedArea->GetQueueLocations().Num()) {
				FVector CalculatedNewPoint = SelectedArea->GetCustomerStandPoint()->GetComponentLocation() + SelectedArea->GetCustomerStandPoint()->GetForwardVector() * -200 * CharQueueIndex;
				SelectedArea->GetQueueLocations().Add(CalculatedNewPoint);
			
				TargetLocation = CalculatedNewPoint;
			}
			else
			{
				if (CharQueueIndex == -1)
				{
					CharQueueIndex = SelectedArea->GetNumOfCustomersInQueue();
					BlackboardComponent->SetValueAsInt(QueueIndexKey.SelectedKeyName, CharQueueIndex);
				}
				
				TargetLocation = QueueLocations[CharQueueIndex];
				UE_LOG(LogTemp, Warning, TEXT("var olan noktaya gidildi"));
			}
			
			UE_LOG(LogTemp, Warning, TEXT("masa doluydu ve seçilen yeni locasyon %s"),*TargetLocation.ToString());
			BlackboardComponent->SetValueAsVector(MoveToLocationKey.SelectedKeyName, TargetLocation);
			
			if (!SelectedArea->GetCustomersQueueArray().Contains(OwningActor))
			{
				SelectedArea->IncrementQueueSize(OwningActor);
			}
			
			
			
			
			return EBTNodeResult::Succeeded;
		}
		
	
	
	return EBTNodeResult::Failed;

	
}
