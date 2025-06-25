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
PurpleprintCorePlatform.h
================================================
*/


#pragma once


//#include "Engine.h"
#include "CoreMinimal.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Package.h"
#include "Misc/EnumRange.h"
#include "Engine/EngineBaseTypes.h"
#include "GenericPlatform/GenericApplication.h"
#include "PurpleprintCorePlatform.generated.h"

UENUM(BlueprintType)
enum class EPurplePowerOfTwo : uint8
{
	e1		UMETA(DisplayName = "1"),
	e2		UMETA(DisplayName = "2"),
	e4		UMETA(DisplayName = "4"),
	e8		UMETA(DisplayName = "8"),
	e16		UMETA(DisplayName = "16"),
	e32		UMETA(DisplayName = "32"),
	e64		UMETA(DisplayName = "64"),
	e128	UMETA(DisplayName = "128"),
	e256	UMETA(DisplayName = "256"),
	e512	UMETA(DisplayName = "512"),
	e1024	UMETA(DisplayName = "1024"),
	e2048	UMETA(DisplayName = "2048"),
	e4096	UMETA(DisplayName = "4096"),
	e8192	UMETA(DisplayName = "8192")
};
ENUM_RANGE_BY_FIRST_AND_LAST(EPurplePowerOfTwo, EPurplePowerOfTwo::e1, EPurplePowerOfTwo::e8192);

UENUM(BlueprintType)
enum class EPurplePowerOfTwoCustom : uint8
{
	eCustom UMETA(DisplayName = "Custom"),
	e1		UMETA(DisplayName = "1"),
	e2		UMETA(DisplayName = "2"),
	e4		UMETA(DisplayName = "4"),
	e8		UMETA(DisplayName = "8"),
	e16		UMETA(DisplayName = "16"),
	e32		UMETA(DisplayName = "32"),
	e64		UMETA(DisplayName = "64"),
	e128	UMETA(DisplayName = "128"),
	e256	UMETA(DisplayName = "256"),
	e512	UMETA(DisplayName = "512"),
	e1024	UMETA(DisplayName = "1024"),
	e2048	UMETA(DisplayName = "2048"),
	e4096	UMETA(DisplayName = "4096"),
	e8192	UMETA(DisplayName = "8192")
};
ENUM_RANGE_BY_FIRST_AND_LAST(EPurplePowerOfTwoCustom, EPurplePowerOfTwoCustom::eCustom, EPurplePowerOfTwoCustom::e8192);

USTRUCT(BlueprintType)
struct FPurplePowerOfTwoResolutionCustom
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "Purpleprint", BlueprintReadWrite)
	EPurplePowerOfTwoCustom Width;

	UPROPERTY(EditAnywhere, Category = "Purpleprint", BlueprintReadWrite)
	EPurplePowerOfTwoCustom Height;

	UPROPERTY(EditAnywhere, Category = "Purpleprint", BlueprintReadWrite)
	FIntPoint Custom = FIntPoint(ForceInitToZero);

	FPurplePowerOfTwoResolutionCustom(EPurplePowerOfTwoCustom Width = EPurplePowerOfTwoCustom::e1024, 
										EPurplePowerOfTwoCustom Height = EPurplePowerOfTwoCustom::e1024, 
										FIntPoint Custom = FIntPoint(1024,1024))
		: Width(Width)
		, Height(Height)
		, Custom(Custom) {}
};

USTRUCT(BlueprintType)
struct FPurpleDisplayInfo
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "Purpleprint", BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, Category = "Purpleprint", BlueprintReadWrite)
	FString ID;

	UPROPERTY(EditAnywhere, Category = "Purpleprint", BlueprintReadWrite)
	int32 NativeWidth = 0;

	UPROPERTY(EditAnywhere, Category = "Purpleprint", BlueprintReadWrite)
	int32 NativeHeight = 0;

	UPROPERTY(EditAnywhere, Category = "Purpleprint", BlueprintReadWrite)
	FIntPoint MaxResolution = FIntPoint(ForceInitToZero);

	UPROPERTY(EditAnywhere, Category = "Purpleprint", BlueprintReadWrite)
	bool bIsPrimary = false;

	UPROPERTY(EditAnywhere, Category = "Purpleprint", BlueprintReadWrite)
	int32 DPI = 0;

	FPurpleDisplayInfo(FString Name = "", FString ID = "", int32 NativeWidth = 0, int32 NativeHeight = 0, 
		FIntPoint MaxResolution = FIntPoint(ForceInitToZero), bool bIsPrimary = false, int32 DPI = 0)
	: Name(Name)
	, ID(ID)
	, NativeWidth(NativeWidth)
	, NativeHeight(NativeHeight)
	, MaxResolution(MaxResolution)
	, bIsPrimary(bIsPrimary)
	, DPI(DPI) {}
};


UCLASS()
class PURPLEPRINTCORE_API UPurpleprintCorePlatform : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

	UPurpleprintCorePlatform( const FObjectInitializer& ObjectInitializer );
private:

protected:

public:
	
	// Returns the full name of a UObject.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Editor")
	static FString GetObjectFullName(UObject* Object);

	// Returns the name of a soft object reference.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Editor")
	static FString GetSoftObjectName(TSoftObjectPtr<UObject> InObject);

	// Returns the name of the persistent level.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Editor", meta = (WorldContext = "WorldContextObject"))
	static FName GetPersistentLevelName(class UObject* WorldContextObject);

	// Returns the stream level name from an actor.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Editor")
	static FName GetStreamLevelNameFromActor(AActor* Actor);

	// Returns the stream level name from a world reference.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Editor")
	static FName GetStreamLevelNameFromReference(const TSoftObjectPtr<UWorld> World);

	// Extracts a valid asset name from a string.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Editor")
	static FName GetCorrectAssetName(const FString String);

	// Returns true if the build is an editor build.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Version", meta = (BlueprintThreadSafe))
	static bool IsEditorBuild();

	// Returns true if the build is a debug build.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Version", meta = (BlueprintThreadSafe))
	static bool IsDebugBuild();

	// Returns true if the build is a development build.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Version", meta = (BlueprintThreadSafe))
	static bool IsDevelopmentBuild();

	// Returns true if the build is a shipping build.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Version", meta = (BlueprintThreadSafe))
	static bool IsShippingBuild();

	// Returns the resolution of the primary monitor.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Monitor", Meta = (Keywords = "screen size desktop"))
	static void GetPrimaryMonitorResolution(int32& Width, int32& Height);

	// Returns information about all connected monitors.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Monitor", Meta = (Keywords = "screen size desktop"))
	static TArray<FPurpleDisplayInfo> GetMonitorsInfo();

	// Returns the number of connected monitors.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Monitor", Meta = (Keywords = "screen size desktop"))
	static int32 GetMonitorsNum();

	// Returns information about the primary monitor.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Monitor", Meta = (Keywords = "screen size desktop"))
	static FPurpleDisplayInfo GetPrimaryMonitorInfo();

	// Returns the index of the primary monitor.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Monitor", Meta = (Keywords = "screen size desktop"))
	static int32 GetPrimaryMonitorIndex();

	// Returns the name of the primary monitor.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Monitor", Meta = (Keywords = "screen size desktop"))
	static FString GetPrimaryMonitorName();

	// Returns true if the specified index is the primary monitor.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Monitor", Meta = (Keywords = "screen size desktop"))
	static bool IsIndexPrimaryMonitor(const int32 Index);

	// Returns monitor info by index.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Monitor", Meta = (Keywords = "screen size desktop"))
	static FPurpleDisplayInfo GetMonitorInfoByIndex(const int32 Index);

	// Returns the monitor name for a given index.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Monitor", Meta = (Keywords = "screen size desktop"))
	static FString GetMonitorName(const int32 Index);

	// Returns a list of supported fullscreen resolutions by monitor index. (not exposed to Blueprints FIntPoint)
	static bool GetSupportedFullscreenResolutionsByIndex(TArray<FIntPoint>& Resolutions, const int32 Index);

	// Converts a DateTime to a Unix timestamp (int32).
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Date")
	static int32 DateTimeToUnixTimeStamp(const FDateTime& DateTime);

	// Converts a DateTime to a Unix timestamp (int64).
	static int64 DateTimeToUnixTimeStamp64(const FDateTime& DateTime);

	// Returns the CPU brand name.
	UFUNCTION(BlueprintPure, meta = (Keywords = "CPU brand"), Category = "Purpleprint|Platform")
	static FString GetCPUBrandName();

	// Returns the CPU vendor name.
	UFUNCTION(BlueprintPure, meta = (Keywords = "CPU vendor"), Category = "Purpleprint|Platform")
	static FString GetCPUVendorName();

	// Returns the number of CPU cores.
	UFUNCTION(BlueprintPure, meta = (Keywords = "CPU cores"), Category = "Purpleprint|Platform")
	static int32 GetCPUCores();

	// Returns the GPU brand name.
	UFUNCTION(BlueprintPure, meta = (Keywords = "GPU brand"), Category = "Purpleprint|Platform")
	static FString GetGPUBrandName();

	// Returns GPU driver information.
	UFUNCTION(BlueprintPure, meta = (Keywords = "GPU driver"), Category = "Purpleprint|Platform")
	static FString GetGPUDriverInfo();

	// Returns the OS version.
	UFUNCTION(BlueprintPure, meta = (Keywords = "OS version"), Category = "Purpleprint|Platform")
	static FString GetOSVersion();

	// Returns a string representation of the network role.
	UFUNCTION(BlueprintPure, meta = (Keywords = "net role"), Category = "Purpleprint|Networking")
	static FString GetNetRoleString(const ENetRole Role);

	// Returns a string representation of the network mode (not exposed to Blueprints ENetMode).
	static FString GetNetModeString(const ENetMode Mode);

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Platform|Editor")
	static bool SavePackages(TArray<UPackage*> Packages, bool bPrompt = true);
	
	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Platform|Editor")
	static bool SaveObjects(TArray<UObject*> Objects, bool bPrompt = true);

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Platform|Editor")
	static bool SavePackage(UPackage* Package, bool bPrompt = true);

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Platform|Editor")
	static bool SaveObject(UObject* Object, bool bPrompt = true);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|IO")
	static FDateTime GetFileModificationTime(const FString& FilePath);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|IO")
	static int64 GetFileSize(const FString& FilePath);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|IO")
	static FString GetFileMD5(const FString& FilePath);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|IO")
	static bool CompareMD5Hashes(const FString& FilePathA, const FString& FilePathB);
};