// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "My_NpcAreas.generated.h"

UCLASS()
class UNPCGAMESCASE_API AMy_NpcAreas : public AActor
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

	TQueue<AActor*> CustomersQueue;
	int32 QueueSize;

	
	
public:	
	AMy_NpcAreas();

protected:
	virtual void BeginPlay() override;

public:
	UArrowComponent* GetCustomerStandPoint();

	bool GetIsAreaBusy();
	void SetIsAreaBusy(bool value);

	void ACustomerArrived(AActor* ArrivedNPC);

	int32 GetNumOfCustomersInQueue();

};
