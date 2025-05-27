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
PurpleprintCoreCableComponent.h
================================================
*/

#pragma once

#include "CoreMinimal.h"
#include "CableComponent.h"
#include "PurpleprintCoreCableComponent.generated.h"

/**
 * 
 */
UCLASS()
class PURPLEPRINTCORE_API UPurpleprintCoreCableComponent : public UCableComponent
{
	GENERATED_BODY()
	

public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;


protected:

	FVector PreviousWorldLocation;
};
