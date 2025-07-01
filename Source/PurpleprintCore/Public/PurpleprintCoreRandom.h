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
PurpleprintCoreRandom.h
================================================
*/

#pragma once

#include "CoreMinimal.h"
#include "Containers/Map.h"
#include "PurpleprintCoreMisc.h"
#include "PurpleprintCoreRandom.generated.h"


UCLASS()
class PURPLEPRINTCORE_API UPurpleprintCoreRandom : public UBlueprintFunctionLibrary 
{
	GENERATED_BODY()

	UPurpleprintCoreRandom( const FObjectInitializer& ObjectInitializer );
private:

protected:

public:

	// Returns a pseudo-random integer index based on weights.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Index Based In Weights"), Category = "Purpleprint|Random")
	static int32 GetRandomIndexByWeight(const TArray<float> Weights);

	// Returns a pseudo-random integer index based on weights using a random stream.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Index Based In Weights Stream"), Category = "Purpleprint|Random")
	static int32 GetRandomIndexByWeightStream(FRandomStream const& Stream, const TArray<float> Weights);

	// Returns a pseudo-random integer index based on weights. Don't checks for empty arrays.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Index Based In Weights Unsafe"), Category = "Purpleprint|Random")
	static int32 GetRandomIndexByWeightUnsafe(const TArray<float> Weights);

	// Returns a pseudo-random integer index based on weights using a random stream. Don't checks for empty arrays.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Index Based In Weights Stream Unsafe"), Category = "Purpleprint|Random")
	static int32 GetRandomIndexByWeightUnsafeStream(FRandomStream const& Stream, const TArray<float> Weights);


	// Returns a random FVector between Min and Max.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Vector (Single Call)"), Category = "Purpleprint|Random")
	static FVector RandomVector(FVector Min, FVector Max);

	// Returns a random FVector between Min and Max using a random stream.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Vector Stream (Single Call)"), Category = "Purpleprint|Random")
	static FVector RandomVectorStream(FRandomStream const& Stream, FVector Min, FVector Max);

	// Returns a random FVector within a bounding box.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Vector Box (Single Call)"), Category = "Purpleprint|Random")
	static FVector RandomVectorBox(FBox Range);

	// Returns a random FVector within a bounding box using a random stream.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Vector Box Stream (Single Call)"), Category = "Purpleprint|Random")
	static FVector RandomVectorBoxStream(FRandomStream const& Stream, FBox Range);

	// Returns a random FRotator within a bounding box.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Rotator Box (Single Call)"), Category = "Purpleprint|Random")
	static FRotator RandomRotatorBox(FBox Range);

	// Returns a random FRotator within a bounding box using a random stream.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Rotator Box Stream (Single Call)"), Category = "Purpleprint|Random")
	static FRotator RandomRotatorBoxStream(FRandomStream const& Stream, FBox Range);

	// Returns a random integer within an integer range.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Int Range"), Category = "Purpleprint|Random")
	static int32 RandomIntRange(FInt32Range Range);

	// Returns a random integer within an integer range using a random stream.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Int Range Stream"), Category = "Purpleprint|Random")
	static int32 RandomIntRangeStream(FRandomStream const& Stream, FInt32Range Range);

	// Returns a random float within a float range.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Float Range"), Category = "Purpleprint|Random")
	static float RandomFloatRange(FFloatRange Range);

	// Returns a random float within a float range using a random stream.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Float Range Stream"), Category = "Purpleprint|Random")
	static float RandomFloatRangeStream(FRandomStream const& Stream, FFloatRange Range);

	// Returns a random integer within an integer range.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Random")
	static int32 RandomPurpleIntRange(FPurpleIntRange Range);

	// Returns a random integer within an integer range using a random stream.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Random")
	static int32 RandomPurpleIntRangeStream(FRandomStream const& Stream, FPurpleIntRange Range);

	// Returns a random float within a float range.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Random")
	static float RandomPurpleFloatRange(FPurpleFloatRange Range);

	// Returns a random float within a float range using a random stream.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Random")
	static float RandomPurpleFloatRangeStream(FRandomStream const& Stream, FPurpleFloatRange Range);

	// Returns a random integer within an integer range.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Random")
	static int32 RandomPurpleIntRangeBound(FPurpleIntRangeBound Range);

	// Returns a random integer within an integer range using a random stream.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Random")
	static int32 RandomPurpleIntRangeBoundStream(FRandomStream const& Stream, FPurpleIntRangeBound Range);

	// Returns a random float within a float range.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Random")
	static float RandomPurpleFloatRangeBound(FPurpleFloatRangeBound Range);

	// Returns a random float within a float range using a random stream.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Random")
	static float RandomPurpleFloatRangeBoundStream(FRandomStream const& Stream, FPurpleFloatRangeBound Range);

	// Returns a random point within a circle.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Random")
	static FVector2D GetRandomPointInCircle(const float Radius = 100.f, const float InnerRadius = 0.0f);

	// Returns a random point within a circle using a random stream.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Random")
	static FVector2D GetRandomPointInCircleStream(FRandomStream const& Stream, const float Radius = 100.f, const float InnerRadius = 0.0f);

	// Returns a random point within a sphere.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Random")
	static FVector GetRandomPointInSphere(const float Radius = 100.f, const FVector Origin = FVector::ZeroVector);

	// Returns a random point within a sphere using a random stream.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Random")
	static FVector GetRandomPointInSphereStream(FRandomStream const& Stream, const float Radius = 100.f, const FVector Origin = FVector::ZeroVector);

	// Returns a random point within a bounding box using a random stream.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Random")
	static FVector GetRandomPointInBoundingBoxStream(FRandomStream const& Stream, const FVector BoxExtent, const FVector Origin = FVector::ZeroVector);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Random")
	static FVector2D GetRandomPointInBiasCircle(const float MinRadius = 0.f, const float MaxRadius = 1.f);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Random")
	static FVector GetRandomPointInBiasSphere(const float MinRadius = 0.f, const float MaxRadius = 1.0f, const FVector Origin = FVector::ZeroVector);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Random")
	static FVector GetRandomPointInBiasBoundingBox(const FVector MinExtent = FVector::ZeroVector, const FVector MaxExtent = FVector(1.0f, 1.0f, 1.0f),
													const FVector Origin = FVector::ZeroVector);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Random")
	static FVector2D GetRandomPointInBiasCircleStream(FRandomStream const& Stream, const float MinRadius = 0.f, const float MaxRadius = 1.f);
	
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Random")
	static FVector GetRandomPointInBiasSphereStream(FRandomStream const& Stream, const float MinRadius = 0.f, const float MaxRadius = 1.0f, 
													const FVector Origin = FVector::ZeroVector);
	
	// Get random points in a box using a bias to define the minimum and maximum of it
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Random")
	static FVector GetRandomPointInBiasBoundingBoxStream(FRandomStream const& Stream, const FVector MinExtent = FVector::ZeroVector,
		const FVector MaxExtent = FVector(1.0f, 1.0f, 1.0f), const FVector Origin = FVector::ZeroVector,
		bool bUseExpensiveMethod = false);
};