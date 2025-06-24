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
PurpleprintCoreRandom.cpp
================================================
*/

#include "PurpleprintCoreRandom.h"
#include "PurpleprintCoreMath.h"


UPurpleprintCoreRandom::UPurpleprintCoreRandom( const class FObjectInitializer& ObjectInitializer ) 
{

}

// <returns>Returns a pseudo-random integer index based on weights.</returns>
int32 UPurpleprintCoreRandom::GetRandomIndexByWeight(const TArray<float> Weights) 
{
	int32 maxIndex = Weights.Num() - 1;

	if (maxIndex < 0) { return -1; }

	float tValue = 0; // Total value
	float rValue = 0; // Random value

	// Ground truth solution for correct percents
	for (int32 i = 0; i < Weights.Num(); i++)
	{
		tValue += Weights[i];
	}
	rValue = FMath::RandRange(0.0f, tValue);
	for (int32 i = 0; i < Weights.Num(); i++)
	{
		if (rValue < Weights[i])
		{
			return i;
		}
		rValue -= Weights[i];
	}
	return 0; //Never reach point
}

int32 UPurpleprintCoreRandom::GetRandomIndexByWeightStream(FRandomStream const& Stream, const TArray<float> Weights)
{
	int32 maxIndex = Weights.Num() - 1;

	if (maxIndex < 0) { return -1; }

	float tValue = 0; // Total value
	float rValue = 0; // Random value

	for (int32 i = 0; i < Weights.Num(); i++)
	{
		tValue += Weights[i];
	}
	rValue = Stream.FRandRange(0.0f, tValue);
	for (int32 i = 0; i < Weights.Num(); i++)
	{
		if (rValue < Weights[i])
		{
			return i;
		}
		rValue -= Weights[i];
	}
	return 0; //Never reach point
}

int32 UPurpleprintCoreRandom::GetRandomIndexByWeightUnsafe(const TArray<float> Weights)
{
	float tValue = 0; // Total value
	float rValue = 0; // Random value

	// Ground truth solution for correct percents
	for (int32 i = 0; i < Weights.Num(); i++)
	{
		tValue += Weights[i];
	}
	rValue = FMath::RandRange(0.0f, tValue);
	for (int32 i = 0; i < Weights.Num(); i++)
	{
		if (rValue < Weights[i])
		{
			return i;
		}
		rValue -= Weights[i];
	}
	return 0; //Never reach point
}

int32 UPurpleprintCoreRandom::GetRandomIndexByWeightUnsafeStream(FRandomStream const& Stream, const TArray<float> Weights)
{
	float tValue = 0; // Total value
	float rValue = 0; // Random value

	for (int32 i = 0; i < Weights.Num(); i++)
	{
		tValue += Weights[i];
	}
	rValue = Stream.FRandRange(0.0f, tValue);
	for (int32 i = 0; i < Weights.Num(); i++)
	{
		if (rValue < Weights[i])
		{
			return i;
		}
		rValue -= Weights[i];
	}
	return 0; //Never reach point
}

FVector UPurpleprintCoreRandom::RandomVector(FVector Min, FVector Max) 
{
	// 1 23 45 67
	int32 rN = FMath::RandRange(1000000, 1999999);

	// Get 67 // 45 // 23
	FVector rV = FVector(	FMath::Fmod((float)(rN % 100) * 0.01f, 1.f), 
							FMath::Fmod((float)((rN / 100) % 100) * 0.01f, 1.f),
							FMath::Fmod((float)((rN / 10000) % 100) * 0.01f, 1.f));

	return ((Max - Min) * rV) + Min;
}

FVector UPurpleprintCoreRandom::RandomVectorStream(FRandomStream const& Stream, FVector Min, FVector Max) 
{
	// 1 23 45 67
	int32 rN = Stream.RandRange(1000000, 1999999);

	// Get 67 // 45 // 23
	FVector rV = FVector(FMath::Fmod((float)(rN % 100) * 0.01f, 1.f),
		FMath::Fmod((float)((rN / 100) % 100) * 0.01f, 1.f),
		FMath::Fmod((float)((rN / 10000) % 100) * 0.01f, 1.f));

	return ((Max - Min) * rV) + Min;
}

FVector UPurpleprintCoreRandom::RandomVectorBox(FBox Range) 
{
	return RandomVector(Range.Min, Range.Max);
}

FVector UPurpleprintCoreRandom::RandomVectorBoxStream(FRandomStream const& Stream, FBox Range) 
{
	return RandomVectorStream(Stream, Range.Min, Range.Max);
}

FRotator UPurpleprintCoreRandom::RandomRotatorBox(FBox Range) 
{
	FVector vR = RandomVector(Range.Min, Range.Max);
	return FRotator(vR.X, vR.Y, vR.Z);
}

FRotator UPurpleprintCoreRandom::RandomRotatorBoxStream(FRandomStream const& Stream, FBox Range) 
{
	FVector vR = RandomVectorStream(Stream, Range.Min, Range.Max);
	return FRotator(vR.X, vR.Y, vR.Z);
}

int32 UPurpleprintCoreRandom::RandomIntRange(FInt32Range Range)
{
	return FMath::RandRange(Range.GetLowerBoundValue(), Range.GetUpperBoundValue());
}

int32 UPurpleprintCoreRandom::RandomIntRangeStream(FRandomStream const& Stream, FInt32Range Range)
{
	return Stream.RandRange(Range.GetLowerBoundValue(), Range.GetUpperBoundValue());
}

float UPurpleprintCoreRandom::RandomFloatRange(FFloatRange Range)
{
	return FMath::FRandRange(Range.GetLowerBoundValue(), Range.GetUpperBoundValue());
}

float UPurpleprintCoreRandom::RandomFloatRangeStream(FRandomStream const& Stream, FFloatRange Range)
{
	return Stream.FRandRange(Range.GetLowerBoundValue(), Range.GetUpperBoundValue());
}

int32 UPurpleprintCoreRandom::RandomPurpleIntRange(FPurpleIntRange Range)
{
	return FMath::RandRange(Range.Min, Range.Max);
}

int32 UPurpleprintCoreRandom::RandomPurpleIntRangeStream(FRandomStream const& Stream, FPurpleIntRange Range)
{
	return Stream.RandRange(Range.Min, Range.Max);
}

float UPurpleprintCoreRandom::RandomPurpleFloatRange(FPurpleFloatRange Range)
{
	return FMath::FRandRange(Range.Min, Range.Max);
}

float UPurpleprintCoreRandom::RandomPurpleFloatRangeStream(FRandomStream const& Stream, FPurpleFloatRange Range)
{
	return Stream.FRandRange(Range.Min, Range.Max);
}

int32 UPurpleprintCoreRandom::RandomPurpleIntRangeBound(FPurpleIntRangeBound Range)
{
	return FMath::RandRange(Range.Min, Range.Max);
}

int32 UPurpleprintCoreRandom::RandomPurpleIntRangeBoundStream(FRandomStream const& Stream, FPurpleIntRangeBound Range)
{
	return Stream.RandRange(Range.Min, Range.Max);
}

float UPurpleprintCoreRandom::RandomPurpleFloatRangeBound(FPurpleFloatRangeBound Range)
{
	return FMath::FRandRange(Range.Min, Range.Max);
}

float UPurpleprintCoreRandom::RandomPurpleFloatRangeBoundStream(FRandomStream const& Stream, FPurpleFloatRangeBound Range)
{
	return Stream.FRandRange(Range.Min, Range.Max);
}

FVector2D UPurpleprintCoreRandom::GetRandomPointInCircle(const float Radius, const float InnerRadius)
{
	float inRad = FMath::Max(InnerRadius, 0.0f);
	float rad = FMath::Max(inRad, Radius);
	float rCos = UPurpleprintCoreMath::CosD(FMath::FRandRange(0.0f, 359.f));
	float rSin = UPurpleprintCoreMath::SinD(FMath::FRandRange(0.0f, 359.f));

	float rX = FMath::FRandRange(inRad, rad) * rCos;
	float rY = FMath::FRandRange(inRad, rad) * rSin;
	return FVector2D(rX, rY);
}

FVector2D UPurpleprintCoreRandom::GetRandomPointInCircleStream(FRandomStream const& Stream, const float Radius, const float InnerRadius)
{
	float inRad = FMath::Max(InnerRadius, 0.0f);
	float rad = FMath::Max(inRad, Radius);
	float rCos = UPurpleprintCoreMath::CosD(Stream.FRandRange(0.0f, 359.f));
	float rSin = UPurpleprintCoreMath::SinD(Stream.FRandRange(0.0f, 359.f));

	float rX = Stream.FRandRange(inRad, rad) * rCos;
	float rY = Stream.FRandRange(inRad, rad) * rSin;
	return FVector2D(rX, rY);
}

FVector UPurpleprintCoreRandom::GetRandomPointInSphere(const float Radius, const FVector Origin)
{
	float x, y, z;
	float u = UPurpleprintCoreMath::Cbrt(FMath::FRand());
	x = FMath::FRandRange(-1.0f, 1.0f);
	y = FMath::FRandRange(-1.0f, 1.0f);
	z = FMath::FRandRange(-1.0f, 1.0f);
	float mag = FMath::Sqrt((x * x) + (y * y) + (z * z));

	x = (x / mag) * u;
	y = (y / mag) * u;
	z = (z / mag) * u;

	return Origin + FVector(x * Radius, y * Radius, z * Radius);
}

FVector UPurpleprintCoreRandom::GetRandomPointInSphereStream(FRandomStream const& Stream, const float Radius, const FVector Origin)
{
	float x, y, z;
	float u = UPurpleprintCoreMath::Cbrt(Stream.FRand());
	x = Stream.FRandRange(-1.0f, 1.0f);
	y = Stream.FRandRange(-1.0f, 1.0f);
	z = Stream.FRandRange(-1.0f, 1.0f);
	float mag = FMath::Sqrt((x * x) + (y * y) + (z * z));

	x = (x / mag) * u;
	y = (y / mag) * u;
	z = (z / mag) * u;

	return Origin + FVector(x * Radius, y * Radius, z * Radius);
}

FVector UPurpleprintCoreRandom::GetRandomPointInBoundingBoxStream(FRandomStream const& Stream, const FVector BoxExtent, const FVector Origin)
{
	const FVector boxMin = Origin - BoxExtent;
	const FVector boxMax = Origin + BoxExtent;

	return FVector(Stream.FRandRange(boxMin.X, boxMax.X),
		Stream.FRandRange(boxMin.Y, boxMax.Y),
		Stream.FRandRange(boxMin.Z, boxMax.Z));
}

FVector2D UPurpleprintCoreRandom::GetRandomPointInBiasCircle(const float MinRadius, const float MaxRadius)
{
	const float clampedMin = FMath::Max(MinRadius, 0.0f);
	const float clampedMax = FMath::Max(clampedMin, MaxRadius);

	// Random radian angle in radians
	float angleRad = FMath::FRandRange(0.0f, 2.0f * PI);

	// Uniform distribution (sqrt)
	float t = FMath::FRand(); // in [0,1]
	float radius = FMath::Sqrt(FMath::Lerp(clampedMin * clampedMin, clampedMax * clampedMax, t));

	float x = FMath::Cos(angleRad) * radius;
	float y = FMath::Sin(angleRad) * radius;

	return FVector2D(x, y);
}

FVector UPurpleprintCoreRandom::GetRandomPointInBiasSphere(const float MinRadius, const float MaxRadius, const FVector Origin)
{
	float x, y, z;

	// cubical root for uniform distribution in sphere
	float u = UPurpleprintCoreMath::Cbrt(FMath::FRand());
	float radius = FMath::Lerp(MinRadius, MaxRadius, u);

	// random unit vector in sphere
	x = FMath::FRandRange(-1.0f, 1.0f);
	y = FMath::FRandRange(-1.0f, 1.0f);
	z = FMath::FRandRange(-1.0f, 1.0f);
	float mag = FMath::Sqrt((x * x) + (y * y) + (z * z));

	x = (x / mag) * radius;
	y = (y / mag) * radius;
	z = (z / mag) * radius;

	return Origin + FVector(x, y, z);
}

FVector UPurpleprintCoreRandom::GetRandomPointInBiasBoundingBox(const FVector MinExtent, const FVector MaxExtent, const FVector Origin)
{
	// asimettric random point in bounding box
	float x = FMath::FRandRange(-MaxExtent.X, MaxExtent.X);
	if (FMath::Abs(x) < MinExtent.X)
		x = FMath::Sign(x) * FMath::FRandRange(MinExtent.X, MaxExtent.X);

	float y = FMath::FRandRange(-MaxExtent.Y, MaxExtent.Y);
	if (FMath::Abs(y) < MinExtent.Y)
		y = FMath::Sign(y) * FMath::FRandRange(MinExtent.Y, MaxExtent.Y);

	float z = FMath::FRandRange(-MaxExtent.Z, MaxExtent.Z);
	if (FMath::Abs(z) < MinExtent.Z)
		z = FMath::Sign(z) * FMath::FRandRange(MinExtent.Z, MaxExtent.Z);

	return Origin + FVector(x, y, z);
}

FVector2D UPurpleprintCoreRandom::GetRandomPointInBiasCircleStream(FRandomStream const& Stream, const float MinRadius, const float MaxRadius)
{
	const float clampedMin = FMath::Max(MinRadius, 0.0f);
	const float clampedMax = FMath::Max(clampedMin, MaxRadius);

	// Random radian angle in radians
	float angleRad = Stream.FRandRange(0.0f, 2.0f * PI);

	// Uniform distribution (sqrt)
	float t = Stream.FRand(); // in [0,1]
	float radius = FMath::Sqrt(FMath::Lerp(clampedMin * clampedMin, clampedMax * clampedMax, t));

	float x = FMath::Cos(angleRad) * radius;
	float y = FMath::Sin(angleRad) * radius;

	return FVector2D(x, y);
}

FVector UPurpleprintCoreRandom::GetRandomPointInBiasSphereStream(FRandomStream const& Stream, const float MinRadius, const float MaxRadius, const FVector Origin)
{
	float x, y, z;

	// cubical root for uniform distribution in sphere
	float u = UPurpleprintCoreMath::Cbrt(Stream.FRand());
	float radius = FMath::Lerp(MinRadius, MaxRadius, u);

	// random unit vector in sphere
	x = Stream.FRandRange(-1.0f, 1.0f);
	y = Stream.FRandRange(-1.0f, 1.0f);
	z = Stream.FRandRange(-1.0f, 1.0f);
	float mag = FMath::Sqrt((x * x) + (y * y) + (z * z));

	x = (x / mag) * radius;
	y = (y / mag) * radius;
	z = (z / mag) * radius;

	return Origin + FVector(x, y, z);
}

FVector UPurpleprintCoreRandom::GetRandomPointInBiasBoundingBoxStream(FRandomStream const& Stream, const FVector MinExtent, const FVector MaxExtent, const FVector Origin)
{
	// asimettric random point in bounding box
	float x = Stream.FRandRange(-MaxExtent.X, MaxExtent.X);
	if (FMath::Abs(x) < MinExtent.X)
		x = FMath::Sign(x) * Stream.FRandRange(MinExtent.X, MaxExtent.X);

	float y = Stream.FRandRange(-MaxExtent.Y, MaxExtent.Y);
	if (FMath::Abs(y) < MinExtent.Y)
		y = FMath::Sign(y) * Stream.FRandRange(MinExtent.Y, MaxExtent.Y);

	float z = Stream.FRandRange(-MaxExtent.Z, MaxExtent.Z);
	if (FMath::Abs(z) < MinExtent.Z)
		z = FMath::Sign(z) * Stream.FRandRange(MinExtent.Z, MaxExtent.Z);

	return Origin + FVector(x, y, z);
}