// Fill out your copyright notice in the Description page of Project Settings.


#include "Ai/My_BTTask_FindAndGoToAreaPoint.h"

#include "My_NpcAreas.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/ArrowComponent.h"


EBTNodeResult::Type UMy_BTTask_FindAndGoToAreaPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

		//burada karakter sıra yoksa 0 a yerleşip alana gidiyor eğer sıra varsa sırasını ve konumunu heesaplayıp oraya doğru gidiyor. 
	
		UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
		auto OwningActor = Cast<AController>(OwnerComp.GetOwner())->GetPawn();
	
		auto SelectedArea = Cast<AMy_NpcAreas>(BlackboardComponent->GetValueAsObject(SelectedAreaKey.SelectedKeyName));

		if (!ensure(SelectedArea)) return EBTNodeResult::Failed;

		if (SelectedArea->GetCustomersQueueArray().Num() == 0)															//eğer sıra boş ise karakter 0.cıdır
		{
			BlackboardComponent->SetValueAsInt(QueueIndexKey.SelectedKeyName, 0);
		}
	
		if (!SelectedArea->GetIsAreaBusy() && BlackboardComponent->GetValueAsInt(QueueIndexKey.SelectedKeyName) == 0)	//eğer karakter 0.indexdeyse ve Alan boş ise buraya girer ve hedef lokasyonu 0. yani işlem noktası yapar.
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
			if (!BlackboardComponent->GetValueAsBool(bIsIndexSettedKey.SelectedKeyName))								//eğer alan meşgulse ve karakter daha önce sırasını hesaplamadıysa buraya girer ve sırasını hesaplar
			{
				int32 CharQueueIndex = SelectedArea->GetNumOfCustomersInQueue();
				BlackboardComponent->SetValueAsInt(QueueIndexKey.SelectedKeyName, CharQueueIndex);
				BlackboardComponent->SetValueAsBool(bIsIndexSettedKey.SelectedKeyName,true);
			}

			FVector TargetLocation;																						//sırası belli olan karakter pozisyonunu hesaplar
			int32 CharQueueIndex = BlackboardComponent->GetValueAsInt(QueueIndexKey.SelectedKeyName);
			
			TArray<FVector>& QueueLocations = SelectedArea->GetQueueLocations();
			
			if (CharQueueIndex >= SelectedArea->GetQueueLocations().Num()) {
				FVector CalculatedNewPoint = SelectedArea->GetCustomerStandPoint()->GetComponentLocation() + SelectedArea->GetCustomerStandPoint()->GetForwardVector() * -200 * CharQueueIndex;
				SelectedArea->GetQueueLocations().Add(CalculatedNewPoint);
			
				TargetLocation = CalculatedNewPoint;
			}
			else
			{
				if (CharQueueIndex == -1)																				// burası normalde logicde yok ancak sanırım threadsafe çalışmadığı için bazen aynı anda olan işlemlerden dolayı index
				{																										// hesabında hata oluyor ve index 0 a düşüp azaldığında -1 oluyor ve bu durumda çökmek yerine tekrar index hesaplayıp 
					CharQueueIndex = SelectedArea->GetNumOfCustomersInQueue();											// en sona gitmesini sağlıyor
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
