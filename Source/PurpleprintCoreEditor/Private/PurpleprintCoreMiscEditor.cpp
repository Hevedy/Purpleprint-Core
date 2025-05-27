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

#include "Engine/World.h"
#include "EditorViewportClient.h"
#include "Editor.h"
#include "LevelEditor.h"
#include "LevelEditorViewport.h"
#include "Engine/Engine.h"


UPurpleprintCoreMiscEditor::UPurpleprintCoreMiscEditor( const class FObjectInitializer& ObjectInitializer ) 
{

}

FVector UPurpleprintCoreMiscEditor::GetEditorActiveCameraLocation()
{
#if WITH_EDITOR
	FPurpleprintCoreCameraTrackerEditor::GetLastCameraLocation();
#endif
	return FVector::ZeroVector;
}

FRotator UPurpleprintCoreMiscEditor::GetEditorActiveCameraRotation()
{
#if WITH_EDITOR
	FPurpleprintCoreCameraTrackerEditor::GetLastCameraRotation();
#endif
	return FRotator::ZeroRotator;
}