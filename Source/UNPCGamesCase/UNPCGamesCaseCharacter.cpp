// Copyright Epic Games, Inc. All Rights Reserved.

#include "UNPCGamesCaseCharacter.h"
#include "UNPCGamesCaseProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "My_InteractableBaseActor.h"
#include "My_UsableInventoryItem.h"
#include "Engine/LocalPlayer.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AUNPCGamesCaseCharacter

AUNPCGamesCaseCharacter::AUNPCGamesCaseCharacter()
{
	// Character doesnt have a rifle at start
	bHasRifle = false;
	
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
		
	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

	

}

void AUNPCGamesCaseCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

}

//////////////////////////////////////////////////////////////////////////// Input

void AUNPCGamesCaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AUNPCGamesCaseCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AUNPCGamesCaseCharacter::Look);

		//Interact
		EnhancedInputComponent->BindAction(InteractAction,ETriggerEvent::Started,this,&AUNPCGamesCaseCharacter::Interact);

		//drop last imte
		EnhancedInputComponent->BindAction(DropLastItemAction,ETriggerEvent::Started,this,&AUNPCGamesCaseCharacter::DropLastItem);

		//use items
		EnhancedInputComponent->BindAction(UseFirstItemAction,ETriggerEvent::Started,this,&AUNPCGamesCaseCharacter::UseFirstItem);
		EnhancedInputComponent->BindAction(UseSecondItemAction,ETriggerEvent::Started,this,&AUNPCGamesCaseCharacter::UseSecondItem);
		EnhancedInputComponent->BindAction(UseThirdItemAction,ETriggerEvent::Started,this,&AUNPCGamesCaseCharacter::UseThirdItem);
		EnhancedInputComponent->BindAction(UseFourthItemAction,ETriggerEvent::Started,this,&AUNPCGamesCaseCharacter::UseFourthItem);
		
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AUNPCGamesCaseCharacter::AddToInventory(FItemStruct ItemStruct)
{
	if (Inventory.Num() >= 4 )
	{
		return;
	}
	Inventory.Add(ItemStruct);

	for (auto Element : Inventory)
	{
		UE_LOG(LogTemp, Warning, TEXT("item : %s"),*Element.Name.ToString());
	}

	OnInventoryUpdated.Broadcast();
}

TArray<FItemStruct> AUNPCGamesCaseCharacter::GetInventory()
{
	return Inventory;
}


void AUNPCGamesCaseCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AUNPCGamesCaseCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AUNPCGamesCaseCharacter::SetHasRifle(bool bNewHasRifle)
{
	bHasRifle = bNewHasRifle;
}

bool AUNPCGamesCaseCharacter::GetHasRifle()
{
	return bHasRifle;
}


void AUNPCGamesCaseCharacter::Interact()
{
	FVector StartPos = GetFirstPersonCameraComponent()->GetComponentLocation();
	FRotator Rotation = GetControlRotation();

	FVector EndPosition = StartPos + Rotation.Vector() * 1000;

	FHitResult HitResult;
	FCollisionQueryParams params;
	params.AddIgnoredActor(this);
	if (GetWorld()->LineTraceSingleByChannel(HitResult,StartPos,EndPosition,ECC_Visibility,params))
	{
		if (HitResult.GetActor()->Implements<UMy_InteractInterface>())
		{
			auto InteractInterface = Cast<IMy_InteractInterface>(HitResult.GetActor());
			InteractInterface->Interact(this);
		}
	}

	DrawDebugLine(GetWorld(),StartPos,EndPosition,FColor::Red,false,5,0,5);
}

void AUNPCGamesCaseCharacter::DropLastItem()
{
	if (Inventory.Num() <= 0)
	{
		return;
	}
	
	GetWorld()->SpawnActor<AActor>(Inventory[Inventory.Num()-1].ItemClassForSpawn,GetActorLocation(),FRotator::ZeroRotator);
	
	Inventory.RemoveAt(Inventory.Num()-1);
	OnInventoryUpdated.Broadcast();

}

void AUNPCGamesCaseCharacter::UseFirstItem()
{
	GetDataAndUseItemAtIndex(0);
}

void AUNPCGamesCaseCharacter::UseSecondItem()
{
	GetDataAndUseItemAtIndex(1);
}

void AUNPCGamesCaseCharacter::UseThirdItem()
{
	GetDataAndUseItemAtIndex(2);
}

void AUNPCGamesCaseCharacter::UseFourthItem()
{
	GetDataAndUseItemAtIndex(3);
}

void AUNPCGamesCaseCharacter::GetDataAndUseItemAtIndex(int32 Index)
{
	if (!Inventory.IsValidIndex(Index))
	{
		return;
	}
	auto SlotItemClass =	Inventory[Index].ItemClassForUse;
	
	auto SpawnedActor= GetWorld()->SpawnActor<AMy_UsableInventoryItem>(SlotItemClass,FVector::ZeroVector,FRotator::ZeroRotator);	
	SpawnedActor->Use();
	SpawnedActor->Destroy();
	Inventory.RemoveAt(Index);
	OnInventoryUpdated.Broadcast();
}


