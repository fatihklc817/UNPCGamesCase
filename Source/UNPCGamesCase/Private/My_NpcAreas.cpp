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

	
}


void AMy_NpcAreas::BeginPlay()
{
	Super::BeginPlay();
	
}

FTransform AMy_NpcAreas::GetCustomerStandPoint()
{
	return CustomerStandPoint->GetComponentTransform();
}



