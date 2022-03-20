// Copyright Epic Games, Inc. All Rights Reserved.

#include "BattleCameraGameMode.h"
#include "BattleCameraCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABattleCameraGameMode::ABattleCameraGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
