// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/My_InteractInterface.h"
#include "My_InteractableBaseActor.generated.h"

UCLASS()
class UNPCGAMESCASE_API AMy_InteractableBaseActor : public AActor, public IMy_InteractInterface
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	
	
public:	
	// Sets default values for this actor's properties
	AMy_InteractableBaseActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	virtual void Interact(APawn* InstigatorPawn) override;

};
