// Fill out your copyright notice in the Description page of Project Settings.


#include "My_ManaPot.h"

#include "UNPCGamesCase/UNPCGamesCaseCharacter.h"

void AMy_ManaPot::Interact(APawn* InstigatorPawn)
{
	Super::Interact(InstigatorPawn);

	Cast<AUNPCGamesCaseCharacter>(InstigatorPawn)->AddToInventory(ItemStruct);

	UE_LOG(LogTemp, Warning, TEXT("mana potu verildiiii"));
	this->Destroy();
}

void AMy_ManaPot::Use()
{
	//it will give mana to player
	UE_LOG(LogTemp, Warning, TEXT("mana potu kullanildii"));
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString("mana potu kullanildii"));
}
