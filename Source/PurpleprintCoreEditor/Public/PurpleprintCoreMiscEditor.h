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


UCLASS()
class PURPLEPRINTCOREEDITOR_API UPurpleprintCoreMiscEditor : public UBlueprintFunctionLibrary 
{
	GENERATED_BODY()

	UPurpleprintCoreMiscEditor( const FObjectInitializer& ObjectInitializer );
private:

protected:

public:

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Editor|Camera", meta = (DevelopmentOnly))
	static FVector GetEditorActiveCameraLocation();

	UFUNCTION(BlueprintPure, Category = "Purpleprint|Editor|Camera", meta = (DevelopmentOnly))
	static FRotator GetEditorActiveCameraRotation();

};