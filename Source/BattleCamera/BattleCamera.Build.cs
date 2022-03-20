// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BattleCamera : ModuleRules
{
	public BattleCamera(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
