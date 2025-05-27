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
PurpleprintCoreManagerComponent.cpp
================================================
*/

#include "Components/PurpleprintCoreManagerComponent.h"
#include "PurpleprintCoreMisc.h"
#include "Misc/EngineVersionComparison.h"

UPurpleprintCoreManagerComponent::UPurpleprintCoreManagerComponent(const FObjectInitializer& ObjectInitializer)
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = true;

/*
#if UE_VERSION_NEWER_THAN(5, 3, 0)
#if WITH_EDITORONLY_DATA
    PrimaryComponentTick.bTickInEditor = true;  // Enable editor tick
#endif
#endif*/
}

void UPurpleprintCoreManagerComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	WorldCameraLocation = UPurpleprintCoreMisc::GetActiveCameraLocation(this);

}

void UPurpleprintCoreManagerComponent::TickEditorComponent(float DeltaTime)
{
#if !WITH_EDITORONLY_DATA
	return;
#endif

	WorldCameraLocation = UPurpleprintCoreMisc::GetActiveCameraLocation(this);

	if (!GetWorld()->IsPlayInEditor())
	{
		// Enable editor tick
	}
}