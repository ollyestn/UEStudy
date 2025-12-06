// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Framework/Commands/Commands.h"
#include "TwinToolStyle.h"

class FTwinToolCommands : public TCommands<FTwinToolCommands>
{
public:

	FTwinToolCommands()
		: TCommands<FTwinToolCommands>(TEXT("TwinTool"), NSLOCTEXT("Contexts", "TwinTool", "TwinTool Plugin"), NAME_None, FTwinToolStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
