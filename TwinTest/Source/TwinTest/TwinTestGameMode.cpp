// Copyright Epic Games, Inc. All Rights Reserved.

#include "TwinTestGameMode.h"
#include "TwinTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATwinTestGameMode::ATwinTestGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
