// Copyright Epic Games, Inc. All Rights Reserved.

#include "TwinToolCommands.h"

#define LOCTEXT_NAMESPACE "FTwinToolModule"

void FTwinToolCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "TwinTool", "Execute TwinTool action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
