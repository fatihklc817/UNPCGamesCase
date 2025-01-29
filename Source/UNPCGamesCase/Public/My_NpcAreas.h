// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "My_NpcAreas.generated.h"

UCLASS()
class UNPCGAMESCASE_API AMy_NpcAreas : public AActor
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere)
	class UArrowComponent* CustomerStandPoint;
	

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* AreaMesh;
	
public:	
	AMy_NpcAreas();

protected:
	virtual void BeginPlay() override;

public:
	FTransform GetCustomerStandPoint();



};
