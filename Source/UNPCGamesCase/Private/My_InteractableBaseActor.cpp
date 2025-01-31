// Fill out your copyright notice in the Description page of Project Settings.


#include "My_InteractableBaseActor.h"

// Sets default values
AMy_InteractableBaseActor::AMy_InteractableBaseActor()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("staticMesh");
	RootComponent = StaticMesh;

}

// Called when the game starts or when spawned
void AMy_InteractableBaseActor::BeginPlay()
{
	Super::BeginPlay();
	
}



void AMy_InteractableBaseActor::Interact(APawn* InstigatorPawn)
{
	UE_LOG(LogTemp, Warning, TEXT("InteractedWithIt"));
	
}

