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
PurpleprintCoreCameraTrackerEditor.cpp
================================================
*/

#include "PurpleprintCoreCameraTrackerEditor.h"

FVector FPurpleprintCoreCameraTrackerEditor::LastCameraLocation = FVector::ZeroVector;
FRotator FPurpleprintCoreCameraTrackerEditor::LastCameraRotation = FRotator::ZeroRotator;

FVector FPurpleprintCoreCameraTrackerEditor::GetLastCameraLocation()
{
	return LastCameraLocation;
}

FRotator FPurpleprintCoreCameraTrackerEditor::GetLastCameraRotation()
{
	return LastCameraRotation;
}

void FPurpleprintCoreCameraTrackerEditor::SetLastCameraLocation(const FVector& NewLocation)
{
	LastCameraLocation = NewLocation;
}

void FPurpleprintCoreCameraTrackerEditor::SetLastCameraRotation(const FRotator& NewRotation)
{
	LastCameraRotation = NewRotation;
}