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
#endif
	return FTransform();
}

FVector UPurpleprintCoreMiscEditor::GetEditorActiveCameraLocation()
{
#if WITH_EDITOR
	return FPurpleprintCoreCameraTrackerEditor::GetLastCameraLocation();
#endif
	return FVector::ZeroVector;
}

FRotator UPurpleprintCoreMiscEditor::GetEditorActiveCameraRotation()
{
#if WITH_EDITOR
	return FPurpleprintCoreCameraTrackerEditor::GetLastCameraRotation();
#endif
	return FRotator::ZeroRotator;
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