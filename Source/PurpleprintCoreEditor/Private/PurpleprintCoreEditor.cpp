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
PurpleprintCoreEditor.cpp
================================================
*/

#include "PurpleprintCoreEditor.h"
#include "PurpleprintCoreMisc.h"
#include "CoreMinimal.h"
#include "HAL/PlatformProcess.h"
#include "PurpleprintCoreCameraEditor.h"
#include "PurpleprintCoreCameraTrackerEditor.h"

#define LOCTEXT_NAMESPACE "PurpleprintCoreEditorModule"

TSharedPtr<FPurpleprintCoreCameraEditor> GCameraTracker;

void FPurpleprintCoreEditor::StartupModule() 
{
#if WITH_EDITOR
	UPurpleprintCoreMisc::EditorCameraLocationDelegate = FEditorCameraLocationDelegate::CreateStatic(&FPurpleprintCoreCameraTrackerEditor::GetLastCameraTransform);
#endif
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
	GCameraTracker = MakeShareable(new FPurpleprintCoreCameraEditor());
}


void FPurpleprintCoreEditor::ShutdownModule() 
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	GCameraTracker.Reset();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE( FPurpleprintCoreEditor, PurpleprintCoreEditor )