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
#include "PurpleprintCoreRandom.generated.h"


UCLASS()
class PURPLEPRINTCORE_API UPurpleprintCoreRandom : public UBlueprintFunctionLibrary 
{
	GENERATED_BODY()

	UPurpleprintCoreRandom( const FObjectInitializer& ObjectInitializer );
private:

protected:

public:

	// Returns a pseudo - random integer index based on weights.
	UFUNCTION( BlueprintPure, meta = ( DisplayName = "Random Index Based In Weights" ), Category = "Purpleprint|Random" )
	static int32 GetRandomIndexByWeight( const TArray<float> Weights);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Index Based In Weights"), Category = "Purpleprint|Random")
	static int32 GetRandomIndexByWeightStream(FRandomStream const& Stream, const TArray<float> Weights);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Vector (Single Call)"), Category = "Purpleprint|Random")
	static FVector RandomVector(FVector Min, FVector Max);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Vector Stream (Single Call)"), Category = "Purpleprint|Random")
	static FVector RandomVectorStream(FRandomStream const& Stream, FVector Min, FVector Max);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Vector Box (Single Call)"), Category = "Purpleprint|Random")
	static FVector RandomVectorBox(FBox Range);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Vector Box Stream (Single Call)"), Category = "Purpleprint|Random")
	static FVector RandomVectorBoxStream(FRandomStream const& Stream, FBox Range);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Rotator Box (Single Call)"), Category = "Purpleprint|Random")
	static FRotator RandomRotatorBox(FBox Range);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Rotator Box Stream (Single Call)"), Category = "Purpleprint|Random")
	static FRotator RandomRotatorBoxStream(FRandomStream const& Stream, FBox Range);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Int Range"), Category = "Purpleprint|Random")
	static int32 RandomRange(FInt32Range Range);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Int Range Stream"), Category = "Purpleprint|Random")
	static int32 RandomRangeStream(FRandomStream const& Stream, FInt32Range Range);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Float Range"), Category = "Purpleprint|Random")
	static float RandomFloatRange(FFloatRange Range);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Random Float Range Stream"), Category = "Purpleprint|Random")
	static float RandomFloatRangeStream(FRandomStream const& Stream, FFloatRange Range);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Random")
	static FVector2D GetRandomPointInCircle(const float Radius = 100.f, const float InnerRadius = 0.0f);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Random")
	static FVector2D GetRandomPointInCircleStream(FRandomStream const& Stream, const float Radius = 100.f, const float InnerRadius = 0.0f);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Random")
	static FVector GetRandomPointInSphere(const float Radius = 100.f, const bool bAlt = false, const FVector Location = FVector::ZeroVector);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Random")
	static FVector GetRandomPointInSphereStream(FRandomStream const& Stream, const float Radius = 100.f, const bool bAlt = false, const FVector Location = FVector::ZeroVector);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Random")
	static FVector GetRandomPointInBoundingBoxStream(FRandomStream const& Stream, const FVector Origin, const FVector BoxExtent);
};