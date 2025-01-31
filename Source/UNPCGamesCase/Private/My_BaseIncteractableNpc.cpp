// Fill out your copyright notice in the Description page of Project Settings.


#include "My_BaseIncteractableNpc.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UNPCGamesCase/UNPCGamesCaseCharacter.h"

// Sets default values
AMy_BaseIncteractableNpc::AMy_BaseIncteractableNpc()
{

	PrimaryActorTick.bCanEverTick = false;

	Health = FMath::RandRange(50,500);
	IsCool = FMath::RandBool();
	Age = FMath::RandRange(20,100);
}


void AMy_BaseIncteractableNpc::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("health : %f "),Health);
	UE_LOG(LogTemp, Warning, TEXT("Am I cool: %s"), IsCool ? TEXT("true") : TEXT("false"));
	UE_LOG(LogTemp, Warning, TEXT("my age is %d"),Age);
}

void AMy_BaseIncteractableNpc::RemoveWidgetAndSetInputModeToGameOnly()
{
	CreatedNpcWidget->RemoveFromParent();
	
	auto PlayerController = CreatedNpcWidget->GetOwningPlayer();

	FInputModeGameOnly InputMode;
	PlayerController->bShowMouseCursor = false;
	PlayerController->SetInputMode(InputMode);
	PlayerController->ResetIgnoreInputFlags();
}


void AMy_BaseIncteractableNpc::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMy_BaseIncteractableNpc::Interact(APawn* InstigatorPawn)
{
	InteractedPawn = InstigatorPawn;
	UE_LOG(LogTemp, Warning, TEXT("interacted witth %s"),*GetName());
	APlayerController* InstigatorPlayerController = Cast<APlayerController>(InstigatorPawn->GetController());
	if (!InstigatorPlayerController)
	{
		return;
	}

	Cast<AUNPCGamesCaseCharacter>(InstigatorPawn)->SetLastInteractedNpc(this);
	CreatedNpcWidget =  CreateWidget<UUserWidget>(InstigatorPlayerController,NPCWidgetClass);
	CreatedNpcWidget->AddToViewport();
	
	FInputModeUIOnly InputMode;
	Cast<APlayerController>( InstigatorPawn->GetController())->SetInputMode(InputMode);
	InstigatorPlayerController->bShowMouseCursor = true;
	InstigatorPlayerController->SetIgnoreMoveInput(true);
	
}

void AMy_BaseIncteractableNpc::DoTask1()
{
	UE_LOG(LogTemp, Warning, TEXT("task1"));
	RemoveWidgetAndSetInputModeToGameOnly();
	
}

void AMy_BaseIncteractableNpc::DoTask2()
{
	UE_LOG(LogTemp, Warning, TEXT("task2"));
	RemoveWidgetAndSetInputModeToGameOnly();
}

void AMy_BaseIncteractableNpc::DoTask3()
{
	UE_LOG(LogTemp, Warning, TEXT("task3"));
	RemoveWidgetAndSetInputModeToGameOnly();
}

