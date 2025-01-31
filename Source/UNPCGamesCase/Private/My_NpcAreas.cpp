// Fill out your copyright notice in the Description page of Project Settings.


#include "My_NpcAreas.h"

#include "Components/ArrowComponent.h"
#include "GameFramework/Character.h"


AMy_NpcAreas::AMy_NpcAreas()
{
	PrimaryActorTick.bCanEverTick = false;

	AreaMesh = CreateDefaultSubobject<UStaticMeshComponent>("AreaMesh");
	RootComponent = AreaMesh;
	
	CustomerStandPoint = CreateDefaultSubobject<UArrowComponent>("CustomerStandPoint");
	CustomerStandPoint->SetupAttachment(RootComponent);

	bIsAreaBusy = false;

	QueueLocations.Add(CustomerStandPoint->GetComponentLocation());
	
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

void AMy_NpcAreas::ACustomerArrivedToInside(AActor* ArrivedNPC)
{
	SetIsAreaBusy(true);
}



int32 AMy_NpcAreas::GetNumOfCustomersInQueue()
{
	return CustomersQueueArray.Num();
}

void AMy_NpcAreas::Interact(APawn* InstigatorPawn)
{
	UE_LOG(LogTemp, Warning, TEXT("%s is Interacted"),*InstigatorPawn->GetName());
	return;
}

void AMy_NpcAreas::IncrementQueueSize(APawn* ArrivedNPC)
{
	CustomersQueueArray.Add(ArrivedNPC);
	
}

TArray<FVector>& AMy_NpcAreas::GetQueueLocations()
{
	return QueueLocations;
}

TArray<APawn*> AMy_NpcAreas::GetCustomersQueueArray()
{
	return CustomersQueueArray;
}



