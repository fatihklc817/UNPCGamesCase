// Fill out your copyright notice in the Description page of Project Settings.


#include "Npc/My_WarriorNpc.h"

void AMy_WarriorNpc::DoTask1()
{
	Super::DoTask1();
	
	PlayAnimMontage(SleepEmoteMontage);
}

void AMy_WarriorNpc::DoTask2()
{
	Super::DoTask2();

	PlayAnimMontage(StaffSpinMontage);
}

void AMy_WarriorNpc::DoTask3()
{
	Super::DoTask3();
	PlayAnimMontage(MonkeyTauntMontage);
}
