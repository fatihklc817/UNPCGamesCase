// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "My_InteractableBaseActor.h"
#include "My_UsableInventoryItem.generated.h"

/**
 * 
 */
UCLASS()
class UNPCGAMESCASE_API AMy_UsableInventoryItem : public AMy_InteractableBaseActor
{
	GENERATED_BODY()

public:
	virtual void Use(); 
	
};
