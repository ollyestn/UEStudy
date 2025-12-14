// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class OfflineSpeechRecognition : ModuleRules
{
	public OfflineSpeechRecognition(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"OfflineSpeechRecognitionLibrary",
				"Projects",
				// ... add other public dependencies that you statically link with here ...
				"CoreUObject", 
				"Engine", 
				"InputCore",
            }
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);


		// 添加Vosk路径（示例）
        string VoskPath = Path.Combine(ModuleDirectory, "../ThirdParty", "Vosk");
        PublicIncludePaths.Add(Path.Combine(VoskPath, "include"));
        PublicAdditionalLibraries.Add(Path.Combine(VoskPath, "lib", "libvosk.lib"));
        // 复制libvosk.dll到==> TwinTest\Plugins\OfflineSpeechRecognition\Binaries\Win64
        // libgcc_s_seh-1.dll到==> TwinTest\Plugins\OfflineSpeechRecognition\Binaries\Win64
        // libstdc++-6.dll到==> TwinTest\Plugins\OfflineSpeechRecognition\Binaries\Win64
        // libwinpthread-1.dll到==> TwinTest\Plugins\OfflineSpeechRecognition\Binaries\Win64
        //RuntimeDependencies.Add("$(PluginDir)/ThirdParty/Vosk/lib/libvosk.dll");
    }
}
