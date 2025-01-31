// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "My_BaseIncteractableNpc.h"
#include "My_ItemStruct.h"
#include "My_VillagerNpc.generated.h"

/**
 * 
 */
UCLASS()
class UNPCGAMESCASE_API AMy_VillagerNpc : public AMy_BaseIncteractableNpc
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,Category="Data")
	FItemStruct ItemStruct;
	
	UPROPERTY(EditDefaultsOnly)
	class UTextRenderComponent* TextBoxComponent;
	
public:

	AMy_VillagerNpc();
	
	virtual void DoTask1() override;

	virtual void DoTask2() override;

		
};
