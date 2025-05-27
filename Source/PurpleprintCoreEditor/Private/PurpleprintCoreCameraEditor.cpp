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
PurpleprintCoreCameraEditor.cpp
================================================
*/


#include "PurpleprintCoreCameraEditor.h"
#include "PurpleprintCoreCameraTrackerEditor.h"
#include "Runtime/Core/Public/Logging/MessageLog.h"

#include "Engine/World.h"
#include "EditorViewportClient.h"
#include "Editor.h"
#include "LevelEditor.h"
#include "LevelEditorViewport.h"
#include "Engine/Engine.h"

void FPurpleprintCoreCameraEditor::Tick(float DeltaTime)
{
    if (GCurrentLevelEditingViewportClient)
    {
        FVector camLocation = GCurrentLevelEditingViewportClient->GetViewLocation();
        FRotator camRotation = GCurrentLevelEditingViewportClient->GetViewRotation();
		FPurpleprintCoreCameraTrackerEditor::SetLastCameraLocation(camLocation);
		FPurpleprintCoreCameraTrackerEditor::SetLastCameraRotation(camRotation);
       	// UE_LOG(LogTemp, Log, TEXT("[EditorCameraTracker] Cam Pos: %s | Rot: %s"),
    	//    *CamLocation.ToString(), *CamRotation.ToString());
    }
}