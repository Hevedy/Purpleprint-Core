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
PurpleprintCoreMath.cpp
================================================
*/

#include "PurpleprintCoreMath.h"


UPurpleprintCoreMath::UPurpleprintCoreMath( const class FObjectInitializer& ObjectInitializer ) 
{

}

float UPurpleprintCoreMath::Cbrt( const float Value ) 
{
	return FMath::Pow( Value, 1.f / 3.f );
}

float UPurpleprintCoreMath::OneLimit(const float Value) 
{
	return FMath::Fmod(Value, 1.0f);
}

float UPurpleprintCoreMath::OneMinus(const float Value) 
{
	return (1.0f - Value);
}

int32 UPurpleprintCoreMath::NegateInt(const int32 Value) 
{
	return (-1 * Value);
}

float UPurpleprintCoreMath::Negate(const float Value) 
{
	return (-1.0f * Value);
}

int32 UPurpleprintCoreMath::ReverseInt(const int32 Value) 
{
	int32 value = 0;
	for (int32 i = Value; i != 0; i /= 10) {
		value = value * 10 + i % 10;
	}
	return value;
}

float UPurpleprintCoreMath::Reverse(const float Value) 
{
	int a = FMath::TruncToInt(Value);
	int b = (int32)FMath::Frac(Value);
	int m = 1;
	for (int i = 0; i <= FloatCount(Value); ++i) { m *= 10; }
	return b + (a / m);
}

FVector UPurpleprintCoreMath::AddVectorIntegerVector(FVector A, FIntVector B)
{
	return FVector(A.X + B.X, A.Y + B.Y, A.Z + B.Z);
}

FVector UPurpleprintCoreMath::MultVectorIntegerVector(FVector A, FIntVector B)
{
	return FVector(A.X * B.X, A.Y * B.Y, A.Z * B.Z);
}

double UPurpleprintCoreMath::CalculateCameraHeightForArea(double DesiredWidthUU, float VerticalFOVDegrees)
{
	double HalfFOVRadians = FMath::DegreesToRadians(VerticalFOVDegrees / 2.0f);
	return (DesiredWidthUU / 2.0f) / FMath::Tan(HalfFOVRadians);
}

float UPurpleprintCoreMath::CalculateCameraHeightForAreaFloat(float DesiredWidthUU, float VerticalFOVDegrees)
{
	return static_cast<float>(CalculateCameraHeightForArea(DesiredWidthUU, VerticalFOVDegrees));
}

FTransform UPurpleprintCoreMath::TransformsAddMasked(const FTransform& A, const FTransform& B, bool bLocation, bool bRotation, bool bScale, bool bReturnFirst)
{
	FVector l = bLocation ? A.GetLocation() + B.GetLocation() : (bReturnFirst ? A.GetLocation() : B.GetLocation());
	FQuat q = A.GetRotation() + B.GetRotation();
	FRotator r = bRotation ? q.Rotator() : (bReturnFirst ? A.GetRotation().Rotator() : B.GetRotation().Rotator());
	FVector s = bScale ? A.GetScale3D() + B.GetScale3D() : (bReturnFirst ? A.GetScale3D() : B.GetScale3D());
	return FTransform(r, l, s);
}

FTransform UPurpleprintCoreMath::TransformsSubMasked(const FTransform& A, const FTransform& B, bool bLocation, bool bRotation, bool bScale, bool bReturnFirst)
{
	FVector l = bLocation ? A.GetLocation() - B.GetLocation() : (bReturnFirst ? A.GetLocation() : B.GetLocation());
	FQuat q = A.GetRotation() - B.GetRotation();
	FRotator r = bRotation ? q.Rotator() : (bReturnFirst ? A.GetRotation().Rotator() : B.GetRotation().Rotator());
	FVector s = bScale ? A.GetScale3D() - B.GetScale3D() : (bReturnFirst ? A.GetScale3D() : B.GetScale3D());
	return FTransform(r, l, s);
}

FTransform UPurpleprintCoreMath::TransformsMulMasked(const FTransform& A, const FTransform& B, bool bLocation, bool bRotation, bool bScale, bool bReturnFirst)
{
	FVector l = bLocation ? A.GetLocation() * B.GetLocation() : (bReturnFirst ? A.GetLocation() : B.GetLocation());
	FQuat q = A.GetRotation() * B.GetRotation();
	FRotator r = bRotation ? q.Rotator() : (bReturnFirst ? A.GetRotation().Rotator() : B.GetRotation().Rotator());
	FVector s = bScale ? A.GetScale3D() * B.GetScale3D() : (bReturnFirst ? A.GetScale3D() : B.GetScale3D());
	return FTransform(r, l, s);
}

FTransform UPurpleprintCoreMath::TransformsCombine(const FTransform& A, const FTransform& B)
{
	FVector l = A.GetLocation() + B.GetLocation();
	FQuat q = A.GetRotation() * B.GetRotation();
	FRotator r = q.Rotator();
	FVector s = A.GetScale3D() * B.GetScale3D();
	return FTransform(r, l, s);
}

FTransform UPurpleprintCoreMath::TransformsCombineMasked(const FTransform& A, const FTransform& B, bool bLocation, bool bRotation, bool bScale, bool bReturnFirst)
{
	FVector l = bLocation ? A.GetLocation() + B.GetLocation() : (bReturnFirst ? A.GetLocation() : B.GetLocation());
	FQuat q = A.GetRotation() * B.GetRotation();
	FRotator r = bRotation ? q.Rotator() : (bReturnFirst ? A.GetRotation().Rotator() : B.GetRotation().Rotator());
	FVector s = bScale ? A.GetScale3D() * B.GetScale3D() : (bReturnFirst ? A.GetScale3D() : B.GetScale3D());
	return FTransform(r, l, s);
}

FVector UPurpleprintCoreMath::GetClosestPointOnSphereSurface(const FVector& SphereCenter, float SphereRadius, const FVector& TargetPoint)
{
	FVector Direction = (TargetPoint - SphereCenter).GetSafeNormal();
	return SphereCenter + Direction * SphereRadius;
}

FVector UPurpleprintCoreMath::GetClosestPointOnDomeSurface(const FVector& DomeCenter, float DomeRadius, const FVector& TargetPoint)
{
	FVector Direction = (TargetPoint - DomeCenter).GetSafeNormal();

	if (Direction.Z < 0)
	{
		Direction.Z *= -1; // Mirror if lower than 0
		Direction = Direction.GetSafeNormal();
	}

	return DomeCenter + Direction * DomeRadius;
}

float UPurpleprintCoreMath::SpringFloat(float Current, float Target, float& Velocity, float Frequency, float Damping, float DeltaTime)
{
	if (DeltaTime <= 0.f)
		return Current;

	// Difference
	float Delta = FMath::FindDeltaAngleDegrees(Current, Target); // Yaw
	float AngularFrequency = 2 * PI * Frequency;

	// Bounce
	float Acceleration = AngularFrequency * AngularFrequency * Delta - 2.0f * Damping * AngularFrequency * Velocity;

	Velocity += Acceleration * DeltaTime;
	Current += Velocity * DeltaTime;

	return Current;
}

bool UPurpleprintCoreMath::FLinearColorNearEqual(const FLinearColor A, const FLinearColor B, const bool bIgnoreAlpha) 
{
	FLinearColor a = A;
	FLinearColor b = B;
	if (bIgnoreAlpha) {
		a.A = 0.f;
		b.A = 0.f;
	}
	if (A == B) {
		return true;
	}
	else {
		if (A.Equals(B)) {
			return true;
		}
	}
	return false;
}

float UPurpleprintCoreMath::BoxPerimeter(const float SizeX, const float SizeY) 
{
	return SizeX * 2 + SizeY * 2;
}

float UPurpleprintCoreMath::BoxDiagonal(const float SizeX, const float SizeY) 
{
	return (float)FMath::Sqrt((SizeX * SizeX) + (SizeY * SizeY));
}

float UPurpleprintCoreMath::BoxSide(const float Diagonal) 
{
	return (float)FMath::Sqrt((Diagonal * Diagonal) / 2);
}

float UPurpleprintCoreMath::VectorDistance(const FVector A, const FVector B) 
{
	return FMath::Abs(FVector(A - B).Size());
}

float UPurpleprintCoreMath::Distance2D(const FVector2D A, const FVector2D B) 
{
	return (float)FMath::Sqrt(FMath::Pow((B.X - A.X), 2) + FMath::Pow((B.Y - A.Y), 2));
}

float UPurpleprintCoreMath::GetVectorsAngleRadiants(FVector A, FVector B) 
{
	return FMath::Acos(FVector::DotProduct(A.GetSafeNormal(), B.GetSafeNormal()));
}

float UPurpleprintCoreMath::GetVectorsAngleDegrees(FVector A, FVector B) 
{
	return FMath::RadiansToDegrees(GetVectorsAngleRadiants(A, B));
}

FVector UPurpleprintCoreMath::GetPointOnLineAtDistance(FVector Start, FVector End, float Distance) 
{
	return Start + (Distance * (End - Start).Normalize());
}

float UPurpleprintCoreMath::LerpLinearBounce(float Alpha)
{
	return 1.0f - FMath::Abs(1.0f - (Alpha * 2.0f));
}

float UPurpleprintCoreMath::LerpLinearBounceAuto(float& Alpha, float Delta, float DeltaSpeed) 
{
	if (FMath::IsNearlyZero((1.0f - Alpha))) {
		Alpha = 0.f;
	}
	float lerp = FMath::FInterpConstantTo(Alpha, 1.0f, Delta, DeltaSpeed);
	Alpha = lerp;
	return LerpLinearBounce(lerp);
}

int32 UPurpleprintCoreMath::IntegerCount(const int32 IntValue, const bool Fast) 
{
	if (Fast) {
		switch (IntValue)
		{
		case 0:
			return 1;
			break;
		case 10:
			return 2;
			break;
		default:
			return FMath::TruncToInt(Log10(FMath::Abs(IntValue))) + 1;
			break;
		}
	}
	else {
		return IntValue == 0 ? 1 : FMath::TruncToInt(Log10S(FMath::Abs(IntValue))) + 1;
	}
}

int32 UPurpleprintCoreMath::FloatCount(const float FloatValue, const bool Fast) 
{
	if (Fast) {
		return FloatValue == 0 ? 1 : FMath::TruncToInt(Log10(FMath::Abs(FloatValue)));
	}
	else {
		return FloatValue == 0 ? 1 : FMath::TruncToInt(Log10S(FMath::Abs(FloatValue)));
	}
}

int32 UPurpleprintCoreMath::DecimalCount(const float FloatValue) 
{

	return FMath::FloorToInt(1 / FloatValue);
}

int32 UPurpleprintCoreMath::NormalizeInRangeRoulette(const int32 Value, const int32 Min, const int32 Max) 
{
	int32 min = Min;
	int32 val = Value;
	int32 max = Max;
	if (val < min) {
		return max - ((val % max) * -1);
	}
	else if (val > max) {
		return val % max;
	}
	else {
		return val;
	}
}


uint8 UPurpleprintCoreMath::BGetCloser(uint8 Ref, uint8 A, uint8 B) 
{
	return Closer<uint8>(Ref, A, B);
}


uint8 UPurpleprintCoreMath::BGetFurther(uint8 Ref, uint8 A, uint8 B) 
{
	return Further<uint8>(Ref, A, B);
}


int32 UPurpleprintCoreMath::IGetCloser(int32 Ref, int32 A, int32 B) 
{
	return Closer<int32>(Ref, A, B);
}


int32 UPurpleprintCoreMath::IGetFurther(int32 Ref, int32 A, int32 B) 
{
	return Further<int32>(Ref, A, B);
}


float UPurpleprintCoreMath::FGetCloser(float Ref, float A, float B) 
{
	return Closer<float>(Ref, A, B);
}


float UPurpleprintCoreMath::FGetFurther(float Ref, float A, float B) 
{
	return Further<float>(Ref, A, B);
}

uint8 UPurpleprintCoreMath::BGetCloserSubNum(uint8 Ref, uint8 RefA, uint8 RefB, uint8 A, uint8 B) 
{
	return ((Closer<uint8>(Ref, RefA, RefB)) == RefA ? A : B);
}

uint8 UPurpleprintCoreMath::BGetFurtherSubNum(uint8 Ref, uint8 RefA, uint8 RefB, uint8 A, uint8 B) 
{
	return ((Further<uint8>(Ref, RefA, RefB)) == RefA ? A : B);
}

int32 UPurpleprintCoreMath::IGetCloserSubNum(int32 Ref, int32 RefA, int32 RefB, int32 A, int32 B) 
{
	return ((Closer<int32>(Ref, RefA, RefB)) == RefA ? A : B);
}

int32 UPurpleprintCoreMath::IGetFurtherSubNum(int32 Ref, int32 RefA, int32 RefB, int32 A, int32 B) 
{
	return ((Further<int32>(Ref, RefA, RefB)) == RefA ? A : B);
}

float UPurpleprintCoreMath::FGetCloserSubNum(float Ref, float RefA, float RefB, float A, float B) 
{
	return ((Closer<float>(Ref, RefA, RefB)) == RefA ? A : B);
}

float UPurpleprintCoreMath::FGetFurtherSubNum(float Ref, float RefA, float RefB, float A, float B) 
{
	return ((Further<float>(Ref, RefA, RefB)) == RefA ? A : B);
}

void UPurpleprintCoreMath::CloserByteArray(const uint8 ByteRefValue, const TArray<uint8>& ByteArray, const bool NotEqual,
	int32& IndexOfCloserValue, uint8& CloserValue) 
{
	CloserValue = Closer<uint8>(ByteRefValue, ByteArray, NotEqual, &IndexOfCloserValue);
}

void UPurpleprintCoreMath::FurtherByteArray(const uint8 ByteRefValue, const TArray<uint8>& ByteArray, int32& IndexOfFurtherValue,
	uint8& FurtherValue) 
{
	FurtherValue = Further<uint8>(ByteRefValue, ByteArray, &IndexOfFurtherValue);
}

void UPurpleprintCoreMath::CloserIntegerArray(const int32 IntRefValue, const TArray<int32>& IntArray, const bool NotEqual,
	int32& IndexOfCloserValue, int32& CloserValue) 
{
	CloserValue = Closer<int32>(IntRefValue, IntArray, NotEqual, &IndexOfCloserValue);
}

void UPurpleprintCoreMath::FurtherIntegerArray(const int32 IntRefValue, const TArray<int32>& IntArray, int32& IndexOfFurtherValue,
	int32& FurtherValue) 
{
	FurtherValue = Further<int32>(IntRefValue, IntArray, &IndexOfFurtherValue);
}

void UPurpleprintCoreMath::CloserFloatArray(const float FloatRefValue, const TArray<float>& FloatArray, const bool NotEqual,
	int32& IndexOfCloserValue, float& CloserValue) 
{
	CloserValue = Closer<float>(FloatRefValue, FloatArray, NotEqual, &IndexOfCloserValue);
}

void UPurpleprintCoreMath::FurtherFloatArray(const float FloatRefValue, const TArray<float>& FloatArray, int32& IndexOfFurtherValue,
	float& FurtherValue) 
{
	FurtherValue = Further<float>(FloatRefValue, FloatArray, &IndexOfFurtherValue);
}

void UPurpleprintCoreMath::MinByteArray(const TArray<uint8>& ByteArray, const int32 NumberOfIndexToDiscard, int32& IndexOfMinValue,
	float& MinValue) 
{
	if (NumberOfIndexToDiscard < 0 || NumberOfIndexToDiscard >= ByteArray.Num()) {
		IndexOfMinValue = -1; MinValue = -1; return;
	}
	TArray<uint8> localArray = ByteArray; TArray<uint8> localArrayRef;
	int32 minIndex = -1; int32 lastMinIndex = -1; float minValue = -1; int32 numdiff = 0;
	for (int32 i = -1; i < NumberOfIndexToDiscard; i++) {
		minValue = FMath::Min<uint8>(localArray, &minIndex);
		localArrayRef.Add(minIndex);
		localArray.RemoveAt(minIndex);
		lastMinIndex = minIndex;
	}
	for (int32 i = 0; i < localArrayRef.Num(); i++) {
		minIndex = (localArrayRef[i] < lastMinIndex) ? minIndex + 1 : minIndex;
	}
	IndexOfMinValue = minIndex; MinValue = minValue;
}

void UPurpleprintCoreMath::MaxByteArray(const TArray<uint8>& ByteArray, const int32 NumberOfIndexToDiscard, int32& IndexOfMaxValue,
	float& MaxValue) 
{
	if (NumberOfIndexToDiscard < 0 || NumberOfIndexToDiscard >= ByteArray.Num()) {
		IndexOfMaxValue = -1; MaxValue = -1; return;
	}
	TArray<uint8> localArray = ByteArray; TArray<uint8> localArrayRef;
	int32 maxIndex = -1; int32 lastMaxIndex = -1; float maxValue = -1; int32 numdiff = 0;
	for (int32 i = -1; i < NumberOfIndexToDiscard; i++) {
		maxValue = FMath::Max<uint8>(localArray, &maxIndex);
		localArrayRef.Add(maxIndex);
		localArray.RemoveAt(maxIndex);
		lastMaxIndex = maxIndex;
	}
	for (int32 i = 0; i < localArrayRef.Num(); i++) {
		maxIndex = (localArrayRef[i] < lastMaxIndex) ? maxIndex + 1 : maxIndex;
	}
	IndexOfMaxValue = maxIndex; MaxValue = maxValue;
}

void UPurpleprintCoreMath::MinIntegerArray(const TArray<int32>& IntArray, const int32 NumberOfIndexToDiscard, int32& IndexOfMinValue,
	float& MinValue) 
{
	if (NumberOfIndexToDiscard < 0 || NumberOfIndexToDiscard >= IntArray.Num()) {
		IndexOfMinValue = -1; MinValue = -1; return;
	}
	TArray<int32> localArray = IntArray; TArray<int32> localArrayRef;
	int32 minIndex = -1; int32 lastMinIndex = -1; float minValue = -1; int32 numdiff = 0;
	for (int32 i = -1; i < NumberOfIndexToDiscard; i++) {
		minValue = FMath::Min<int32>(localArray, &minIndex);
		localArrayRef.Add(minIndex);
		localArray.RemoveAt(minIndex);
		lastMinIndex = minIndex;
	}
	for (int32 i = 0; i < localArrayRef.Num(); i++) {
		minIndex = (localArrayRef[i] < lastMinIndex) ? minIndex + 1 : minIndex;
	}
	IndexOfMinValue = minIndex; MinValue = minValue;
}

void UPurpleprintCoreMath::MaxIntegerArray(const TArray<int32>& IntArray, const int32 NumberOfIndexToDiscard, int32& IndexOfMaxValue,
	float& MaxValue) 
{
	if (NumberOfIndexToDiscard < 0 || NumberOfIndexToDiscard >= IntArray.Num()) {
		IndexOfMaxValue = -1; MaxValue = -1; return;
	}
	TArray<int32> localArray = IntArray; TArray<int32> localArrayRef;
	int32 maxIndex = -1; int32 lastMaxIndex = -1; float maxValue = -1; int32 numdiff = 0;
	for (int32 i = -1; i < NumberOfIndexToDiscard; i++) {
		maxValue = FMath::Max<int32>(localArray, &maxIndex);
		localArrayRef.Add(maxIndex);
		localArray.RemoveAt(maxIndex);
		lastMaxIndex = maxIndex;
	}
	for (int32 i = 0; i < localArrayRef.Num(); i++) {
		maxIndex = (localArrayRef[i] < lastMaxIndex) ? maxIndex + 1 : maxIndex;
	}
	IndexOfMaxValue = maxIndex; MaxValue = maxValue;
}

void UPurpleprintCoreMath::MinFloatArray(const TArray<float>& FloatArray, const int32 NumberOfIndexToDiscard, int32& IndexOfMinValue,
	float& MinValue) 
{
	if (NumberOfIndexToDiscard < 0 || NumberOfIndexToDiscard >= FloatArray.Num()) {
		IndexOfMinValue = -1; MinValue = -1; return;
	}
	TArray<float> localArray = FloatArray; TArray<int32> localArrayRef;
	int32 minIndex = -1; int32 lastMinIndex = -1; float minValue = -1; int32 numdiff = 0;
	for (int32 i = -1; i < NumberOfIndexToDiscard; i++) {
		minValue = FMath::Min<float>(localArray, &minIndex);
		localArrayRef.Add(minIndex);
		localArray.RemoveAt(minIndex);
		lastMinIndex = minIndex;
	}
	for (int32 i = 0; i < localArrayRef.Num(); i++) {
		minIndex = (localArrayRef[i] < lastMinIndex) ? minIndex + 1 : minIndex;
	}
	IndexOfMinValue = minIndex; MinValue = minValue;
}

void UPurpleprintCoreMath::MaxFloatArray(const TArray<float>& FloatArray, const int32 NumberOfIndexToDiscard, int32& IndexOfMaxValue,
	float& MaxValue) 
{
	if (NumberOfIndexToDiscard < 0 || NumberOfIndexToDiscard >= FloatArray.Num()) {
		IndexOfMaxValue = -1; MaxValue = -1; return;
	}
	TArray<float> localArray = FloatArray; TArray<int32> localArrayRef;
	int32 maxIndex = -1; int32 lastMaxIndex = -1; float maxValue = -1; int32 numdiff = 0;
	for (int32 i = -1; i < NumberOfIndexToDiscard; i++) {
		maxValue = FMath::Max<float>(localArray, &maxIndex);
		localArrayRef.Add(maxIndex);
		localArray.RemoveAt(maxIndex);
		lastMaxIndex = maxIndex;
	}
	for (int32 i = 0; i < localArrayRef.Num(); i++) {
		maxIndex = (localArrayRef[i] < lastMaxIndex) ? maxIndex + 1 : maxIndex;
	}
	IndexOfMaxValue = maxIndex; MaxValue = maxValue;
}