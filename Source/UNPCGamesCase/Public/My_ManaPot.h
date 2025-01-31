// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "My_ItemStruct.h"
#include "My_UsableInventoryItem.h"
#include "My_ManaPot.generated.h"

/**
 * 
 */
UCLASS()
class UNPCGAMESCASE_API AMy_ManaPot : public AMy_UsableInventoryItem
{
	GENERATED_BODY()

	
	UPROPERTY(EditAnywhere,Category="Data")
	FItemStruct ItemStruct;

public:
	virtual void Interact(APawn* InstigatorPawn) override;

	virtual void Use() override;
	
	
};
