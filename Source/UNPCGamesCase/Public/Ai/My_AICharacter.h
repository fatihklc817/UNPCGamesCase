// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "My_AICharacter.generated.h"

UCLASS()
class UNPCGAMESCASE_API AMy_AICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	AMy_AICharacter();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;



};
