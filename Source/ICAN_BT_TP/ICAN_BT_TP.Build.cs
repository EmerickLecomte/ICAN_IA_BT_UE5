// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ICAN_BT_TP : ModuleRules
{
	public ICAN_BT_TP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
