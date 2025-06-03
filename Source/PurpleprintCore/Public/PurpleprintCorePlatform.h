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


#include "Engine.h"
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
	
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Editor")
	static FString GetObjectFullName(UObject* Object);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Editor")
	static FString GetSoftObjectName(TSoftObjectPtr<UObject> InObject);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Editor", meta = (WorldContext = "WorldContextObject"))
	static FName GetPersistentLevelName(class UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Editor")
	static FName GetStreamLevelNameFromActor(AActor* Actor);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Editor")
	static FName GetStreamLevelNameFromReference(const TSoftObjectPtr<UWorld> World);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Editor")
	static FName GetCorrectAssetName(const FString String);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Version", meta = (BlueprintThreadSafe))
	static bool IsEditorBuild();

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Version", meta = (BlueprintThreadSafe))
	static bool IsDebugBuild();

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Version", meta = (BlueprintThreadSafe))
	static bool IsDevelopmentBuild();

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Version", meta = (BlueprintThreadSafe))
	static bool IsShippingBuild();

	//Returns the primary monitor resolution.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Monitor", Meta = (Keywords = "screen size desktop"))
	static void GetPrimaryMonitorResolution(int32& Width, int32& Height);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Monitor", Meta = (Keywords = "screen size desktop"))
	static TArray<FPurpleDisplayInfo> GetMonitorsInfo();

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Monitor", Meta = (Keywords = "screen size desktop"))
	static int32 GetMonitorsNum();

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Monitor", Meta = (Keywords = "screen size desktop"))
	static FPurpleDisplayInfo GetPrimaryMonitorInfo();

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Monitor", Meta = (Keywords = "screen size desktop"))
	static int32 GetPrimaryMonitorIndex();

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Monitor", Meta = (Keywords = "screen size desktop"))
	static FString GetPrimaryMonitorName();

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Monitor", Meta = (Keywords = "screen size desktop"))
	static bool IsIndexPrimaryMonitor(const int32 Index);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Monitor", Meta = (Keywords = "screen size desktop"))
	static FPurpleDisplayInfo GetMonitorInfoByIndex(const int32 Index);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Monitor", Meta = (Keywords = "screen size desktop"))
	static FString GetMonitorName(const int32 Index);

	// FIntPoint not exposed to Blueprints sadly
	static bool GetSupportedFullscreenResolutionsByIndex(TArray<FIntPoint>& Resolutions, const int32 Index);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Platform|Date")
	static int32 DateTimeToUnixTimeStamp(const FDateTime& DateTime);

	static int64 DateTimeToUnixTimeStamp64(const FDateTime& DateTime);

	UFUNCTION(BlueprintPure, meta = (Keywords = "CPU brand"), Category = "Purpleprint|Platform") //Set your category
	static FString GetCPUBrandName();

	UFUNCTION(BlueprintPure, meta = (Keywords = "CPU vendor"), Category = "Purpleprint|Platform")
	static FString GetCPUVendorName();

	UFUNCTION(BlueprintPure, meta = (Keywords = "CPU cores"), Category = "Purpleprint|Platform")
	static int32 GetCPUCores();

	UFUNCTION(BlueprintPure, meta = ( Keywords = "GPU brand"), Category = "Purpleprint|Platform")
	static FString GetGPUBrandName();

	UFUNCTION(BlueprintPure, meta = (Keywords = "GPU driver"), Category = "Purpleprint|Platform")
	static FString GetGPUDriverInfo();

	UFUNCTION(BlueprintPure, meta = (Keywords = "OS version"), Category = "Purpleprint|Platform")
	static FString GetOSVersion();

	UFUNCTION(BlueprintPure, meta = (Keywords = "net role"), Category = "Purpleprint|Networking")
	static FString GetNetRoleString(const ENetRole Role);

	// Undefined for Blueprints so cannot be exposed
	static FString GetNetModeString(const ENetMode Mode);
};