// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Basic : ModuleRules
{
	public Basic(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore","EnhancedInput" });


		PublicIncludePaths.Add(ModuleDirectory);	// "*/Classes_Game/{프로젝트명(Basic)}" 추가
		PublicIncludePaths.Add("Basic/Character");	// 추가된 Basic에 Character 추가 포함
													// 이제 헤더파일에 경로에 ../Character해서 찾았던 파일을 그냥 최상단에 쓰면 사용가능
		
		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
