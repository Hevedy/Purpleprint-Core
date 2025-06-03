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
PurpleprintCore.Build.cs
================================================
*/


using UnrealBuildTool;
using System.IO;

public class PurpleprintCore : ModuleRules
{
	public PurpleprintCore(ReadOnlyTargetRules Target) : base(Target)
	{
		
		//bEnforceIWYU = false;
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		//PublicDefinitions.Add("CUSTOM_ENGINE_HEV=0");


		PublicIncludePaths.Add( Path.Combine( ModuleDirectory, "Public" ) );
        PrivateIncludePaths.Add( Path.Combine( ModuleDirectory, "Private" ) );

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add other public dependencies that you statically link with here ...
				"Core",
				"CoreUObject",
				"Engine",
				"ApplicationCore",
				"CableComponent"
			}
			);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"RHI",
				"RenderCore",
				"UMG", "Slate", "SlateCore", "Niagara",
				// ... add private dependencies that you statically link with here ...
			}
			);

		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.Add("UnrealEd");
		}

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
