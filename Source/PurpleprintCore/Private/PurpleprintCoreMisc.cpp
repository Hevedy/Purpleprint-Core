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
PurpleprintCoreMisc.cpp
================================================
*/

#include "PurpleprintCoreMisc.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Engine/Texture.h"
#include "Kismet/GameplayStatics.h"
#include "PurpleprintCoreMath.h"
#include "EulerTransform.h"
#include "Math/TransformNonVectorized.h"
#include "Runtime/Core/Public/Logging/MessageLog.h"
#include "Engine/CollisionProfile.h"
#include "PhysicsEngine/PhysicsSettings.h"

#include "GameFramework/Actor.h"
#include "Engine/StaticMeshActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/DecalComponent.h"

#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "NiagaraComponent.h"
#include "NiagaraSystem.h"

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

// To be able to perform regex operatins on level stream info package name
#if WITH_EDITOR
#include "Runtime/Core/Public/Internationalization/Regex.h"

#include "EditorSupportDelegates.h"
//#include "Editor/UnrealEd/Public/EditorUtilities.h"

// Needed for texture render
#include "Misc/MessageDialog.h"
#include "AssetToolsModule.h"
#include "PackageTools.h"
#include "Logging/MessageLog.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Engine/TextureRenderTarget2D.h"
#endif

#include "DrawDebugHelpers.h"

#include "NiagaraDataInterfaceArrayFunctionLibrary.h"
//#include "NiagaraFunctionLibrary.h"
//#include "NiagaraDataInterfaceArrayFloat.h"
//#include "NiagaraParameterCollectionInstance.h"
//#include "NiagaraDataInterface.h"

#define LOCTEXT_NAMESPACE "PurpleprintCoreMisc"

FEditorCameraLocationDelegate UPurpleprintCoreMisc::EditorCameraLocationDelegate;

UPurpleprintCoreMisc::UPurpleprintCoreMisc( const class FObjectInitializer& ObjectInitializer ) 
{

}

bool UPurpleprintCoreMisc::AreTransformArraysEqual(const TArray<FTransform>& A, const TArray<FTransform>& B)
{
	if (A.Num() != B.Num())
		return false;
	for (int32 i = 0; i < A.Num(); ++i)
	{
		if (!A[i].Equals(B[i]))
			return false;
	}
	return true;
}

EPurpleCoreAxis UPurpleprintCoreMisc::PurpleCoreAlignAxisToAxis(EPurpleCoreAlignAxis Align)
{
	switch (Align)
	{
		case EPurpleCoreAlignAxis::eX:
			return EPurpleCoreAxis::eX;
		case EPurpleCoreAlignAxis::eY:
			return EPurpleCoreAxis::eY;
		case EPurpleCoreAlignAxis::eZ:
			return EPurpleCoreAxis::eZ;
		case EPurpleCoreAlignAxis::eXN:
			return EPurpleCoreAxis::eXN;
		case EPurpleCoreAlignAxis::eYN:
			return EPurpleCoreAxis::eYN;
		case EPurpleCoreAlignAxis::eZN:
			return EPurpleCoreAxis::eZN;
		case EPurpleCoreAlignAxis::eFree:
		default:
			return EPurpleCoreAxis::eX;
	}
}

EPurpleCoreAlignAxis UPurpleprintCoreMisc::PurpleCoreAxisToAlignAxis(EPurpleCoreAxis Axis)
{
	switch (Axis)
	{
		case EPurpleCoreAxis::eX:
			return EPurpleCoreAlignAxis::eX;
		case EPurpleCoreAxis::eY:
			return EPurpleCoreAlignAxis::eY;
		case EPurpleCoreAxis::eZ:
			return EPurpleCoreAlignAxis::eZ;
		case EPurpleCoreAxis::eXN:
			return EPurpleCoreAlignAxis::eXN;
		case EPurpleCoreAxis::eYN:
			return EPurpleCoreAlignAxis::eYN;
		case EPurpleCoreAxis::eZN:
			return EPurpleCoreAlignAxis::eZN;
		default:
			return EPurpleCoreAlignAxis::eFree;
	}
}

FVector UPurpleprintCoreMisc::GetAxisVectorFromTransform(const FTransform& Transform, EPurpleCoreAxis Align)
{
	switch (Align)
	{
		case EPurpleCoreAxis::eX:
			return Transform.GetRotation().GetForwardVector();
		case EPurpleCoreAxis::eY:
			return Transform.GetRotation().GetRightVector();
		case EPurpleCoreAxis::eZ:
			return Transform.GetRotation().GetUpVector();
		case EPurpleCoreAxis::eXN:
			return Transform.GetRotation().GetForwardVector() * -1.f;
		case EPurpleCoreAxis::eYN:
			return Transform.GetRotation().GetRightVector() * -1.f;
		case EPurpleCoreAxis::eZN:
			return Transform.GetRotation().GetUpVector() * -1.f;
		default:
			return FVector::ZeroVector;
		}
}

FVector UPurpleprintCoreMisc::GetAlignVectorFromTransform(const FTransform& Transform, EPurpleCoreAlignAxis Align)
{
	switch (Align)
	{
		case EPurpleCoreAlignAxis::eX:
			return Transform.GetRotation().GetForwardVector();
		case EPurpleCoreAlignAxis::eY:
			return Transform.GetRotation().GetRightVector();
		case EPurpleCoreAlignAxis::eZ:
			return Transform.GetRotation().GetUpVector();
		case EPurpleCoreAlignAxis::eXN:
			return Transform.GetRotation().GetForwardVector() * -1.f;
		case EPurpleCoreAlignAxis::eYN:
			return Transform.GetRotation().GetRightVector() * -1.f;
		case EPurpleCoreAlignAxis::eZN:
			return Transform.GetRotation().GetUpVector() * -1.f;
		case EPurpleCoreAlignAxis::eFree:
		default:
			return FVector::ZeroVector;
		}
}

FVector2D UPurpleprintCoreMisc::FloatSplitToVector2D( const float FloatValue ) 
{
	return FVector2D( FMath::TruncToInt( FloatValue ), FMath::Frac( FloatValue ) );
}

FVector UPurpleprintCoreMisc::FloatSplitToVector( const float FloatValue ) 
{
	return FVector( FMath::TruncToInt( FloatValue ), FMath::Frac( FloatValue ), 0.0f );
}

FVector4 UPurpleprintCoreMisc::FloatSplitToVector4( const float FloatValue ) 
{
	return FVector4( FMath::TruncToInt( FloatValue ), FMath::Frac( FloatValue ), 0.0f, 0.0f );
}

FVector UPurpleprintCoreMisc::MaxVector(FVector A, FVector B)
{
	return FVector(FMath::Max(A.X, B.X), FMath::Max(A.Y, B.Y), FMath::Max(A.Z, B.Z));
}

FVector UPurpleprintCoreMisc::MinVector(FVector A, FVector B)
{
	return FVector(FMath::Min(A.X, B.X), FMath::Min(A.Y, B.Y), FMath::Min(A.Z, B.Z));
}

FIntVector UPurpleprintCoreMisc::MaxIntegerVector(FIntVector A, FIntVector B)
{
	return FIntVector(FMath::Max(A.X, B.X), FMath::Max(A.Y, B.Y), FMath::Max(A.Z, B.Z));
}

FIntVector UPurpleprintCoreMisc::MinIntegerVector(FIntVector A, FIntVector B)
{
	return FIntVector(FMath::Min(A.X, B.X), FMath::Min(A.Y, B.Y), FMath::Min(A.Z, B.Z));
}

FInt32Range UPurpleprintCoreMisc::ClampIntRange(const FInt32Range& Range, const int32 Min, const int32 Max)
{
	FInt32Range lRange;
	lRange.SetLowerBoundValue(FMath::Clamp(Range.GetLowerBoundValue(), Min, Max));
	lRange.SetUpperBoundValue(FMath::Clamp(Range.GetUpperBoundValue(), Min, Max));
	return lRange;
}

FFloatRange UPurpleprintCoreMisc::ClampFloatRange(const FFloatRange& Range, const float Min, const float Max)
{
	FFloatRange lRange;
	lRange.SetLowerBoundValue(FMath::Clamp(Range.GetLowerBoundValue(), Min, Max));
	lRange.SetUpperBoundValue(FMath::Clamp(Range.GetUpperBoundValue(), Min, Max));
	return lRange;
}

FVector2D UPurpleprintCoreMisc::ClampVector2D(FVector2D Value, FVector2D Min, FVector2D Max) 
{
	FVector2D local;
	local.X = FMath::Clamp(Value.X, Min.X, Max.X);
	local.Y = FMath::Clamp(Value.Y, Min.Y, Max.Y);
	return local;
}

FVector UPurpleprintCoreMisc::ClampVector(FVector Value, FVector Min, FVector Max) 
{
	FVector local;
	local.X = FMath::Clamp(Value.X, Min.X, Max.X);
	local.Y = FMath::Clamp(Value.Y, Min.Y, Max.Y);
	local.Z = FMath::Clamp(Value.Z, Min.Z, Max.Z);
	return local;
}

FIntVector UPurpleprintCoreMisc::ClampIntegerVector(FIntVector X, FIntVector Min, FIntVector Max)
{
	return FIntVector(FMath::Clamp(X.X, Min.X, Max.X), FMath::Clamp(X.Y, Min.Y, Max.Y), FMath::Clamp(X.Z, Min.Z, Max.Z));
}

FVector4 UPurpleprintCoreMisc::ClampVector4(FVector4 Value, FVector4 Min, FVector4 Max) 
{
	FVector4 local;
	local.X = FMath::Clamp(Value.X, Min.X, Max.X);
	local.Y = FMath::Clamp(Value.Y, Min.Y, Max.Y);
	local.Z = FMath::Clamp(Value.Z, Min.Z, Max.Z);
	local.W = FMath::Clamp(Value.W, Min.W, Max.W);
	return local;
}

FVector2D UPurpleprintCoreMisc::VectorToVector2D( const FVector &VecValue ) 
{
	return FVector2D( VecValue.X, VecValue.Y );
}

FVector2D UPurpleprintCoreMisc::Vector4ToVector2D( const FVector4 &Vec4Value ) 
{
	return FVector2D( Vec4Value.X, Vec4Value.Y );
}

FVector UPurpleprintCoreMisc::VectorIntToVector( const FIntVector &VecIntValue ) 
{
	return FVector( FMath::TruncToInt((float)VecIntValue.X ), FMath::TruncToInt((float)VecIntValue.Y ), FMath::TruncToInt((float)VecIntValue.Z ) );
}

FVector UPurpleprintCoreMisc::Vector2DToVector( const FVector2D &Vec2Value ) 
{
	return FVector( Vec2Value.X, Vec2Value.Y, 0.0f );
}

FVector UPurpleprintCoreMisc::Vector4ToVector( const FVector4 &Vec4Value ) 
{
	return FVector( Vec4Value.X, Vec4Value.Y, Vec4Value.Z );
}

FIntVector UPurpleprintCoreMisc::VectorToVectorInt( const FVector &VecValue ) 
{
	return FIntVector( VecValue.X, VecValue.Y, VecValue.Z );
}

FVector4 UPurpleprintCoreMisc::Vector2DToVector4( const FVector2D &Vec2Value ) 
{
	return FVector4( Vec2Value.X, Vec2Value.Y, 0.0f, 0.0f );
}

FVector4 UPurpleprintCoreMisc::VectorToVector4( const FVector &VecValue ) 
{
	return FVector4( VecValue.X, VecValue.Y, VecValue.Z, 0.0f );
}

FRotator UPurpleprintCoreMisc::RotatorOrderInvert( const FRotator &RotValue ) 
{
	return FRotator( RotValue.Roll, RotValue.Yaw, RotValue.Pitch );
}

FVector2D UPurpleprintCoreMisc::Vector2DOrderInvert( const FVector2D &Vec2Value ) 
{
	return FVector2D( Vec2Value.Y, Vec2Value.X );
}

FVector UPurpleprintCoreMisc::VectorOrderInvert( const FVector &VecValue ) 
{
	return FVector( VecValue.Z, VecValue.Y, VecValue.X );
}

FVector4 UPurpleprintCoreMisc::Vector4OrderInvert( const FVector4 &Vec4Value ) 
{
	return FVector4( Vec4Value.W, Vec4Value.Z, Vec4Value.Y, Vec4Value.X );
}

FRotator UPurpleprintCoreMisc::RotatorOrderRight( const FRotator &RotValue ) 
{
	return FRotator( RotValue.Roll, RotValue.Pitch, RotValue.Yaw );
}

FVector UPurpleprintCoreMisc::VectorOrderRight( const FVector &VecValue ) 
{
	return FVector( VecValue.Z, VecValue.X, VecValue.Y );
}

FVector4 UPurpleprintCoreMisc::Vector4OrderRight( const FVector4 &Vec4Value ) 
{
	return FVector4( Vec4Value.W, Vec4Value.X, Vec4Value.Y, Vec4Value.Z );
}

FRotator UPurpleprintCoreMisc::RotatorOrderLeft( const FRotator &RotValue ) 
{
	return FRotator( RotValue.Yaw, RotValue.Roll, RotValue.Pitch );
}

FVector UPurpleprintCoreMisc::VectorOrderLeft( const FVector &VecValue ) 
{
	return FVector( VecValue.Y, VecValue.Z, VecValue.X );
}

FVector4 UPurpleprintCoreMisc::Vector4OrderLeft( const FVector4 &Vec4Value ) 
{
	return FVector4( Vec4Value.Y, Vec4Value.Z, Vec4Value.W, Vec4Value.X );
}

uint8 UPurpleprintCoreMisc::GetByteArrayAlpha(const TArray<uint8>& Array, const float Alpha) 
{
	int32 c = Array.Num();
	if (c < 1) { return 0; }
	else if (c == 1) { return Array[0]; }
	int32 cCount = FMath::Max(0, c - 1);
	int32 cutNum = FMath::RoundToInt(FMath::GetMappedRangeValueClamped(FVector2D(0.0f, 1.0f), FVector2D(0.0f, cCount), Alpha));
	return Array[cutNum];
}

int32 UPurpleprintCoreMisc::GetIntegerArrayAlpha(const TArray<int32>& Array, const float Alpha) 
{
	int32 c = Array.Num();
	if (c < 1) { return -1; }
	else if (c == 1) { return Array[0]; }
	int32 cCount = FMath::Max(0, c - 1);
	int32 cutNum = FMath::RoundToInt(FMath::GetMappedRangeValueClamped(FVector2D(0.0f, 1.0f), FVector2D(0.0f, cCount), Alpha));
	return Array[cutNum];
}

float UPurpleprintCoreMisc::GetFloatArrayAlpha(const TArray<float>& Array, const float Alpha) 
{
	int32 c = Array.Num();
	if (c < 1) { return -1.f; }
	else if (c == 1) { return Array[0]; }
	int32 cCount = FMath::Max(0, c - 1);
	int32 cutNum = FMath::RoundToInt(FMath::GetMappedRangeValueClamped(FVector2D(0.0f, 1.0f), FVector2D(0.0f, cCount), Alpha));
	return Array[cutNum];
}

FVector2D UPurpleprintCoreMisc::GetVector2DArrayAlpha(const TArray<FVector2D>& Array, const float Alpha) 
{
	int32 c = Array.Num();
	if (c < 1) { return FVector2D(-1.f, -1.f); }
	else if (c == 1) { return Array[0]; }
	int32 cCount = FMath::Max(0, c - 1);
	int32 cutNum = FMath::RoundToInt(FMath::GetMappedRangeValueClamped(FVector2D(0.0f, 1.0f), FVector2D(0.0f, cCount), Alpha));
	return Array[cutNum];
}

FVector UPurpleprintCoreMisc::GetVectorArrayAlpha(const TArray<FVector>& Array, const float Alpha) 
{
	int32 c = Array.Num();
	if (c < 1) { return  FVector(-1.f, -1.f, -1.f); }
	else if (c == 1) { return Array[0]; }
	int32 cCount = FMath::Max(0, c - 1);
	int32 cutNum = FMath::RoundToInt(FMath::GetMappedRangeValueClamped(FVector2D(0.0f, 1.0f), FVector2D(0.0f, cCount), Alpha));
	return Array[cutNum];
}

FRotator UPurpleprintCoreMisc::GetRotatorArrayAlpha(const TArray<FRotator>& Array, const float Alpha) 
{
	int32 c = Array.Num();
	if (c < 1) { return  FRotator(-1.f, -1.f, -1.f); }
	else if (c == 1) { return Array[0]; }
	int32 cCount = FMath::Max(0, c - 1);
	int32 cutNum = FMath::RoundToInt(FMath::GetMappedRangeValueClamped(FVector2D(0.0f, 1.0f), FVector2D(0.0f, cCount), Alpha));
	return Array[cutNum];
}

FTransform UPurpleprintCoreMisc::GetTransformArrayAlpha(const TArray<FTransform>& Array, const float Alpha) 
{
	int32 c = Array.Num();
	if (c < 1) { return  FTransform(FRotator(-1.f, -1.f, -1.f), FVector(-1.f, -1.f, -1.f), FVector(-1.f, -1.f, -1.f)); }
	else if (c == 1) { return Array[0]; }
	int32 cCount = FMath::Max(0, c - 1);
	int32 cutNum = FMath::RoundToInt(FMath::GetMappedRangeValueClamped(FVector2D(0.0f, 1.0f), FVector2D(0.0f, cCount), Alpha));
	return Array[cutNum];
}

FTransform UPurpleprintCoreMisc::GetTransformArrayAlphaLerp(const TArray<FTransform>& Array, const float Alpha, const bool bLoop) 
{
	int32 sA = Array.Num();
	const int32 sALast = sA - 1;
	if (sA < 2) {
		if (sA < 1) {
			return  FTransform(FRotator(-1.f, -1.f, -1.f), FVector(-1.f, -1.f, -1.f), FVector(-1.f, -1.f, -1.f));
		}
		else { //(sA == 1) 
			return Array[0];
		}
	}
	else {
		if (Alpha == 0.f) {
			return Array[0];
		}
		else if (Alpha == 1.0f) {
			return Array[sALast];
		}
	}
	float alpha = Alpha * sALast;
	const int32 sNum = FMath::FloorToInt(alpha);
	alpha -= sNum;
	const int32 sNumNext = sNum + 1;
	FTransform vC = Array[sNum];
	FTransform vT = Array[sNumNext];
	FTransform vF = FTransform();
	vF.FTransform::Blend(vC, vT, alpha);
	return vF;
}

FVector UPurpleprintCoreMisc::GetActiveCameraLocation(const UObject* WorldContextObject, FRotator& Rotation)
{
	UWorld* world = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);

	if (!world) return FVector::ZeroVector;

	if (world->IsGameWorld())
	{
		APlayerController* pc = UGameplayStatics::GetPlayerController(world, 0);
		if (pc)
		{
			FVector camLoc;
			FRotator camRot;
			pc->GetPlayerViewPoint(camLoc, camRot);
			Rotation = camRot;
			return camLoc;
		}
	}

#if WITH_EDITOR
	if (EditorCameraLocationDelegate.IsBound())
	{
		FTransform t = EditorCameraLocationDelegate.Execute();
		Rotation = t.GetRotation().Rotator();
		return t.GetLocation();
	}
#endif

	return FVector::ZeroVector;
}

AActor* UPurpleprintCoreMisc::SpawnActorClone(AActor* Actor, const FTransform& Transform) 
{
	if (!Actor) 
	{
		return nullptr;
	}
	UWorld* w = Actor->GetWorld();
	if (!w) 
	{
		return nullptr;
	}
	FActorSpawnParameters params = FActorSpawnParameters();
	params.Template = Actor;

	UClass* aClass = Actor->GetClass();
	AActor* const sActor = w->SpawnActor<AActor>(aClass,Transform, params);
	return sActor;

}

void UPurpleprintCoreMisc::CopySceneComponentParams(USceneComponent* Source, USceneComponent* Target)
{
	if (!Source || !Target) return;
	Target->SetMobility(Source->Mobility);
	Target->DetailMode = Source->DetailMode;
}

void UPurpleprintCoreMisc::CopyPrimitiveComponentParams(UPrimitiveComponent* Source, UPrimitiveComponent* Target, bool bCopyMaterials)
{
	if (!Source || !Target) return;
	Target->SetMobility(Source->Mobility);
	Target->DetailMode = Source->DetailMode;
	Target->SetCollisionProfileName(Source->GetCollisionProfileName());
	Target->SetCollisionObjectType(Source->GetCollisionObjectType());
	Target->SetCollisionEnabled(Source->GetCollisionEnabled());
	Target->bCastFarShadow = Source->bCastFarShadow;
	Target->bCastStaticShadow = Source->bCastStaticShadow;
	Target->bCastDynamicShadow = Source->bCastDynamicShadow;
	Target->SetCastShadow(Source->CastShadow);
	Target->SetLightingChannels(Source->LightingChannels.bChannel0, Source->LightingChannels.bChannel1, Source->LightingChannels.bChannel2);
	Target->SetCullDistance(Source->LDMaxDrawDistance);

	if (!bCopyMaterials) return;

	TArray<UMaterialInterface*> materials;
	Source->GetUsedMaterials(materials);
	SetPrimitiveComponentMaterials(Source, materials);
}

void UPurpleprintCoreMisc::CopyStaticMeshComponentParams(UStaticMeshComponent* Source, UStaticMeshComponent* Target)
{
	if (!Source || !Target) return;
	Target->SetStaticMesh(Source->GetStaticMesh());
	CopyPrimitiveComponentParams(Source, Target, true);
}

// This is the only one that isn't primitive
void UPurpleprintCoreMisc::CopyDecalComponentParams(UDecalComponent* Source, UDecalComponent* Target)
{
	if (!Source || !Target) return;
	Target->SetMobility(Source->Mobility);
	Target->DetailMode = Source->DetailMode;
	Target->SetDecalMaterial(Source->GetDecalMaterial());
	Target->FadeStartDelay = Source->FadeStartDelay;
	Target->FadeDuration = Source->FadeDuration;
	Target->FadeInStartDelay = Source->FadeInStartDelay;
	Target->FadeInDuration = Source->FadeInDuration;
	Target->SetFadeScreenSize(Source->FadeScreenSize);
}

void UPurpleprintCoreMisc::CopyNiagaraComponentParams(UNiagaraComponent* Source, UNiagaraComponent* Target)
{
	if (!Source || !Target) return;
	Target->SetAsset(Source->GetAsset());
	CopyPrimitiveComponentParams(Source, Target, false);
}

void UPurpleprintCoreMisc::CopyParticleComponentParams(UParticleSystemComponent* Source, UParticleSystemComponent* Target)
{
	if (!Source || !Target) return;
	Target->SetTemplate(Source->Template);
	CopyPrimitiveComponentParams(Source, Target, false);
}

FString UPurpleprintCoreMisc::GenerateStaticMeshRefKey(const UStaticMeshComponent* MeshComp)
{
	if (!IsValid(MeshComp) || !MeshComp->GetStaticMesh())
		return TEXT("Invalid");

	FString key = MeshComp->GetStaticMesh()->GetPathName(); // Use the static mesh path as the key

	// Add material names to the key
	int32 numMaterials = MeshComp->GetNumMaterials();
	for (int32 i = 0; i < numMaterials; ++i)
	{
		UMaterialInterface* material = MeshComp->GetMaterial(i);
		FString matName = IsValid(material) ? material->GetPathName() : TEXT("None");
		key += FString::Printf(TEXT("_Mat%d:%s"), i, *matName);
	}

	return key;
}

FString UPurpleprintCoreMisc::GenerateDecalRefKey(const UDecalComponent* Decal)
{
	if (!IsValid(Decal)) return TEXT("Invalid");
	UMaterialInterface* mat = Decal->GetDecalMaterial();
	return mat ? mat->GetPathName() : TEXT("None");
}

FString UPurpleprintCoreMisc::GenerateNiagaraRefKey(const UNiagaraComponent* Niagara)
{
	if (!IsValid(Niagara)) return TEXT("Invalid");
	UNiagaraSystem* system = Niagara->GetAsset();
	return system ? system->GetPathName() : TEXT("None");
}

FString UPurpleprintCoreMisc::GenerateEmitterRefKey(AEmitter* Emitter)
{
	if (!IsValid(Emitter)) return TEXT("Invalid");

	const UParticleSystemComponent* particleComp = Emitter->GetParticleSystemComponent();
	if (!IsValid(particleComp)) return TEXT("NoComp");

	UParticleSystem* pTemplate = particleComp->Template;
	return IsValid(pTemplate) ? pTemplate->GetPathName() : TEXT("NoTemplate");
}

FString UPurpleprintCoreMisc::GenerateGenericActorRefKey(const AActor* Actor)
{
	if (!IsValid(Actor)) return TEXT("Invalid");

	UClass* actorClass = Actor->GetClass();
	FString key = actorClass->GetPathName();

	/*
	if (const auto* Child = Cast<AChildActor>(Actor))
	{
		if (const auto* Inner = Child->GetChildActor())
		{
			Key += TEXT("_Child:") + Inner->GetClass()->GetPathName();
		}
	}*/

	return key;
}

bool UPurpleprintCoreMisc::IsValidCollisionProfileName(FName ProfileName)
{
	FCollisionResponseTemplate Dummy;
	return UCollisionProfile::Get()->GetProfileTemplate(ProfileName, Dummy);
}

TArray<FName> UPurpleprintCoreMisc::GetAllCollisionProfileNames()
{
#if WITH_EDITOR
	TArray<TSharedPtr<FName>> SharedNames;
	UCollisionProfile::GetProfileNames(SharedNames);

	TArray<FName> Names;
	Names.Reserve(SharedNames.Num());
	for (const TSharedPtr<FName>& SharedName : SharedNames)
	{
		if (const FName* Name = SharedName.Get())
		{
			Names.Add(*Name);
		}
	}

	return Names;
#else
	return TArray<FName>();
#endif
}


bool UPurpleprintCoreMisc::SetPrimitiveComponentMaterials(UPrimitiveComponent* Component, TArray<UMaterialInterface*> Materials)
{
	if (!Component ||Materials.Num() == 0) return false;
	uint8 maxIndex = Component->GetNumMaterials() - 1;
	uint8 index = 0;
	for (UMaterialInterface* mat : Materials) {
		if (mat) {
			Component->SetMaterial(FMath::Min(index, maxIndex), mat);
		}
		index++;
	}
	return true;
}

bool UPurpleprintCoreMisc::SetActorStaticMeshMaterials(AStaticMeshActor* Actor, TArray<UMaterialInterface*> Materials)
{
	if (!Actor || Materials.Num() == 0) return false;
	return SetPrimitiveComponentMaterials(Actor->GetStaticMeshComponent(), Materials);
}

// Kind of function replica from core given we cannot create non power of two
UTexture2D* UPurpleprintCoreMisc::ConstructTexture2DNonPowerTwo(UTextureRenderTarget2D* RT, UObject* Outer, const FString& NewTexName, EObjectFlags InObjectFlags, uint32 Flags, TArray<uint8>* AlphaOverride)
{
	UTexture2D* Result = NULL;
#if WITH_EDITOR
	if (!RT)
	{
		return Result;
	}
	// Check render target size is valid
	const bool bIsValidSize = (RT->SizeX != 0 && RT->SizeY != 0);
	// The r2t resource will be needed to read its surface contents
	FRenderTarget* RenderTarget = RT->GameThread_GetRenderTargetResource();

	const EPixelFormat PixelFormat = RT->GetFormat();
	ETextureSourceFormat TextureFormat = TSF_Invalid;
	switch (PixelFormat)
	{
	case PF_B8G8R8A8:
		TextureFormat = TSF_BGRA8;
		break;
	case PF_FloatRGBA:
		TextureFormat = TSF_RGBA16F;
		break;
	case PF_G8:
		TextureFormat = TSF_G8;
		break;
	default:
	{
		FText InvalidFormatMessage = NSLOCTEXT("TextureRenderTarget2D", "UnsupportedFormatRenderTarget2DWarning", "Unsupported format when creating Texture2D from TextureRenderTarget2D. Supported formats are B8G8R8A8, FloatRGBA and G8.");
		FMessageDialog::Open(EAppMsgType::Ok, InvalidFormatMessage);
	}
	}

	// exit if source is not compatible.
	if (bIsValidSize == false || RenderTarget == NULL || TextureFormat == TSF_Invalid)
	{
		return Result;
	}

	// create the 2d texture
	Result = NewObject<UTexture2D>(Outer, FName(*NewTexName), InObjectFlags);

#if ENGINE_MAJOR_VERSION >= 5 && ENGINE_MINOR_VERSION >= 6
	RT->UpdateTexture2D(Result, TextureFormat, Flags, AlphaOverride);
	//RT->UpdateTexture(Result, Flags, AlphaOverride);
	//UpdateTexture(UTexture * InTexture, EConstructTextureFlags InFlags = CTF_Default, const TArray<uint8>*InAlphaOverride = nullptr, FOnTextureChangingDelegate InOnTextureChangingDelegate = OnTextureChangingDefault, FText * OutErrorMessage = nullptr);
#else
	RT->UpdateTexture2D(Result, TextureFormat, Flags, AlphaOverride);
#endif

	// if render target gamma used was 1.0 then disable SRGB for the static texture
	if (FMath::Abs(RenderTarget->GetDisplayGamma() - 1.0f) < KINDA_SMALL_NUMBER)
	{
		Flags &= ~CTF_SRGB;
	}

	Result->SRGB = (Flags & CTF_SRGB) != 0;
	Result->MipGenSettings = TMGS_FromTextureGroup;

	if ((Flags & CTF_AllowMips) == 0)
	{
		Result->MipGenSettings = TMGS_NoMipmaps;
	}


	if (Flags & CTF_Compress)
	{
		// Set compression options.
		Result->DeferCompression = (Flags & CTF_DeferCompression) ? true : false;
	}
	else
	{
		// Disable compression
		Result->CompressionNone = true;
		Result->DeferCompression = false;
	}
	Result->PostEditChange();
#endif
	return Result;
}


UTexture2D* UPurpleprintCoreMisc::RenderTargetCreateStaticTexture2DNonPowerTwoEditorOnly(UTextureRenderTarget2D* RenderTarget, FString InName, enum TextureCompressionSettings CompressionSettings, enum TextureMipGenSettings MipSettings)
{
#if WITH_EDITOR
	if (!RenderTarget)
	{
		FMessageLog("Blueprint").Warning(LOCTEXT("RenderTargetCreateStaticTexture2DNonPowerTwoEditorOnly_InvalidRenderTarget", "RenderTargetCreateStaticTexture2DNonPowerTwoEditorOnly: RenderTarget must be non-null."));
		return nullptr;
	}
#if ENGINE_MAJOR_VERSION >= 5
	else if (!RenderTarget->GameThread_GetRenderTargetResource())
#else
	else if (!RenderTarget->Resource)
#endif
	{
		FMessageLog("Blueprint").Warning(LOCTEXT("RenderTargetCreateStaticTexture2DNonPowerTwoEditorOnly_ReleasedRenderTarget", "RenderTargetCreateStaticTexture2DNonPowerTwoEditorOnly: RenderTarget has been released."));
		return nullptr;
	}
	else
	{
		FString Name;
		FString PackageName;
		IAssetTools& AssetTools = FModuleManager::Get().LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

		//Use asset name only if directories are specified, otherwise full path
		if (!InName.Contains(TEXT("/")))
		{
			FString AssetName = RenderTarget->GetOutermost()->GetName();
			const FString SanitizedBasePackageName = UPackageTools::SanitizePackageName(AssetName);
			const FString PackagePath = FPackageName::GetLongPackagePath(SanitizedBasePackageName) + TEXT("/");
			AssetTools.CreateUniqueAssetName(PackagePath, InName, PackageName, Name);
		}
		else
		{
			InName.RemoveFromStart(TEXT("/"));
			InName.RemoveFromStart(TEXT("Content/"));
			InName.StartsWith(TEXT("Game/")) == true ? InName.InsertAt(0, TEXT("/")) : InName.InsertAt(0, TEXT("/Game/"));
			AssetTools.CreateUniqueAssetName(InName, TEXT(""), PackageName, Name);
		}

		UObject* NewObj = nullptr;

		// create a static 2d texture
		NewObj = ConstructTexture2DNonPowerTwo(RenderTarget, CreatePackage(*PackageName), Name, RenderTarget->GetMaskedFlags() | RF_Public | RF_Standalone, CTF_Default | CTF_AllowMips, NULL);
		UTexture2D* NewTex = Cast<UTexture2D>(NewObj);

		if (NewTex != nullptr)
		{
			// package needs saving
			NewObj->MarkPackageDirty();

			// Notify the asset registry
			FAssetRegistryModule::AssetCreated(NewObj);

			// Update Compression and Mip settings
			NewTex->CompressionSettings = CompressionSettings;
			NewTex->MipGenSettings = MipSettings;
			NewTex->PostEditChange();

			return NewTex;
		}
		FMessageLog("Blueprint").Warning(LOCTEXT("RenderTargetCreateStaticTexture2DNonPowerTwoEditorOnly_FailedToCreateTexture", "RenderTargetCreateStaticTexture2DNonPowerTwoEditorOnly: Failed to create a new texture."));
	}
#else
	FMessageLog("Blueprint").Error(LOCTEXT("Texture2D's cannot be created at runtime.", "RenderTargetCreateStaticTexture2DNonPowerTwoEditorOnly: Can't create Texture2D at run time. "));
#endif
	return nullptr;
}

TArray<FTransform> UPurpleprintCoreMisc::SnapActorsToSimulatedTransform(TArray<AActor*> Actors)
{
#if WITH_EDITOR
	if (Actors.Num() == 0) return TArray<FTransform>();

	TArray<FTransform> transforms;

	for( auto actor : Actors)
	{
		// Get transform
		FTransform simulatedTransform = actor->GetActorTransform();
		transforms.Add(simulatedTransform);
		// Apply simulation transform
		actor->Modify(); // For editor undo/redo support
		actor->SetActorTransform(simulatedTransform, false, nullptr, ETeleportType::TeleportPhysics);
	}
	// Mask as dirty so the level is saved with the new transforms
	FEditorScriptExecutionGuard scriptGuard;
	FEditorSupportDelegates::RedrawAllViewports.Broadcast();

	return transforms;
#else
	return TArray<FTransform>();
#endif
}

/*
bool UPurpleprintCoreMisc::GetNiagaraVectorParamArray(UNiagaraComponent* NiagaraComponent, FName ParameterName, TArray<FVector>& OutArray)
{
	// use instead #include "NiagaraDataInterfaceArrayFunctionLibrary.h"
	if (!NiagaraComponent) return false;

	
	// Get instance data
	FNiagaraUserRedirectionParameterStore& Params = NiagaraComponent->GetOverrideParameters();

	// Find the data interface
	UNiagaraDataInterfaceArrayFloat3* VectorArrayDI = Cast<UNiagaraDataInterfaceArrayFloat3>(Params.GetDataInterface(ParameterName));

	if (!VectorArrayDI) return false;

	// Get array directly
	const TArray<FVector>& InternalArray = VectorArrayDI->GetArrayReference();

	OutArray = InternalArray;
	return false;
}
*/

#undef LOCTEXT_NAMESPACE