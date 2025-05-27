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
PurpleprintCoreCameraTrackerEditor.h
================================================
*/


#pragma once

#include "CoreMinimal.h"

// This class don't use UCLASS neither generated headers
class PURPLEPRINTCOREEDITOR_API FPurpleprintCoreCameraTrackerEditor
{

public:
	static FVector GetLastCameraLocation();
	static FRotator GetLastCameraRotation();
	static void SetLastCameraLocation(const FVector& NewLocation);
	static void SetLastCameraRotation(const FRotator& NewRotation);

private:
	static FVector LastCameraLocation;
	static FRotator LastCameraRotation;
};