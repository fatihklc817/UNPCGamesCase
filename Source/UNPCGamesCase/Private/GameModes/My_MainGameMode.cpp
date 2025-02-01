// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/My_MainGameMode.h"

#include "AIController.h"
#include "My_BaseIncteractableNpc.h"
#include "My_NpcAreas.h"
#include "Ai/My_AICharacter.h"
#include "Ai/My_AIController.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"


AMy_MainGameMode::AMy_MainGameMode()
{
	NpcAreasClass = AMy_NpcAreas::StaticClass();
}

void AMy_MainGameMode::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(this,NpcAreasClass,NpcAreas);
	


	//rastgele ai müşteri spawnla
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_AiSPawn,
			[this]()
			{
				auto RandIndex = FMath::RandRange(0,1);
			FVector CenterLocation = FVector(0.f, 0.f, 0.f); 
	
			float MinX = -1000.0f;
			float MaxX = 1000.0f;
			float MinY = -1000.0f;
			float MaxY = 1000.0f;
			float MinZ = 50.0f;  
			float MaxZ = 100.0f;

	
			FVector RandomOffset = FVector(
				FMath::RandRange(MinX, MaxX),  
				FMath::RandRange(MinY, MaxY), 
				FMath::RandRange(MinZ, MaxZ)   
			);

	
			FVector FinalLocation = CenterLocation + RandomOffset;
				
				auto SpawnedActor = GetWorld()->SpawnActor<AActor>(AiClass,FinalLocation,FRotator::ZeroRotator);
			},
			FMath::RandRange(SpawnAiSecondRange_MinValue,SpawnAiSecondRange_MaxValue),
			true,
			5);


	//rastgele npc spawnla
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_NpcPawn,
			[this]()
			{
				auto RandIndex = FMath::RandRange(0,1);
				FVector CenterLocation = FVector(0.f, 0.f, 0.f); 
	
				float MinX = -3000.0f;
				float MaxX = 3000.0f;
				float MinY = -3000.0f;
				float MaxY = 3000.0f;
				float MinZ = 50.0f;  
				float MaxZ = 100.0f;

	
				FVector RandomOffset = FVector(
					FMath::RandRange(MinX, MaxX),  
					FMath::RandRange(MinY, MaxY), 
					FMath::RandRange(MinZ, MaxZ)   
				);

	
				FVector FinalLocation = CenterLocation + RandomOffset;
				
				auto SpawnedActor = GetWorld()->SpawnActor<AActor>(NpcClasses[RandIndex],FinalLocation,FRotator::ZeroRotator);
				FRotator LookAtRotation = (UGameplayStatics::GetPlayerPawn(this,0)->GetActorLocation() - FinalLocation).Rotation();
				SpawnedActor->SetActorRotation(LookAtRotation);
				UE_LOG(LogTemp, Warning, TEXT("final loc %s"),*FinalLocation.ToString());
			},
			20,
			true,
			3);
	
}
TArray<AActor*> AMy_MainGameMode::GetNpcAreas()
{
	return NpcAreas;
}
