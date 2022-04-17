// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ActionCameraManager : ModuleRules
{
	public ActionCameraManager(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		MinFilesUsingPrecompiledHeaderOverride = 1;

		bEnforceIWYU = true;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine" });
		PublicIncludePaths.AddRange(new string[] { "ActionCameraManager/Public" });
		PrivateIncludePaths.AddRange(new string[] { "ActionCameraManager/Private" });

	}
}
