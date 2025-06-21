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
PurpleprintCoreMiscEditor.cpp
================================================
*/

#include "PurpleprintCoreMiscEditor.h"
#include "PurpleprintCoreCameraTrackerEditor.h"

#include "Engine/StaticMesh.h"

#define LOCTEXT_NAMESPACE "PurpleprintCoreMiscEditor"

UPurpleprintCoreMiscEditor::UPurpleprintCoreMiscEditor( const class FObjectInitializer& ObjectInitializer ) 
{

}

FTransform UPurpleprintCoreMiscEditor::GetEditorActiveCameraTransform()
{
#if WITH_EDITOR
	return FPurpleprintCoreCameraTrackerEditor::GetLastCameraTransform();
#else
	// Return a default transform if not in editor mode
	// This is useful to avoid crashes when this function is called outside of the editor context.
	// You can modify this default transform as needed.
	return FTransform();
#endif
}

FVector UPurpleprintCoreMiscEditor::GetEditorActiveCameraLocation()
{
#if WITH_EDITOR
	return FPurpleprintCoreCameraTrackerEditor::GetLastCameraLocation();
#else
	return FVector::ZeroVector;
#endif
}

FRotator UPurpleprintCoreMiscEditor::GetEditorActiveCameraRotation()
{
#if WITH_EDITOR
	return FPurpleprintCoreCameraTrackerEditor::GetLastCameraRotation();
#else
	return FRotator::ZeroRotator;
#endif
}

void UPurpleprintCoreMiscEditor::SetMinimumLODForPlatforms(UStaticMesh* StaticMesh, const TMap<FName, int32>& PlatformMinimumLODs)
{
	if(StaticMesh == nullptr || PlatformMinimumLODs.Num() == 0)
	{
		return;
	}

	for (const TPair<FName, int32>& pMinimumLOD : PlatformMinimumLODs)
	{
		FPerPlatformInt pLOD = FPerPlatformInt(pMinimumLOD.Value);
		StaticMesh->SetMinLOD(pLOD);
	}
}

#undef LOCTEXT_NAMESPACE