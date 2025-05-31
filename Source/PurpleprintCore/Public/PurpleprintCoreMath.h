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
PurpleprintCoreMath.h
================================================
*/

#pragma once

#include "CoreMinimal.h"
#include "Containers/Map.h"
#include "Misc/EngineVersionComparison.h"
#include "PurpleprintCoreMath.generated.h"


UCLASS()
class PURPLEPRINTCORE_API UPurpleprintCoreMath : public UBlueprintFunctionLibrary 
{
	GENERATED_BODY()

	UPurpleprintCoreMath( const FObjectInitializer& ObjectInitializer );
private:

protected:

public:

	static FORCEINLINE float Log2(float Value) { return FMath::Loge(Value) * 1.4426950f; }
	// Slower than Log2 but more accurate
	static FORCEINLINE float Log2S(float Value) { return FMath::LogX(2.f, Value); }
	// 1.0 / Loge(10)= 0.4342944f
	static FORCEINLINE float Log10(float Value) { return FMath::Loge(Value) * 0.4342944f; }

	static FORCEINLINE double Log10S(float Value) { return (double)(FMath::Loge(Value) * (1.0 / FMath::Loge(10.f))); }

	static FORCEINLINE float Deg2Rad() { return (float)(PI * 2.f) / 360.f; }

	static FORCEINLINE float Deg2RadFixed() { return 0.017453f; }

	// Missing from C++ lib so here are, the Degress operations
	static inline float SinD(const float A );
	static inline float AsinD(const float A );
	static inline float CosD(const float A );
	static inline float AcosD(const float A );
	static inline float TanD(const float A );
	static inline float AtanD(const float A );
	static inline float Atan2D(const float A, const float B );

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static float Log10Fast(const float Value) { return Log10(Value); };

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static float Log10Slow(const float Value) { return Log10S(Value); };

	/** Returns cube root */
	UFUNCTION( BlueprintPure, Category = "Purpleprint|Math|Utils" )
	static float Cbrt( const float Value );

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static float OneLimit(const float Value);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static float OneMinus(const float Value);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static int32 NegateInt(const int32 Value);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static float Negate(const float Value);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static int32 ReverseInt(const int32 Value);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static float Reverse(const float Value);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static FVector MaxVec(FVector A, FVector B);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static FVector MinVec(FVector A, FVector B);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static FVector ClampVec(FVector X, FVector Min, FVector Max);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static FIntVector MaxIVec(FIntVector A, FIntVector B);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static FIntVector MinIVec(FIntVector A, FIntVector B);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static FIntVector ClampIVec(FIntVector X, FIntVector Min, FIntVector Max);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static FVector AddVecIVec(FVector A, FIntVector B);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static FVector MultVecIVec(FVector A, FIntVector B);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static FIntVector VecToIVec(FVector X);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static FVector IVecToVec(FIntVector X);

	//#if UE_VERSION_NEWER_THAN(5, 2, 0)
	//#endif
	// Cannot set a check for newer versions here, UFUNCTION isn't supported inside #if verison check
	static double CalculateCameraHeightForArea(double DesiredWidthUU, float VerticalFOVDegrees);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static float CalculateCameraHeightForAreaFloat(float DesiredWidthUU, float VerticalFOVDegrees);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Transform")
	static FTransform TransformsAddMasked(const FTransform& A, const FTransform& B, bool bLocation = true, bool bRotation = true, bool bScale = false, bool bReturnFirst = true);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Transform")
	static FTransform TransformsSubMasked(const FTransform& A, const FTransform& B, bool bLocation = true, bool bRotation = true, bool bScale = false, bool bReturnFirst = true);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Transform")
	static FTransform TransformsMulMasked(const FTransform& A, const FTransform& B, bool bLocation = true, bool bRotation = true, bool bScale = false, bool bbReturnFirst = true);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Transform")
	static FTransform TransformsCombine(const FTransform& A, const FTransform& B);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math")
	static FVector GetClosestPointOnSphereSurface(const FVector& SphereCenter, float SphereRadius, const FVector& TargetPoint);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math")
	static FVector GetClosestPointOnDomeSurface(const FVector& DomeCenter, float DomeRadius, const FVector& TargetPoint);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math")
	static float SpringFloat(float Current, float Target, float& Velocity, float Frequency, float Damping, float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Math|Color")
	static bool FLinearColorNearEqual(const FLinearColor A, const FLinearColor B, const bool bIgnoreAlpha = true);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static float BoxPerimeter(const float SizeX, const float SizeY);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static float BoxDiagonal(const float SizeX, const float SizeY);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static float BoxSide(const float Diagonal);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static float VectorDistance(const FVector A, const FVector B);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static float Distance2D(const FVector2D A, const FVector2D B);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static float GetVectorsAngleRadiants(FVector A, FVector B);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static float GetVectorsAngleDegrees(FVector A, FVector B);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static FVector GetPointOnLineAtDistance(FVector Start, FVector End, float Distance);

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Lerp")
	static float LerpLinearBounce(float Alpha);

	// Make callable because will return only once
	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Math|Lerp")
	static float LerpLinearBounceAuto(float& Alpha, float Delta, float DeltaSpeed = 1.0f);

	/** Returns the float in range of min and max can cross up or down */
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Utils")
	static int32 NormalizeInRangeRoulette(const int32 Value, const int32 Min, const int32 Max);

	/** Returns the number of characters in the int */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Integer Size"), Category = "Purpleprint|Math|Utils")
	static int32 IntegerCount(const int32 IntValue, const bool Fast = true);

	/** Returns the number of characters in the float */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Float Size"), Category = "Purpleprint|Math|Utils")
	static int32 FloatCount(const float FloatValue, const bool Fast = true);

	/** Returns the number decimals in the float */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Float Decimals"), Category = "Purpleprint|Math|Utils")
	static int32 DecimalCount(const float FloatValue);

	// Returns the closer value of A and B
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Closer (Byte)", CompactNodeTitle = "CLOS"), Category = "Purpleprint|Math|Byte")
	static uint8 BGetCloser(uint8 Ref, uint8 A, uint8 B);

	// Returns the further value of A and B
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Further (Byte)", CompactNodeTitle = "FURT"), Category = "Purpleprint|Math|Byte")
	static uint8 BGetFurther(uint8 Ref, uint8 A, uint8 B);

	// Returns the closer value of A and B
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Closer (int)", CompactNodeTitle = "CLOS"), Category = "Purpleprint|Math|Integer")
	static int32 IGetCloser(int32 Ref, int32 A, int32 B);

	// Returns the further value of A and B
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Further (int)", CompactNodeTitle = "FURT"), Category = "Purpleprint|Math|Integer")
	static int32 IGetFurther(int32 Ref, int32 A, int32 B);

	// Returns the closer value of A and B
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Closer (float)", CompactNodeTitle = "CLOS"), Category = "Purpleprint|Math|Float")
	static float FGetCloser(float Ref, float A, float B);

	// Returns the further value of A and B
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Further (float)", CompactNodeTitle = "FURT"), Category = "Purpleprint|Math|Float")
	static float FGetFurther(float Ref, float A, float B);

	/** Returns the closer value of A and B using provided numbers */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Closer Number (Byte)", CompactNodeTitle = "CLOSN"), Category = "Purpleprint|Math|Byte")
	static uint8 BGetCloserSubNum(uint8 Ref, uint8 RefA, uint8 RefB, uint8 A, uint8 B);

	/** Returns the further value of A and B using provided numbers */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Further Number (Byte)", CompactNodeTitle = "FURTN"), Category = "Purpleprint|Math|Byte")
	static uint8 BGetFurtherSubNum(uint8 Ref, uint8 RefA, uint8 RefB, uint8 A, uint8 B);

	/** Returns the closer value of A and B using provided numbers */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Closer Number (int)", CompactNodeTitle = "CLOSN"), Category = "Purpleprint|Math|Integer")
	static int32 IGetCloserSubNum(int32 Ref, int32 RefA, int32 RefB, int32 A, int32 B);

	/** Returns the further value of A and B using provided numbers */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Further Number (int)", CompactNodeTitle = "FURTN"), Category = "Purpleprint|Math|Integer")
	static int32 IGetFurtherSubNum(int32 Ref, int32 RefA, int32 RefB, int32 A, int32 B);

	/** Returns the closer value of A and B using provided numbers */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Closer Number (float)", CompactNodeTitle = "CLOSN"), Category = "Purpleprint|Math|Float")
	static float FGetCloserSubNum(float Ref, float RefA, float RefB, float A, float B);

	/** Returns the further value of A and B using provided numbers */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Further Number (float)", CompactNodeTitle = "FURTN"), Category = "Purpleprint|Math|Float")
	static float FGetFurtherSubNum(float Ref, float RefA, float RefB, float A, float B);

	/** Returns the closer byte in the array and their index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Byte")
	static void CloserByteArray(const uint8 ByteRefValue, const TArray<uint8>& ByteArray, const bool NotEqual, int32& IndexOfCloserValue, uint8& CloserValue);

	/** Returns the further byte in the array and their index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Byte")
	static void FurtherByteArray(const uint8 ByteRefValue, const TArray<uint8>& ByteArray, int32& IndexOfFurtherValue, uint8& FurtherValue);

	/** Returns the closer integer in the array and their index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Integer")
	static void CloserIntegerArray(const int32 IntRefValue, const TArray<int32>& IntArray, const bool NotEqual, int32& IndexOfCloserValue, int32& CloserValue);

	/** Returns the further integer in the array and their index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Integer")
	static void FurtherIntegerArray(const int32 IntRefValue, const TArray<int32>& IntArray, int32& IndexOfFurtherValue, int32& FurtherValue);

	/** Returns the closer float in the array and their index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Float")
	static void CloserFloatArray(const float FloatRefValue, const TArray<float>& FloatArray, const bool NotEqual, int32& IndexOfCloserValue, float& CloserValue);

	/** Returns the further float in the array and their index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Float")
	static void FurtherFloatArray(const float FloatRefValue, const TArray<float>& FloatArray, int32& IndexOfFurtherValue, float& FurtherValue);

	/** Returns the min byte in the array and their index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Float")
	static void MinByteArray(const TArray<uint8>& ByteArray, const int32 NumberOfIndexToDiscard, int32& IndexOfMinValue, float& MinValue);

	/** Returns the max byte in the array and their index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Float")
	static void MaxByteArray(const TArray<uint8>& ByteArray, const int32 NumberOfIndexToDiscard, int32& IndexOfMaxValue, float& MaxValue);

	/** Returns the min integer in the array and their index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Float")
	static void MinIntegerArray(const TArray<int32>& IntArray, const int32 NumberOfIndexToDiscard, int32& IndexOfMinValue, float& MinValue);

	/** Returns the max integer in the array and their index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Float")
	static void MaxIntegerArray(const TArray<int32>& IntArray, const int32 NumberOfIndexToDiscard, int32& IndexOfMaxValue, float& MaxValue);

	/** Returns the min float in the array and their index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Float")
	static void MinFloatArray(const TArray<float>& FloatArray, const int32 NumberOfIndexToDiscard, int32& IndexOfMinValue, float& MinValue);

	/** Returns the max float in the array and their index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Math|Float")
	static void MaxFloatArray(const TArray<float>& FloatArray, const int32 NumberOfIndexToDiscard, int32& IndexOfMaxValue, float& MaxValue);

	/** Returns closer value in a generic way */
	template< class T >
	static CONSTEXPR FORCEINLINE T Closer(const T Reference, const T A, const T B) {
		return (((Reference - A) >= (T)0) ? (Reference - A) : -(Reference - A)) <= (((Reference - B) >= (T)0) ? (Reference - B) : -(Reference - B)) ? A : B;
	}

	/** Returns further value in a generic way */
	template< class T >
	static CONSTEXPR FORCEINLINE T Further(const T Reference, const T A, const T B) {
		return (((Reference - A) >= (T)0) ? (Reference - A) : -(Reference - A)) >= (((Reference - B) >= (T)0) ? (Reference - B) : -(Reference - B)) ? A : B;
	}

	/**
	* Closer number to given of Array
	* @param	Array of templated type
	* @param	Reference value templated type to compare
	* @param	Optional boolean to search only the closer values and no the equals
	* @param	Optional pointer for returning the index of the closer element, if multiple closer elements the first index is returned
	* @return	The closer value found in the array or default value if the array was empty or can't find a correct value
	*/
	template< class T >
	static FORCEINLINE T Closer(const T Reference, const TArray<T>& Values, const bool NotEqual, int32* CloserIndex = NULL) 
	{
		if (Values.Num() == 0) 
		{
			if (CloserIndex) 
			{
				*CloserIndex = INDEX_NONE;
			}
			return T();
		}

		T CurCloser = ((Reference - Values[0]) >= (T)0) ? (Reference - Values[0]) : -(Reference - Values[0]);
		int32 CurCloserIndex = 0;
		if (CurCloser == 0 && NotEqual) 
		{
			CurCloserIndex = -1;
		}

		for (int32 v = 1; v < Values.Num(); ++v) 
		{
			const T Value = ((Reference - Values[v]) >= (T)0) ? (Reference - Values[v]) : -(Reference - Values[v]);
			if (Value < CurCloser) 
			{
				if (!NotEqual || (NotEqual && Value != 0.f)) { // From 0 to 0.f probably fix
					CurCloser = Value;
					CurCloserIndex = v;
				}
			}
		}

		if (CloserIndex) 
		{
			*CloserIndex = CurCloserIndex == -1 ? INDEX_NONE : CurCloserIndex;
		}
		return Values.Num() == 0 ? 0 : Values[CurCloserIndex == -1 ? 0 : CurCloserIndex];
	}

	/**
	* Further number to given of Array
	* @param	Array of templated type
	* @param	Reference value templated type to compare
	* @param	Optional pointer for returning the index of the further element, if multiple further elements the first index is returned
	* @return	The further value found in the array or default value if the array was empty
	*/
	template< class T >
	static FORCEINLINE T Further(const T Reference, const TArray<T>& Values, int32* FurtherIndex = NULL) 
	{
		if (Values.Num() == 0) 
		{
			if (FurtherIndex) 
			{
				*FurtherIndex = INDEX_NONE;
			}
			return T();
		}

		T CurFurther = ((Reference - Values[0]) >= (T)0) ? (Reference - Values[0]) : -(Reference - Values[0]);
		int32 CurFurtherIndex = 0;
		for (int32 v = 1; v < Values.Num(); ++v) 
		{
			const T Value = ((Reference - Values[v]) >= (T)0) ? (Reference - Values[v]) : -(Reference - Values[v]);
			if (CurFurther < Value) 
			{
				CurFurther = Value;
				CurFurtherIndex = v;
			}
		}

		if (FurtherIndex) 
		{
			*FurtherIndex = CurFurtherIndex == -1 ? INDEX_NONE : CurFurtherIndex;
		}
		return Values.Num() == 0 ? 0 : Values[CurFurtherIndex == -1 ? 0 : CurFurtherIndex];
	}

	/**
	* Closer number to given of Array
	* @param	Array of templated type
	* @param	Reference value templated type to compare
	* @param	Optional boolean to search only the closer values and no the equals
	* @param	Optional pointer for returning the index of the closer element, if multiple closer elements the first index is returned
	* @return	The closer value found in the array or default value if the array was empty or can't find a correct value
	*/
	template< class T, class TT >
	static FORCEINLINE TT CloserTMap(const T Reference, const TMap<T, TT>& Values, const bool NotEqual, int32* CloserIndex = NULL, T* CloserKey = NULL) 
	{
		if (Values.Num() == 0) 
		{
			if (CloserIndex) 
			{
				*CloserIndex = INDEX_NONE;
			}
			if (CloserKey) 
			{
				*CloserKey = INDEX_NONE;
			}
			return TT();
		}

		TArray<T> keysArray;
		TArray<TT> valuesArray;
		//_Values
		Values.GenerateKeyArray(keysArray);
		Values.GenerateValueArray(valuesArray);

		T curCloser = ((Reference - keysArray[0]) >= (T)0) ? (Reference - keysArray[0]) : -(Reference - keysArray[0]);
		int32 curCloserIndex = 0;
		if (curCloser == 0 && NotEqual) 
		{
			curCloserIndex = -1;
		}

		for (int32 v = 1; v < Values.Num(); ++v) 
		{
			const T value = ((Reference - keysArray[v]) >= (T)0) ? (Reference - keysArray[v]) : -(Reference - keysArray[v]);
			if (value < curCloser) {
				if (!NotEqual || (NotEqual && value != 0.f)) { // From 0 to 0.f probably fix
					curCloser = value;
					curCloserIndex = v;
				}
			}
		}

		if (CloserIndex) 
		{
			*CloserIndex = curCloserIndex == -1 ? INDEX_NONE : curCloserIndex;
		}
		if (CloserKey) 
		{
			*CloserKey = Values.Num() == 0 ? INDEX_NONE : keysArray[curCloserIndex == -1 ? 0 : curCloserIndex];
		}
		return Values.Num() == 0 ? INDEX_NONE : valuesArray[curCloserIndex == -1 ? 0 : curCloserIndex];
	}
};