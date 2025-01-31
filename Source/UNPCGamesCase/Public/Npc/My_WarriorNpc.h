// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "My_BaseIncteractableNpc.h"
#include "My_WarriorNpc.generated.h"

/**
 * 
 */
UCLASS()
class UNPCGAMESCASE_API AMy_WarriorNpc : public AMy_BaseIncteractableNpc
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UAnimMontage* SleepEmoteMontage;

	UPROPERTY(EditAnywhere)
	UAnimMontage* StaffSpinMontage;

	UPROPERTY(EditAnywhere)
	UAnimMontage* MonkeyTauntMontage;
	
	
	virtual void DoTask1() override;

	virtual void DoTask2() override;

	virtual void DoTask3() override;
	
};
