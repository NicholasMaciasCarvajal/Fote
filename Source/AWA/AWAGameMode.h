// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AWAGameMode.generated.h"
#include "AWACharacter.h"
#include "AWAPlayerController.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class AAWAGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	AAWAGameMode();
};



