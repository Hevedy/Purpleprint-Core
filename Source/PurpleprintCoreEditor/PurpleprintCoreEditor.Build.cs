/*
===========================================================================
This code is part of the "Source Code" content in
Purpleprint - Core by Hevedy <https://github.com/Hevedy>
<https://github.com/Hevedy/Purpleprint-Core>

The MIT License (MIT)
Copyright (c) 2015-2025 Hevedy <https://github.com/Hevedy>
===========================================================================
*/

/*
================================================
PurpleprintCoreEditor.Build.cs
================================================
*/


using UnrealBuildTool;
using System.IO;

public class PurpleprintCoreEditor : ModuleRules
{
	public PurpleprintCoreEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;


		PublicIncludePaths.Add( Path.Combine( ModuleDirectory, "Public" ) );
        PrivateIncludePaths.Add( Path.Combine( ModuleDirectory, "Private" ) );

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add other public dependencies that you statically link with here ...
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore"
			}
			);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Slate", "SlateCore",
				"UnrealEd",
				"EditorStyle",
				"Projects",
				"LevelEditor",
				"ApplicationCore",
				"ToolMenus",
				"DeveloperSettings",
				"PurpleprintCore"
				// ... add private dependencies that you statically link with here ...
			}
			);

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
