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
#include "Kismet/KismetSystemLibrary.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "CollisionQueryParams.h"
#include "PurpleprintCoreMath.h"
#include "PurpleprintCoreMisc.generated.h"

class UPrimitiveComponent;
class AStaticMeshActor;
class UMaterialInterface;
class UDecalComponent;
class UNiagaraComponent;
class UParticleSystemComponent;

UENUM(BlueprintType)
enum class EPurpleCoreAlignAxis : uint8 
{
	eFree	UMETA(DisplayName = "Free"),
	eX		UMETA(DisplayName = "X+"),
	eY		UMETA(DisplayName = "Y+"),
	eZ		UMETA(DisplayName = "Z+"),
	eXN		UMETA(DisplayName = "X-"),
	eYN		UMETA(DisplayName = "Y-"),
	eZN		UMETA(DisplayName = "Z-")
};
ENUM_RANGE_BY_FIRST_AND_LAST(EPurpleCoreAlignAxis, EPurpleCoreAlignAxis::eFree, EPurpleCoreAlignAxis::eZN);

UENUM(BlueprintType)
enum class EPurpleCoreAxis : uint8 
{
	eX		UMETA(DisplayName = "X+"),
	eY		UMETA(DisplayName = "Y+"),
	eZ		UMETA(DisplayName = "Z+"),
	eXN		UMETA(DisplayName = "X-"),
	eYN		UMETA(DisplayName = "Y-"),
	eZN		UMETA(DisplayName = "Z-")
};
ENUM_RANGE_BY_FIRST_AND_LAST(EPurpleCoreAxis, EPurpleCoreAxis::eX, EPurpleCoreAxis::eZN);

USTRUCT(BlueprintType)
struct FPurpleTraceStruct 
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
	FVector Origin = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
	float Length = 200.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
	EPurpleCoreAxis Direction = EPurpleCoreAxis::eZN;

	// Alternative vector manually set
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
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
		Length = 200.f;
		Direction = EPurpleCoreAxis::eZN;
		DirectionVector = FVector(0.f, 0.f, -1.f);
		Channel = ETraceTypeQuery::TraceTypeQuery1;
		bComplex = true;
		bIgnoreSelf = true;
		ActorsToIgnore = TArray<AActor*>();
		bDebug = false;
	}
};

USTRUCT(BlueprintType)
struct FPurpleTraceAlignStruct 
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
	FVector Origin = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace", meta = (EditCondition = "Direction != EPurpleCoreAlignAxis::eFree"))
	float Length = 200.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
	EPurpleCoreAlignAxis Direction = EPurpleCoreAlignAxis::eFree;

	// Alternative vector manually set
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace", meta = (EditCondition = "Direction != EPurpleCoreAlignAxis::eFree"))
	FVector DirectionVector = FVector(0.f, 0.f, -1.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace", meta = (EditCondition = "Direction != EPurpleCoreAlignAxis::eFree"))
	TEnumAsByte<ETraceTypeQuery> Channel = ETraceTypeQuery::TraceTypeQuery1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace", meta = (EditCondition = "Direction != EPurpleCoreAlignAxis::eFree"))
	bool bComplex = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace", meta = (EditCondition = "Direction != EPurpleCoreAlignAxis::eFree"))
	bool bIgnoreSelf = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actors", meta = (EditCondition = "Direction != EPurpleCoreAlignAxis::eFree"))
	TArray<AActor*> ActorsToIgnore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Align", meta = (EditCondition = "Direction != EPurpleCoreAlignAxis::eFree"))
	bool bAlignNormal = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Align", meta = (EditCondition = "Direction != EPurpleCoreAlignAxis::eFree"))
	FVector AlignNormalMask = FVector(0.f, 0.f, 1.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug", meta = (EditCondition = "Direction != EPurpleCoreAlignAxis::eFree"))
	bool bDebug = false;


	FPurpleTraceAlignStruct() 
	{
		Origin = FVector::ZeroVector;
		Length = 200.f;
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
};

DECLARE_DELEGATE_RetVal(FVector, FEditorCameraLocationDelegate);

UCLASS()
class PURPLEPRINTCORE_API UPurpleprintCoreMisc : public UBlueprintFunctionLibrary 
{
	GENERATED_BODY()

	UPurpleprintCoreMisc( const FObjectInitializer& ObjectInitializer );
private:

protected:

public:
	static FEditorCameraLocationDelegate EditorCameraLocationDelegate;

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

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Vector")
	static FVector2D ClampVector2D(FVector2D Value, FVector2D Min, FVector2D Max);

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Vector")
	static FVector ClampVector(FVector Value, FVector Min, FVector Max);

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

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Camera", meta = (WorldContext = "WorldContextObject"))
	static FVector GetActiveCameraLocation(const UObject* WorldContextObject);

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

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Collison")
	static bool IsValidCollisionProfileName(FName ProfileName);

	// This function is editor only
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Collison")
	static TArray<FName> GetAllCollisionProfileNames();

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Component")
	static bool SetPrimitiveComponentMaterials(UPrimitiveComponent* Component, TArray<UMaterialInterface*> Materials);

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Actor")
	static bool SetActorStaticMeshMaterials(AStaticMeshActor* Actor, TArray<UMaterialInterface*> Materials);

};