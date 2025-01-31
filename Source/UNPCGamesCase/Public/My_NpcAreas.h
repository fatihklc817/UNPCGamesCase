// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/My_InteractInterface.h"
#include "My_NpcAreas.generated.h"

UCLASS()
class UNPCGAMESCASE_API AMy_NpcAreas : public AActor , public IMy_InteractInterface
{
	GENERATED_BODY()

protected:
	//for location where customer will come and stay
	UPROPERTY(EditAnywhere)
	class UArrowComponent* CustomerStandPoint;
	
	// mesh
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* AreaMesh;

	//to check if any other ai is using the area 
	UPROPERTY()
	bool bIsAreaBusy;

	//to store the queue of customers
	UPROPERTY()
	TArray<APawn*> CustomersQueueArray;
	

	TArray<FVector> QueueLocations;

	
	
public:	
	AMy_NpcAreas();

protected:
	virtual void BeginPlay() override;

public:
	UArrowComponent* GetCustomerStandPoint();

	bool GetIsAreaBusy();
	void SetIsAreaBusy(bool value);

	void ACustomerArrivedToInside(AActor* ArrivedNPC);
	

	int32 GetNumOfCustomersInQueue();

	//Interface
	virtual void Interact(APawn* InstigatorPawn) override;

	void IncrementQueueSize(APawn* ArrivedNPC);

	TArray<FVector>& GetQueueLocations();

	TArray<APawn*>& GetCustomersQueueArray();

};
