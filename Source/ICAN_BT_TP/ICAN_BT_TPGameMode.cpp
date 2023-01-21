// Copyright Epic Games, Inc. All Rights Reserved.

#include "ICAN_BT_TPGameMode.h"
#include "ICAN_BT_TPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AICAN_BT_TPGameMode::AICAN_BT_TPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
