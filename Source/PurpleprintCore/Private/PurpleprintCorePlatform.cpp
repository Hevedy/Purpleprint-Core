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
PurpleprintCorePlatform.cpp
================================================
*/


#include "PurpleprintCorePlatform.h"
#include "GenericPlatform/GenericApplication.h"
#include "GenericPlatform/GenericPlatformDriver.h"
#include "Widgets/SWindow.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/GameNetworkManager.h"
#include "Interfaces/NetworkPredictionInterface.h"
#include "Net/OnlineEngineInterface.h"

#if WITH_EDITORONLY_DATA
#include "AssetRegistry/AssetRegistryModule.h"
#include "Editor.h"
#include "PackageTools.h"
#include "FileHelpers.h"
#endif // WITH_EDITORONLY_DATA


UPurpleprintCorePlatform::UPurpleprintCorePlatform(const class FObjectInitializer& ObjectInitializer) 
{

}


FString UPurpleprintCorePlatform::GetObjectFullName(UObject* Object)
{
	return GetFullNameSafe(Object);
}

FString UPurpleprintCorePlatform::GetSoftObjectName(TSoftObjectPtr<UObject> InObject)
{
	return InObject.GetAssetName();
}

FName UPurpleprintCorePlatform::GetPersistentLevelName(class UObject* WorldContextObject)
{
	if (!WorldContextObject)
	{
		return NAME_None;
	}
	return WorldContextObject->GetWorld()->PersistentLevel->GetOuter()->GetFName();
}

FName UPurpleprintCorePlatform::GetStreamLevelNameFromActor(AActor* Actor)
{
	if (Actor != nullptr)
	{
		ULevel* level = Actor->GetLevel();
		if (level) 
		{
			return level->GetOuter()->GetFName();
		}
	}
	return NAME_None;
}

FName UPurpleprintCorePlatform::GetStreamLevelNameFromReference(const TSoftObjectPtr<UWorld> World)
{
	if (World != nullptr)
	{
		return FName(*FPackageName::ObjectPathToPackageName(World.ToString()));
	}
	return NAME_None;
}

FName UPurpleprintCorePlatform::GetCorrectAssetName(const FString String)
{
	if (String != "") 
	{
		return FName(*FPackageName::ObjectPathToPackageName(String));
	}
	return NAME_None;
}

bool UPurpleprintCorePlatform::IsEditorBuild()
{
#if WITH_EDITOR
    return true;
#else
    return false;
#endif
}

bool UPurpleprintCorePlatform::IsDebugBuild()
{
#if UE_BUILD_DEBUG
    return true;
#else
    return false;
#endif
}

bool UPurpleprintCorePlatform::IsDevelopmentBuild()
{
#if UE_BUILD_DEVELOPMENT
    return true;
#else
    return false;
#endif
}

bool UPurpleprintCorePlatform::IsShippingBuild()
{
#if UE_BUILD_SHIPPING
    return true;
#else
    return false;
#endif
}

void UPurpleprintCorePlatform::GetPrimaryMonitorResolution(int32& Width, int32& Height)
{
	FDisplayMetrics displayMetrics;
	FDisplayMetrics::RebuildDisplayMetrics(displayMetrics);

	Width = displayMetrics.PrimaryDisplayWidth;
	Height = displayMetrics.PrimaryDisplayHeight;
}

TArray<FPurpleDisplayInfo> UPurpleprintCorePlatform::GetMonitorsInfo()
{
	FDisplayMetrics displayMetrics;
	FDisplayMetrics::RebuildDisplayMetrics(displayMetrics);

	TArray<FPurpleDisplayInfo> di;
	for (const FMonitorInfo& m : displayMetrics.MonitorInfo) {
		di.Add(FPurpleDisplayInfo(m.Name, m.ID, m.NativeWidth, m.NativeHeight, m.MaxResolution, m.bIsPrimary, m.DPI));
	}
	return di;
}

int32 UPurpleprintCorePlatform::GetMonitorsNum()
{
	return GetMonitorsInfo().Num();
}

FPurpleDisplayInfo UPurpleprintCorePlatform::GetPrimaryMonitorInfo()
{
	FDisplayMetrics displayMetrics;
	FDisplayMetrics::RebuildDisplayMetrics(displayMetrics);

	FPurpleDisplayInfo di = FPurpleDisplayInfo();
	for (const FMonitorInfo& m : displayMetrics.MonitorInfo) {
		if (m.bIsPrimary) {
			return FPurpleDisplayInfo(m.Name, m.ID, m.NativeWidth, m.NativeHeight, m.MaxResolution, m.bIsPrimary, m.DPI);
		}
	}
	// In case invalid
	return di;
}

int32 UPurpleprintCorePlatform::GetPrimaryMonitorIndex()
{
	FDisplayMetrics displayMetrics;
	FDisplayMetrics::RebuildDisplayMetrics(displayMetrics);

	int32 i = 0;
	for (const FMonitorInfo& m : displayMetrics.MonitorInfo) {
		if (m.bIsPrimary) {
			return i;
		}
		i++;
	}
	return -1;
}

FString UPurpleprintCorePlatform::GetPrimaryMonitorName()
{
	FPurpleDisplayInfo info = GetPrimaryMonitorInfo();
	return info.Name;
}

bool UPurpleprintCorePlatform::IsIndexPrimaryMonitor(const int32 Index) 
{
	return Index == GetPrimaryMonitorIndex();
}

FPurpleDisplayInfo UPurpleprintCorePlatform::GetMonitorInfoByIndex(const int32 Index)
{
	FDisplayMetrics displayMetrics;
	FDisplayMetrics::RebuildDisplayMetrics(displayMetrics);

	FPurpleDisplayInfo di = FPurpleDisplayInfo();
	
	const int32 index = FMath::Clamp(Index, 0, displayMetrics.MonitorInfo.Num());

	const FMonitorInfo m = displayMetrics.MonitorInfo[index];
	di = FPurpleDisplayInfo(m.Name, m.ID, m.NativeWidth, m.NativeHeight, m.MaxResolution, m.bIsPrimary, m.DPI);
	return di;
}

FString UPurpleprintCorePlatform::GetMonitorName(const int32 Index)
{
	FPurpleDisplayInfo info = GetMonitorInfoByIndex(Index);
	return info.Name;
}

bool UPurpleprintCorePlatform::GetSupportedFullscreenResolutionsByIndex(TArray<FIntPoint>& Resolutions, const int32 Index)
{
	uint32 minYResolution = UKismetSystemLibrary::GetMinYResolutionForUI();
	FPurpleDisplayInfo di = GetMonitorInfoByIndex(Index);

	FScreenResolutionArray supportedResolutions;
	if (RHIGetAvailableResolutions(supportedResolutions, true))
	{
		uint32 largestY = 0;
		for (const FScreenResolutionRHI& supportedResolution : supportedResolutions)
		{
			largestY = FMath::Max(largestY, supportedResolution.Height);
			if (supportedResolution.Height >= minYResolution)
			{
				FIntPoint resolution;
				resolution.X = supportedResolution.Width;
				resolution.Y = supportedResolution.Height;

				Resolutions.Add(resolution);
			}
		}
		if (!Resolutions.Num())
		{
			if (di.NativeHeight == largestY)
			{
				FIntPoint resolution;
				resolution.X = di.NativeWidth;
				resolution.Y = di.NativeHeight;

				Resolutions.Add(resolution);
			}
		}

		return true;
	}

	return false;
}

int32 UPurpleprintCorePlatform::DateTimeToUnixTimeStamp(const FDateTime& _DateTime) 
{
	return _DateTime.ToUnixTimestamp();
}

int64 UPurpleprintCorePlatform::DateTimeToUnixTimeStamp64(const FDateTime& _DateTime) 
{
	return _DateTime.ToUnixTimestamp();
}

FString UPurpleprintCorePlatform::GetCPUBrandName()
{
	return FWindowsPlatformMisc::GetCPUBrand();
}

FString UPurpleprintCorePlatform::GetCPUVendorName()
{
	return FWindowsPlatformMisc::GetCPUVendor();
}

int32 UPurpleprintCorePlatform::GetCPUCores()
{
	return FWindowsPlatformMisc::NumberOfCores();
}

FString UPurpleprintCorePlatform::GetGPUBrandName()
{
	return FWindowsPlatformMisc::GetPrimaryGPUBrand();
}

FString UPurpleprintCorePlatform::GetGPUDriverInfo()
{
	return FWindowsPlatformMisc::GetGPUDriverInfo(FWindowsPlatformMisc::GetPrimaryGPUBrand()).DeviceDescription;
}

FString UPurpleprintCorePlatform::GetOSVersion()
{
	return FWindowsPlatformMisc::GetOSVersion();
}

FString UPurpleprintCorePlatform::GetNetRoleString(const ENetRole Role)
{
	switch (Role)
	{
	case ROLE_None:
		return "None";
	case ROLE_SimulatedProxy:
		return "SimulatedProxy";
	case ROLE_AutonomousProxy:
		return "AutonomousProxy";
	case ROLE_Authority:
		return "Authority";
	case ROLE_MAX:
		return "Max";
	default:
		return "Unknow";
	}
}

FString UPurpleprintCorePlatform::GetNetModeString(const ENetMode Mode)
{
	switch (Mode)
	{
	case NM_Standalone:
		return "Standalone";
	case NM_DedicatedServer:
		return "DedicatedServer";
	case NM_ListenServer:
		return "ListenServer";
	case NM_Client:
		return "Client";
	case NM_MAX:
		return "Max";
	default:
		return "Unknow";
	}
}

bool UPurpleprintCorePlatform::SavePackages(TArray<UPackage*> Packages, bool bPrompt)
{
#if WITH_EDITORONLY_DATA
	for(UPackage* Package : Packages)
	{
		if (Package && Package->IsValidLowLevel() && !Package->IsPendingKill())
		{
			if (Package->IsDirty())
			{
				FEditorFileUtils::PromptForCheckoutAndSave({ Package }, false, bPrompt);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Package %s is not dirty, no need to save."), *Package->GetName());
			}
		}
	}
	return true;
#else
	return false;
#endif // WITH_EDITORONLY_DATA
}

bool UPurpleprintCorePlatform::SaveObjects(TArray<UObject*> Objects, bool bPrompt)
{
#if WITH_EDITORONLY_DATA
	for (UObject* Object : Objects)
	{
		if (Object && Object->IsValidLowLevel() && !Object->IsPendingKill())
		{
			UPackage* package = Object->GetOutermost();
			if (package && package->IsDirty())
			{
				FEditorFileUtils::PromptForCheckoutAndSave({ package }, false, bPrompt);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Package %s is not dirty, no need to save."), *package->GetName());
			}
		}
	}
	return true;
#else
	return false;
#endif // WITH_EDITORONLY_DATA
}

bool UPurpleprintCorePlatform::SavePackage(UPackage* Package, bool bPrompt)
{
#if WITH_EDITORONLY_DATA
	if (Package)
	{
		if (Package->IsValidLowLevel() && !Package->IsPendingKill())
		{
			if (Package->IsDirty())
			{
				//FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
				//AssetRegistryModule.Get().AssetModified(Package);
				FEditorFileUtils::PromptForCheckoutAndSave({ Package }, false, bPrompt);
				//FEditorFileUtils::SaveDirtyPackages(false, true, true, false, false, false);
				return true;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Package %s is not dirty, no need to save."), *Package->GetName());
			}
		}
	}
	return false;
#else
	return false;
#endif // WITH_EDITORONLY_DATA
}

bool UPurpleprintCorePlatform::SaveObject(UObject* Object, bool bPrompt)
{
#if WITH_EDITORONLY_DATA
	if (Object && Object->IsValidLowLevel() && !Object->IsPendingKill())
	{
		UPackage* package = Object->GetOutermost();
		return SavePackage(package, bPrompt);
	}
	return false;
#else
	return false;
#endif // WITH_EDITORONLY_DATA
}

FDateTime UPurpleprintCorePlatform::GetFileModificationTime(const FString& FilePath)
{
	IPlatformFile& platformFile = FPlatformFileManager::Get().GetPlatformFile();

	if (!platformFile.FileExists(*FilePath))
	{
		UE_LOG(LogTemp, Warning, TEXT("File not found: %s"), *FilePath);
		return FDateTime(); // Time by default
	}

	return platformFile.GetTimeStamp(*FilePath);
}

int64 UPurpleprintCorePlatform::GetFileSize(const FString& FilePath)
{
	IPlatformFile& platformFile = FPlatformFileManager::Get().GetPlatformFile();

	if (!platformFile.FileExists(*FilePath))
	{
		UE_LOG(LogTemp, Warning, TEXT("File not found: %s"), *FilePath);
		return -1; // Invalid size
	}

	return platformFile.FileSize(*FilePath);
}

FString UPurpleprintCorePlatform::GetFileMD5(const FString& FilePath)
{
	IPlatformFile& platformFile = FPlatformFileManager::Get().GetPlatformFile();
	if (!platformFile.FileExists(*FilePath))
	{
		UE_LOG(LogTemp, Warning, TEXT("File does not exist: %s"), *FilePath);
		return FString();
	}

	TArray<uint8> fileData;
	if (!FFileHelper::LoadFileToArray(fileData, *FilePath))
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to read the file: %s"), *FilePath);
		return FString();
	}

	FMD5 md5;
	md5.Update(fileData.GetData(), fileData.Num());

	uint8 digest[16];
	md5.Final(digest);

	return BytesToHex(digest, 16);
}

bool UPurpleprintCorePlatform::CompareMD5Hashes(const FString& FilePathA, const FString& FilePathB)
{
	FString hash1 = GetFileMD5(FilePathA);
	FString hash2 = GetFileMD5(FilePathB);

	if (hash1.IsEmpty() || hash2.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("Unable to get file hashes from one or both files."));
		return false;
	}

	if (hash1 == hash2)
	{
		return true; // Hashes are equal
	}
	else
	{
		return false; // Hashes are not equal
	}
}