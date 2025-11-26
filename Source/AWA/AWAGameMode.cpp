// Copyright Epic Games, Inc. All Rights Reserved.

#include "AWAGameMode.h"

AAWAGameMode::AAWAGameMode()
{
	DefaultPawnClass = AAWACharacter::StaticClass(); // o tu BP
	PlayerControllerClass = AAWAPlayerController::StaticClass();
}
