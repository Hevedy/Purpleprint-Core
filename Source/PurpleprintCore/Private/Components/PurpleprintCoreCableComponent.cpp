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
PurpleprintCoreCableComponent.cpp
================================================
*/

#include "Components/PurpleprintCoreCableComponent.h"

void UPurpleprintCoreCableComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	if (!PreviousWorldLocation.IsZero())
	{
		// Fake local transform removing the actual world location from previus frame
		ApplyWorldOffset(GetComponentLocation() - PreviousWorldLocation, false);
	}

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	PreviousWorldLocation = GetComponentLocation();
};