// Fill out your copyright notice in the Description page of Project Settings.


#include "My_HpPot.h"

#include "UNPCGamesCase/UNPCGamesCaseCharacter.h"

void AMy_HpPot::Interact(APawn* InstigatorPawn)
{
	Super::Interact(InstigatorPawn);


	Cast<AUNPCGamesCaseCharacter>(InstigatorPawn)->AddToInventory(ItemStruct);

	UE_LOG(LogTemp, Warning, TEXT("can potu verildiiii"));
	this->Destroy();
	
}

void AMy_HpPot::Use()
{
	//it will give health to the player
	UE_LOG(LogTemp, Warning, TEXT("can potu kullanildii"));
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString("can potu kullanildii"));
}
