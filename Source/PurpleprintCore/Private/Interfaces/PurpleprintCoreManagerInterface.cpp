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
PurpleprintCoreManagerInterface.cpp
================================================
*/


#include "Interfaces/PurpleprintCoreManagerInterface.h"
#include "Actors/PurpleprintCoreManagerActor.h"
#include "Kismet/GameplayStatics.h"

APurpleprintCoreManagerActor* IPurpleprintCoreManagerInterface::FindManager(UWorld* World) const
{
	if (!World) return nullptr;

	TArray<AActor*> FoundManagers;
	UGameplayStatics::GetAllActorsOfClass(World, APurpleprintCoreManagerActor::StaticClass(), FoundManagers);

	if (FoundManagers.Num() > 0)
	{
		return Cast<APurpleprintCoreManagerActor>(FoundManagers[0]);
	}

	return nullptr;
}