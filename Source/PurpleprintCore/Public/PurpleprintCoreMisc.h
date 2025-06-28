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
PurpleprintCoreMisc.h
================================================
*/

#pragma once

#include "CoreMinimal.h"
#include "Misc/EnumRange.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "Engine/EngineTypes.h"
#include "CollisionQueryParams.h"
#include "PurpleprintCoreMath.h"
#include "Engine/TextureDefines.h"
#include "RenderUtils.h"
#include "PurpleprintCoreMisc.generated.h"

class UPrimitiveComponent;
class AStaticMeshActor;
class UMaterialInterface;
class UDecalComponent;
class UNiagaraComponent;
class UParticleSystemComponent;

USTRUCT(BlueprintType)
struct FPurpleIntRangeBound
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Range)
	int32 Min = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Range)
	int32 Max = 1;

	UPROPERTY()
	int32 MinBound = 0;

	UPROPERTY()
	int32 MaxBound = 1;

	FPurpleIntRangeBound(int32 MinValue = 0, int32 MaxValue = 1, int32 MinBoundValue = 0, int32 MaxBoundValue = 1)
		: Min(MinValue), Max(MaxValue), MinBound(MinBoundValue), MaxBound(MaxBoundValue)
	{}

	bool operator==(const FPurpleIntRangeBound& Other) const
	{
		return Min == Other.Min && Max == Other.Max && MinBound == Other.MinBound && MaxBound == Other.MaxBound;
	}

	void Normalize()
	{
		if (Min > Max)
		{
			Swap(Min, Max);
		}
		if (MinBound > MaxBound)
		{
			Swap(MinBound, MaxBound);
		}
	}

	void NormalizeClamp()
	{
		Normalize();
		Min = FMath::Clamp(Min, MinBound, MaxBound);
		Max = FMath::Clamp(Max, MinBound, MaxBound);
	}

	void Set(int32 MinValue = 0, int32 MaxValue = 1)
	{
		Min = MinValue;
		Max = MaxValue;
		NormalizeClamp();
	}

	void SetClamp(int32 MinValue = 0, int32 MaxValue = 1, int32 MinBoundValue = 0, int32 MaxBoundValue = 1)
	{
		Min = MinValue;
		Max = MaxValue;
		MinBound = MinBoundValue;
		MaxBound = MaxBoundValue;
		NormalizeClamp();
	}

	void SetClamp(int32 MinBoundValue = 0, int32 MaxBoundValue = 1)
	{
		MinBound = MinBoundValue;
		MaxBound = MaxBoundValue;
		NormalizeClamp();
	}
};

USTRUCT(BlueprintType)
struct FPurpleFloatRangeBound
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Range)
	float Min = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Range)
	float Max = 1.0f;

	UPROPERTY()
	float MinBound = 0.0f;

	UPROPERTY()
	float MaxBound = 1.0f;

	FPurpleFloatRangeBound(float MinValue = 0.0f, float MaxValue = 1.0f, float MinBoundValue = 0.0f, float MaxBoundValue = 1.0f)
		: Min(MinValue), Max(MaxValue), MinBound(MinBoundValue), MaxBound(MaxBoundValue)
	{
	}

	bool operator==(const FPurpleFloatRangeBound& Other) const
	{
		return Min == Other.Min && Max == Other.Max && MinBound == Other.MinBound && MaxBound == Other.MaxBound;
	}

	void Normalize()
	{
		if (Min > Max)
		{
			Swap(Min, Max);
		}
		if (MinBound > MaxBound)
		{
			Swap(MinBound, MaxBound);
		}
	}

	void NormalizeClamp()
	{
		Normalize();
		Min = FMath::Clamp(Min, MinBound, MaxBound);
		Max = FMath::Clamp(Max, MinBound, MaxBound);
	}

	void Set(float MinValue = 0.0f, float MaxValue = 1.0f)
	{
		Min = MinValue;
		Max = MaxValue;
		NormalizeClamp();
	}

	void SetClamp(float MinValue = 0.0f, float MaxValue = 1.0f, float MinBoundValue = 0.0f, float MaxBoundValue = 1.0f)
	{
		Min = MinValue;
		Max = MaxValue;
		MinBound = MinBoundValue;
		MaxBound = MaxBoundValue;
		NormalizeClamp();
	}

	void SetClamp(float MinBoundValue = 0.0f, float MaxBoundValue = 1.0f)
	{
		MinBound = MinBoundValue;
		MaxBound = MaxBoundValue;
		NormalizeClamp();
	}
};

USTRUCT(BlueprintType)
struct FPurpleIntRange
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Range)
	int32 Min = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Range)
	int32 Max = 1;

	FPurpleIntRange(int32 MinValue = 0, int32 MaxValue = 1)
		: Min(MinValue), Max(MaxValue)
	{}

	bool operator==(const FPurpleIntRange& Other) const
	{
		return Min == Other.Min && Max == Other.Max;
	}

	void Normalize()
	{
		if (Min > Max)
		{
			Swap(Min, Max);
		}
	}

	void NormalizeClamp(int32 MinBoundValue = 0, int32 MaxBoundValue = 1)
	{
		Normalize();
		int32 minBound = MinBoundValue;
		int32 maxBound = MaxBoundValue;
		if (minBound > maxBound)
		{
			Swap(minBound, maxBound);
		}
		Min = FMath::Clamp(Min, minBound, maxBound);
		Max = FMath::Clamp(Max, minBound, maxBound);
	}

	void Set(int32 MinValue = 0, int32 MaxValue = 1)
	{
		Min = MinValue;
		Max = MaxValue;
		Normalize();
	}

	void SetClamp(int32 MinValue = 0, int32 MaxValue = 1, int32 MinBoundValue = 0, int32 MaxBoundValue = 1)
	{
		Min = MinValue;
		Max = MaxValue;
		NormalizeClamp(MinBoundValue, MaxBoundValue);
	}
};

USTRUCT(BlueprintType)
struct FPurpleFloatRange
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Range)
	float Min = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Range)
	float Max = 1.0f;

	FPurpleFloatRange(float MinValue = 0.0f, float MaxValue = 1.0f)
		: Min(MinValue), Max(MaxValue)
	{}

	bool operator==(const FPurpleFloatRange& Other) const
	{
		return Min == Other.Min && Max == Other.Max;
	}

	void Normalize()
	{
		if (Min > Max)
		{
			Swap(Min, Max);
		}
	}

	void NormalizeClamp(float MinBoundValue = 0.0f, float MaxBoundValue = 1.0f)
	{
		Normalize();
		float minBound = MinBoundValue;
		float maxBound = MaxBoundValue;
		if (minBound > maxBound)
		{
			Swap(minBound, maxBound);
		}
		Min = FMath::Clamp(Min, minBound, maxBound);
		Max = FMath::Clamp(Max, minBound, maxBound);
	}

	void Set(float MinValue = 0.0f, float MaxValue = 1.0f)
	{
		Min = MinValue;
		Max = MaxValue;
		Normalize();
	}

	void SetClamp(float MinValue = 0.0f, float MaxValue = 1.0f, float MinBoundValue = 0.0f, float MaxBoundValue = 1.0f)
	{
		Min = MinValue;
		Max = MaxValue;
		NormalizeClamp(MinBoundValue, MaxBoundValue);
	}
};

UENUM(BlueprintType, meta = (Bitflags))
enum class EPurpleTransformBitMaskList : uint8
{
	eNone = 0			UMETA(DisplayName = "None"),
	eLocation = 1 << 0	UMETA(DisplayName = "Location"),
	eRotation = 1 << 1	UMETA(DisplayName = "Rotation"),
	eScale = 1 << 2		UMETA(DisplayName = "Scale")
};

USTRUCT(BlueprintType)
struct FPurpleTransformBitMask
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Transform)
	uint8 bLocation : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Transform)
	uint8 bRotation : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Transform)
	uint8 bScale : 1;

	FPurpleTransformBitMask() :
		bLocation(true),
		bRotation(false),
		bScale(false)
	{}

	bool operator==(const FPurpleTransformBitMask& Other) const
	{
		return bLocation == Other.bLocation && bRotation == Other.bRotation 
			&& bScale == Other.bScale;
	}

	uint8 GetBitMask() const
	{
		return (uint8)((bLocation ? 1 : 0) | (bRotation << 1) | (bScale << 2));
	}
};


inline uint8 GetPurpleTransformBitMaskForStruct(FPurpleTransformBitMask Value)
{
	return (uint8)((Value.bLocation ? 1 : 0) | (Value.bRotation << 1) | (Value.bScale << 2));
}

USTRUCT(BlueprintType)
struct FPurpleVectorBitMask
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Transform)
	uint8 bX : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Transform)
	uint8 bY : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Transform)
	uint8 bZ : 1;

	FPurpleVectorBitMask() :
		bX(true),
		bY(true),
		bZ(true)
	{
	}

	bool operator==(const FPurpleVectorBitMask& Other) const
	{
		return bX == Other.bX && bY == Other.bY
			&& bZ == Other.bZ;
	}

	const

		uint8 GetBitMask() const
	{
		return (uint8)((bX ? 1 : 0) | (bY << 1) | (bZ << 2));
	}
};

inline uint8 GetPurpleVectorBitMaskForStruct(FPurpleVectorBitMask Value)
{
	return (uint8)((Value.bX ? 1 : 0) | (Value.bY << 1) | (Value.bZ << 2));
}

UENUM(BlueprintType)
enum class EPurpleCommonCollisionProfile : uint8
{
	eCustom					UMETA(DisplayName = "Custom"),
	eNoCollision			UMETA(DisplayName = "NoCollision"),
	eBlockAll				UMETA(DisplayName = "BlockAll"),
	eOverlapAll				UMETA(DisplayName = "OverlapAll"),
	eBlockAllDynamic		UMETA(DisplayName = "BlockAllDynamic"),
	eOverlapAllDynamic		UMETA(DisplayName = "OverlapAllDynamic"),
	eIgnoreOnlyPawn			UMETA(DisplayName = "IgnoreOnlyPawn"),
	ePawn					UMETA(DisplayName = "Pawn"),
	eSpectator				UMETA(DisplayName = "Spectator"),
	eCharacterMesh			UMETA(DisplayName = "CharacterMesh"),
	ePhysicsActor			UMETA(DisplayName = "PhysicsActor"),
	eDestructible			UMETA(DisplayName = "Destructible"),
	eInvisibleWall			UMETA(DisplayName = "InvisibleWall"),
	eInvisibleWallDynamic	UMETA(DisplayName = "InvisibleWallDynamic"),
	eTrigger				UMETA(DisplayName = "Trigger"),
	eRagdoll				UMETA(DisplayName = "Ragdoll"),
	eVehicle				UMETA(DisplayName = "Vehicle"),
	eUI						UMETA(DisplayName = "UI"),
};
ENUM_RANGE_BY_FIRST_AND_LAST(EPurpleCommonCollisionProfile, EPurpleCommonCollisionProfile::eCustom, EPurpleCommonCollisionProfile::eUI);

UENUM(BlueprintType)
enum class EPurpleCoreGenericAxis : uint8
{
	eX		UMETA(DisplayName = "X"),
	eY		UMETA(DisplayName = "Y"),
	eZ		UMETA(DisplayName = "Z")
};
ENUM_RANGE_BY_FIRST_AND_LAST(EPurpleCoreGenericAxis, EPurpleCoreGenericAxis::eX, EPurpleCoreGenericAxis::eZ);

UENUM(BlueprintType)
enum class EPurpleCoreAlignAxis : uint8 
{
	eFree	UMETA(DisplayName = "Free"),
	eX		UMETA(DisplayName = "X+"),
	eY		UMETA(DisplayName = "Y+"),
	eZ		UMETA(DisplayName = "Z+"),
	eXN		UMETA(DisplayName = "X-"),
	eYN		UMETA(DisplayName = "Y-"),
	eZN		UMETA(DisplayName = "Z-"),
	eCustom UMETA(DisplayName = "Custom")
};
ENUM_RANGE_BY_FIRST_AND_LAST(EPurpleCoreAlignAxis, EPurpleCoreAlignAxis::eFree, EPurpleCoreAlignAxis::eCustom);


UENUM(BlueprintType)
enum class EPurpleCoreAxis : uint8 
{
	eX		UMETA(DisplayName = "X+"),
	eY		UMETA(DisplayName = "Y+"),
	eZ		UMETA(DisplayName = "Z+"),
	eXN		UMETA(DisplayName = "X-"),
	eYN		UMETA(DisplayName = "Y-"),
	eZN		UMETA(DisplayName = "Z-"),
	eCustom UMETA(DisplayName = "Custom")
};
ENUM_RANGE_BY_FIRST_AND_LAST(EPurpleCoreAxis, EPurpleCoreAxis::eX, EPurpleCoreAxis::eZN);


USTRUCT(BlueprintType)
struct FPurpleTraceStruct 
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace", meta = (EditCondition = "Direction!=EPurpleCoreAxis::eCustom"))
	FVector Origin = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
	float Length = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
	EPurpleCoreAxis Direction = EPurpleCoreAxis::eZN;

	// Alternative vector manually set
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace", meta = (EditCondition = "Direction!=EPurpleCoreAxis::eCustom"))
	FVector DirectionVector = FVector(0.f, 0.f, -1.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
	TEnumAsByte<ETraceTypeQuery> Channel = ETraceTypeQuery::TraceTypeQuery1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
	bool bComplex = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
	bool bIgnoreSelf = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actors")
	TArray<AActor*> ActorsToIgnore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
	bool bDebug = false;

	FPurpleTraceStruct() {
		Origin = FVector::ZeroVector;
		Length = 500.f;
		Direction = EPurpleCoreAxis::eZN;
		DirectionVector = FVector(0.f, 0.f, -1.f);
		Channel = ETraceTypeQuery::TraceTypeQuery1;
		bComplex = true;
		bIgnoreSelf = true;
		ActorsToIgnore = TArray<AActor*>();
		bDebug = false;
	}

	bool operator==(const FPurpleTraceStruct& Other) const
	{
		return Origin.Equals(Other.Origin) &&
			FMath::IsNearlyEqual(Length, Other.Length) &&
			Direction == Other.Direction &&
			DirectionVector.Equals(Other.DirectionVector) &&
			Channel == Other.Channel &&
			bComplex == Other.bComplex &&
			bIgnoreSelf == Other.bIgnoreSelf &&
			ActorsToIgnore == Other.ActorsToIgnore &&
			bDebug == Other.bDebug;
	}
};

USTRUCT(BlueprintType)
struct FPurpleTraceAlignStruct 
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace", meta = (EditCondition = "Direction==EPurpleCoreAlignAxis::eCustom"))
	FVector Origin = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace", meta = (EditCondition = "Direction!=EPurpleCoreAlignAxis::eFree"))
	float Length = 1500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
	EPurpleCoreAlignAxis Direction = EPurpleCoreAlignAxis::eFree;

	// Alternative vector manually set
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace", meta = (EditCondition = "Direction==EPurpleCoreAlignAxis::eCustom"))
	FVector DirectionVector = FVector(0.f, 0.f, -1.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace", meta = (EditCondition = "Direction!=EPurpleCoreAlignAxis::eFree"))
	TEnumAsByte<ETraceTypeQuery> Channel = ETraceTypeQuery::TraceTypeQuery1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace", meta = (EditCondition = "Direction!=EPurpleCoreAlignAxis::eFree"))
	bool bComplex = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace", meta = (EditCondition = "Direction!=EPurpleCoreAlignAxis::eFree"))
	bool bIgnoreSelf = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actors", meta = (EditCondition = "Direction!=EPurpleCoreAlignAxis::eFree"))
	TArray<AActor*> ActorsToIgnore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Align", meta = (EditCondition = "Direction!=EPurpleCoreAlignAxis::eFree"))
	bool bAlignNormal = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Align", meta = (EditCondition = "Direction!=EPurpleCoreAlignAxis::eFree"))
	FVector AlignNormalMask = FVector(0.f, 0.f, 1.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug", meta = (EditCondition = "Direction!=EPurpleCoreAlignAxis::eFree"))
	bool bDebug = false;


	FPurpleTraceAlignStruct() 
	{
		Origin = FVector::ZeroVector;
		Length = 1500.f;
		Direction = EPurpleCoreAlignAxis::eFree;
		DirectionVector = FVector(0.f, 0.f, -1.f);
		Channel = ETraceTypeQuery::TraceTypeQuery1;
		bComplex = true;
		bIgnoreSelf = true;
		ActorsToIgnore = TArray<AActor*>();
		bAlignNormal = true;
		AlignNormalMask = FVector(0.f, 0.f, 1.f);
		bDebug = false;
	}

	bool operator==(const FPurpleTraceAlignStruct& Other) const
	{
		return Origin.Equals(Other.Origin) &&
			FMath::IsNearlyEqual(Length, Other.Length) &&
			Direction == Other.Direction &&
			DirectionVector.Equals(Other.DirectionVector) &&
			Channel == Other.Channel &&
			bComplex == Other.bComplex &&
			bIgnoreSelf == Other.bIgnoreSelf &&
			ActorsToIgnore == Other.ActorsToIgnore &&
			bAlignNormal == Other.bAlignNormal &&
			AlignNormalMask.Equals(Other.AlignNormalMask) &&
			bDebug == Other.bDebug;
	}
};

#if WITH_EDITORONLY_DATA
DECLARE_DELEGATE_RetVal(FTransform, FEditorCameraLocationDelegate);
#endif

UCLASS()
class PURPLEPRINTCORE_API UPurpleprintCoreMisc : public UBlueprintFunctionLibrary 
{
	GENERATED_BODY()

	UPurpleprintCoreMisc( const FObjectInitializer& ObjectInitializer );
private:

protected:

public:

#if WITH_EDITORONLY_DATA
	static FEditorCameraLocationDelegate EditorCameraLocationDelegate;
#endif

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Placer|Utils")
	static FName EnumToNameCommonCollisionProfile(EPurpleCommonCollisionProfile EnumValue);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Placer|Utils")
	static EPurpleCommonCollisionProfile NameToEnumCommonCollisionProfile(const FName& ShortName);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Utils")
	static bool AreTransformArraysEqual(const TArray<FTransform>& A, const TArray<FTransform>& B);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Utils")
	static EPurpleCoreAxis PurpleCoreAlignAxisToAxis(EPurpleCoreAlignAxis Align);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Utils")
	static EPurpleCoreAlignAxis PurpleCoreAxisToAlignAxis(EPurpleCoreAxis Axis);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Utils")
	static FVector GetAxisVectorFromTransform(const FTransform& Transform, EPurpleCoreAxis Align);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Utils")
	static FVector GetAlignVectorFromTransform(const FTransform& Transform, EPurpleCoreAlignAxis Align);

	/** Returns FVector2D(A,B) from a float A.B */
	UFUNCTION( BlueprintCallable, Category = "Purpleprint|Vector" )
	static FVector2D FloatSplitToVector2D( const float FloatValue );

	/** Returns FVector(A,B,0) from a float A.B */
	UFUNCTION( BlueprintCallable, Category = "Purpleprint|Vector" )
	static FVector FloatSplitToVector( const float FloatValue );

	/** Returns FVector4(A,B,0,0) from a float A.B */
	UFUNCTION( BlueprintCallable, Category = "Purpleprint|Vector" )
	static FVector4 FloatSplitToVector4( const float FloatValue );

    // Returns a vector with the maximum component for each dimension from the pair of vectors.
    UFUNCTION(BlueprintPure, Category = "Purpleprint|Vector")
    static FVector MaxVector(FVector A, FVector B);

    // Returns a vector with the minimum component for each dimension from the pair of vectors.
    UFUNCTION(BlueprintPure, Category = "Purpleprint|Vector")
    static FVector MinVector(FVector A, FVector B);

    // Returns an integer vector with the maximum component for each dimension from the pair of integer vectors.
    UFUNCTION(BlueprintPure, Category = "Purpleprint|Vector")
    static FIntVector MaxIntegerVector(FIntVector A, FIntVector B);

    // Returns an integer vector with the minimum component for each dimension from the pair of integer vectors.
    UFUNCTION(BlueprintPure, Category = "Purpleprint|Vector")
    static FIntVector MinIntegerVector(FIntVector A, FIntVector B);

	// Clamps a range of integers between the specified minimum and maximum values.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Range")
	static FInt32Range ClampIntRange(const FInt32Range& Range, const int32 Min, const int32 Max);

	// Clamps a range of float between the specified minimum and maximum values.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Range")
	static FFloatRange ClampFloatRange(const FFloatRange& Range, const float Min, const float Max);

	// Clamps a range of float between the specified minimum and maximum values.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Range")
	static FBox ClampBox(const FBox& Box, FVector Min, FVector Max, bool bNormalize = true);

    // Clamps each component of a 2D vector between the corresponding components of Min and Max.
    UFUNCTION(BlueprintCallable, Category = "Purpleprint|Vector")
    static FVector2D ClampVector2D(FVector2D Value, FVector2D Min, FVector2D Max);

    // Clamps each component of a 3D vector between the corresponding components of Min and Max.
    UFUNCTION(BlueprintCallable, Category = "Purpleprint|Vector")
    static FVector ClampVector(FVector Value, FVector Min, FVector Max);

    // Clamps each component of an integer vector between the corresponding components of Min and Max.
    UFUNCTION(BlueprintPure, Category = "Purpleprint|Vector")
    static FIntVector ClampIntegerVector(FIntVector X, FIntVector Min, FIntVector Max);

    // Clamps each component of a 4D vector between the corresponding components of Min and Max.
    UFUNCTION(BlueprintCallable, Category = "Purpleprint|Vector")
    static FVector4 ClampVector4(FVector4 Value, FVector4 Min, FVector4 Max);

	/** Returns FVector2D(A,B) from the FVector(A,B,C) */
	UFUNCTION( BlueprintCallable, Category = "Purpleprint|Vector" )
	static FVector2D VectorToVector2D( const FVector &VecValue );

	/** Returns FVector2D(A,B) from the FVector4(A,B,C,D) */
	UFUNCTION( BlueprintCallable, Category = "Purpleprint|Vector" )
	static FVector2D Vector4ToVector2D( const FVector4 &Vec4Value );

	/** Returns FVector(A,B,0) from the FVector2D(A,B) */
	UFUNCTION( BlueprintCallable, Category = "Purpleprint|Vector" )
	static FVector VectorIntToVector( const FIntVector &VecIntValue );

	/** Returns FVector(A,B,0) from the FVector2D(A,B) */
	UFUNCTION( BlueprintCallable, Category = "Purpleprint|Vector" )
	static FVector Vector2DToVector( const FVector2D &Vec2Value );

	/** Returns FVector(A,B,C) from the FVector4(A,B,C,D) */
	UFUNCTION( BlueprintCallable, Category = "Purpleprint|Vector" )
	static FVector Vector4ToVector( const FVector4 &Vec4Value );

	/** Returns FVector(A,B,0) from the FVector2D(A,B) */
	UFUNCTION( BlueprintCallable, Category = "Purpleprint|Vector" )
	static FIntVector VectorToVectorInt( const FVector &VecValue );

	/** Returns FVector4(A,B,0,0) from the FVector2D(A,B) */
	UFUNCTION( BlueprintCallable, Category = "Purpleprint|Vector" )
	static FVector4 Vector2DToVector4( const FVector2D &Vec2Value );

	/** Returns FVector4(A,B,C,0) from the FVector(A,B,C) */
	UFUNCTION( BlueprintCallable, Category = "Purpleprint|Vector" )
	static FVector4 VectorToVector4( const FVector &VecValue );

	/** Returns FRotator(C,B,A) from the FRotator(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "Purpleprint|Rotator" )
	static FRotator RotatorOrderInvert( const FRotator &RotValue );

	/** Returns FVector2D(B,A) from the FVector2D(A,B) */
	UFUNCTION( BlueprintPure, Category = "Purpleprint|Vector2D" )
	static FVector2D Vector2DOrderInvert( const FVector2D &Vec2Value );

	/** Returns FVector(C,B,A) from the FVector(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "Purpleprint|Vector" )
	static FVector VectorOrderInvert( const FVector &VecValue );

	/** Returns FVector4(D,C,B,A) from the FVector4(A,B,C,D) */
	UFUNCTION( BlueprintPure, Category = "Purpleprint|Vector4" )
	static FVector4 Vector4OrderInvert( const FVector4 &Vec4Value );

	/** Returns FRotator(C,A,B) from the FRotator(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "Purpleprint|Rotator" )
	static FRotator RotatorOrderRight( const FRotator &RotValue );

	/** Returns FVector(C,A,B) from the FVector(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "Purpleprint|Vector" )
	static FVector VectorOrderRight( const FVector &VecValue );

	/** Returns FVector(D,A,B,C) from the FVector(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "Purpleprint|Vector" )
	static FVector4 Vector4OrderRight( const FVector4 &Vec4Value );

	/** Returns FRotator(B,C,A) from the FRotator(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "Purpleprint|Rotator" )
	static FRotator RotatorOrderLeft( const FRotator &RotValue );

	/** Returns FVector(B,C,A) from the FVector(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "Purpleprint|Vector" )
	static FVector VectorOrderLeft( const FVector &VecValue );

	/** Returns FVector(B,C,D,A) from the FVector(A,B,C,D) */
	UFUNCTION( BlueprintPure, Category = "Purpleprint|Vector" )
	static FVector4 Vector4OrderLeft( const FVector4 &Vec4Value );

	// Given an Alpha value get the aprox value in the array
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Array")
	static uint8 GetByteArrayAlpha(const TArray<uint8>& Array, const float Alpha);

	// Given an Alpha value get the aprox value in the array
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Array")
	static int32 GetIntegerArrayAlpha(const TArray<int32>& Array, const float Alpha);

	// Given an Alpha value get the aprox value in the array
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Array")
	static float GetFloatArrayAlpha(const TArray<float>& Array, const float Alpha);

	// Given an Alpha value get the aprox value in the array
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Array")
	static FVector2D GetVector2DArrayAlpha(const TArray<FVector2D>& Array, const float Alpha);

	// Given an Alpha value get the aprox value in the array
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Array")
	static FVector GetVectorArrayAlpha(const TArray<FVector>& Array, const float Alpha);

	// Given an Alpha value get the aprox value in the array
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Array")
	static FRotator GetRotatorArrayAlpha(const TArray<FRotator>& Array, const float Alpha);

	// Given an Alpha value get the aprox value in the array
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Array")
	static FTransform GetTransformArrayAlpha(const TArray<FTransform>& Array, const float Alpha);

	// Given an Alpha value get the aprox value in the array
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Array")
	static FTransform GetTransformArrayAlphaLerp(const TArray<FTransform>& Array, const float Alpha, const bool bLoop = false);

	// Get actice camera in editor and game location and rotation
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Camera", meta = (WorldContext = "WorldContextObject"))
	static FVector GetActiveCameraLocation(const UObject* WorldContextObject, FRotator& Rotation);

	// Spawn an actor clone with the same properties as the original actor
	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Actor", meta = (DeterminesOutputType = "Actor"))
	static AActor* SpawnActorClone(AActor* Actor, const FTransform& Transform);

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Component")
	static void CopySceneComponentParams(USceneComponent* Source, USceneComponent* Target);

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Component")
	static void CopyPrimitiveComponentParams(UPrimitiveComponent* Source, UPrimitiveComponent* Target, bool bCopyMaterials = true);
	
	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Component")
	static void CopyStaticMeshComponentParams(UStaticMeshComponent* Source, UStaticMeshComponent* Target);

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Component")
	static void CopyDecalComponentParams(UDecalComponent* Source, UDecalComponent* Target);

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Component")
	static void CopyNiagaraComponentParams(UNiagaraComponent* Source, UNiagaraComponent* Target);

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Component")
	static void CopyParticleComponentParams(UParticleSystemComponent* Source, UParticleSystemComponent* Target);

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Component")
	static FString GenerateStaticMeshRefKey(const UStaticMeshComponent* MeshComp);

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Component")
	static FString GenerateDecalRefKey(const UDecalComponent* Decal);

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Component")
	static FString GenerateNiagaraRefKey(const UNiagaraComponent* Niagara);

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Component")
	static FString GenerateEmitterRefKey(AEmitter* Emitter);

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Component")
	static FString GenerateGenericActorRefKey(const AActor* Actor);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Collison")
	static bool IsValidCollisionProfileName(FName ProfileName);

	// This function is editor only
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Collison")
	static TArray<FName> GetAllCollisionProfileNames();

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Component")
	static bool SetPrimitiveComponentMaterials(UPrimitiveComponent* Component, TArray<UMaterialInterface*> Materials);

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Actor")
	static bool SetActorStaticMeshMaterials(AStaticMeshActor* Actor, TArray<UMaterialInterface*> Materials);

	static UTexture2D* ConstructTexture2DNonPowerTwo(UTextureRenderTarget2D* RT, UObject* InOuter, const FString& NewTexName, EObjectFlags InObjectFlags, uint32 Flags = CTF_Default, TArray<uint8>* AlphaOverride = NULL);

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Texture", meta = (DisplayName = "Render Target Create Static Texture Non Power Of Two Editor Only", Keywords = "Create Static Texture from Render Target", UnsafeDuringActorConstruction = "true", DevelopmentOnly))
	static UTexture2D* RenderTargetCreateStaticTexture2DNonPowerTwoEditorOnly(UTextureRenderTarget2D* RenderTarget, FString Name = "Texture", enum TextureCompressionSettings CompressionSettings = TC_Default, enum TextureMipGenSettings MipSettings = TMGS_FromTextureGroup);

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Actor", meta = (UnsafeDuringActorConstruction = "true", DevelopmentOnly))
	static TArray<FTransform> SnapActorsToSimulatedTransform(TArray<AActor*> Actors);

	//UFUNCTION(BlueprintCallable, Category = "Purpleprint|Niagara")
	//static bool GetNiagaraVectorParamArray(UNiagaraComponent* NiagaraComponent, FName ParameterName, TArray<FVector>& OutArray);
};