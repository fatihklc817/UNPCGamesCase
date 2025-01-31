// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "My_InteractInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMy_InteractInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UNPCGAMESCASE_API IMy_InteractInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void Interact(APawn* InstigatorPawn);
};
