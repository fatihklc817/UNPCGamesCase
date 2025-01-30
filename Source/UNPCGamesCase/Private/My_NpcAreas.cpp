// Fill out your copyright notice in the Description page of Project Settings.


#include "My_NpcAreas.h"

#include "Components/ArrowComponent.h"


AMy_NpcAreas::AMy_NpcAreas()
{
	PrimaryActorTick.bCanEverTick = false;

	AreaMesh = CreateDefaultSubobject<UStaticMeshComponent>("AreaMesh");
	RootComponent = AreaMesh;
	
	CustomerStandPoint = CreateDefaultSubobject<UArrowComponent>("CustomerStandPoint");
	CustomerStandPoint->SetupAttachment(RootComponent);

	bIsAreaBusy = false;
	
}


void AMy_NpcAreas::BeginPlay()
{
	Super::BeginPlay();
	
}

UArrowComponent* AMy_NpcAreas::GetCustomerStandPoint()
{
	return CustomerStandPoint;
	
}

bool AMy_NpcAreas::GetIsAreaBusy()
{
	return bIsAreaBusy;
}

void AMy_NpcAreas::SetIsAreaBusy(bool value)
{
	bIsAreaBusy = value;
}

void AMy_NpcAreas::ACustomerArrived(AActor* ArrivedNPC)
{
	SetIsAreaBusy(true);
	CustomersQueue.Enqueue(ArrivedNPC);
	QueueSize++;
	
}

void AMy_NpcAreas::CurrentCustomerDoneItsTask()
{
	QueueSize--;
}

int32 AMy_NpcAreas::GetNumOfCustomersInQueue()
{
	return QueueSize;
}



