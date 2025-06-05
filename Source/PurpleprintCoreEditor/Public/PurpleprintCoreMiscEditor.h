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
PurpleprintCoreMiscEditor.h
================================================
*/


#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PurpleprintCoreMiscEditor.generated.h"

class UStaticMesh;

UCLASS()
class PURPLEPRINTCOREEDITOR_API UPurpleprintCoreMiscEditor : public UBlueprintFunctionLibrary 
{
	GENERATED_BODY()

	UPurpleprintCoreMiscEditor( const FObjectInitializer& ObjectInitializer );
private:

protected:

public:

	// Returns the full transform (location, rotation, scale) of the currently active editor camera.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Editor|Camera", meta = (DevelopmentOnly))
	static FTransform GetEditorActiveCameraTransform();

	// Returns the world location (vector) of the currently active editor camera.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Editor|Camera", meta = (DevelopmentOnly))
	static FVector GetEditorActiveCameraLocation();

	// Returns the rotation (pitch, yaw, roll) of the currently active editor camera.
	UFUNCTION(BlueprintPure, Category = "Purpleprint|Editor|Camera", meta = (DevelopmentOnly))
	static FRotator GetEditorActiveCameraRotation();

	UFUNCTION(BlueprintCallable, Category = "Purpleprint|Editor|StaticMesh", meta = (DevelopmentOnly))
	static void SetMinimumLODForPlatforms(UStaticMesh* StaticMesh, const TMap<FName, int32>& PlatformMinimumLODs);

};