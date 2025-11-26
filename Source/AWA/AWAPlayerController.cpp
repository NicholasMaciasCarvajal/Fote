// Copyright Epic Games, Inc. All Rights Reserved.


#include "AWAPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"

void AAWAPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Contexts
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}

void AAWAPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (!GetPawn())
    {
        FVector SpawnLocation = FVector(0, 0, 300);
        FRotator SpawnRotation = FRotator::ZeroRotator;
        FActorSpawnParameters Params;
        Params.Owner = this;

        AAWACharacter* NewPawn = GetWorld()->SpawnActor<AAWACharacter>(AAWACharacter::StaticClass(), SpawnLocation, SpawnRotation, Params);
        Possess(NewPawn);
    }
}
