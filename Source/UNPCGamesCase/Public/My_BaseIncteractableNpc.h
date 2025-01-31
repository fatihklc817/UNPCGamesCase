// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/My_InteractInterface.h"
#include "My_BaseIncteractableNpc.generated.h"

UCLASS()
class UNPCGAMESCASE_API AMy_BaseIncteractableNpc : public ACharacter, public IMy_InteractInterface
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> NPCWidgetClass;

	UPROPERTY()
	UUserWidget* CreatedNpcWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,meta=(AllowPrivateAccess=true))
	FString Task1String;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,meta=(AllowPrivateAccess=true))
	FString Task2String;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,meta=(AllowPrivateAccess=true))
	FString Task3String;

	//istenen 3 random değişken
	UPROPERTY(EditDefaultsOnly)
	float Health;

	UPROPERTY(EditDefaultsOnly)
	bool IsCool;

	UPROPERTY(EditDefaultsOnly)
	int32 Age;

protected:
	UPROPERTY()
	APawn* InteractedPawn;
	
public:
	AMy_BaseIncteractableNpc();

protected:
	virtual void BeginPlay() override;

	void RemoveWidgetAndSetInputModeToGameOnly();

public:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Interact(APawn* InstigatorPawn) override;

	UFUNCTION(BlueprintCallable)
	virtual void DoTask1();

	UFUNCTION(BlueprintCallable)
	virtual void DoTask2();

	UFUNCTION(BlueprintCallable)
	virtual void DoTask3();

	

	
};
