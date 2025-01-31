// Fill out your copyright notice in the Description page of Project Settings.


#include "Npc/My_VillagerNpc.h"

#include "Components/TextRenderComponent.h"
#include "Engine/TextRenderActor.h"
#include "UNPCGamesCase/UNPCGamesCaseCharacter.h"


AMy_VillagerNpc::AMy_VillagerNpc()
{
	TextBoxComponent = CreateDefaultSubobject<UTextRenderComponent>("TextBoxComponent");
	TextBoxComponent->SetupAttachment(RootComponent);
}

void AMy_VillagerNpc::DoTask1()
{

	if (!TextBoxComponent)
	{
		return;
	}
	
	TextBoxComponent->SetText(FText::FromString(TEXT("Hi i am villager i live in here and who is asking ? ")));
	
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle,
		[this]()
		{
			TextBoxComponent->SetText(FText::FromString(TEXT("")));
		},
		7,
		false);

	
	
	Super::DoTask1();
}

void AMy_VillagerNpc::DoTask2()
{
	Super::DoTask2();

	
	Cast<AUNPCGamesCaseCharacter>(InteractedPawn)->AddToInventory(ItemStruct);
	
}
