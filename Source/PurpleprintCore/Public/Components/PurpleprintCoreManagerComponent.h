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
PurpleprintCoreManagerComponent.h
================================================
*/

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/UObjectGlobals.h"
#include "PurpleprintCoreManagerComponent.generated.h"

/**
 * 
 */
UCLASS()
class PURPLEPRINTCORE_API UPurpleprintCoreManagerComponent : public UActorComponent
{
	GENERATED_BODY()
	

public:
	UPurpleprintCoreManagerComponent(const FObjectInitializer& ObjectInitializer);

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	virtual void TickEditorComponent(float DeltaTime);

protected:

	FVector WorldCameraLocation;
};
