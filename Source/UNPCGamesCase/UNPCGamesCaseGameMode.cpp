// Copyright Epic Games, Inc. All Rights Reserved.

#include "UNPCGamesCaseGameMode.h"
#include "UNPCGamesCaseCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUNPCGamesCaseGameMode::AUNPCGamesCaseGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
