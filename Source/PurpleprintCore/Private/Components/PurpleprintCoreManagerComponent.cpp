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
#include "Interfaces/PurpleprintCoreManagerInterface.h"

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

	WorldCameraLocation = UPurpleprintCoreMisc::GetActiveCameraLocation(this, WorldCameraRotation);

	if (!bTickActorsInGame) return;

	for (AActor* Actor : ActorsPool)
	{
		if (IsValid(Actor))
		{
			// Call the interface function on the actor
			IPurpleprintCoreManagerInterface::Execute_ManagerVirtualTick(Actor, DeltaTime);
		}
		else
		{
			RemoveActorFromPool(Actor);
		}
	}
}

void UPurpleprintCoreManagerComponent::VirtualTickEditorComponent(float DeltaTime)
{
#if WITH_EDITORONLY_DATA
	WorldCameraLocation = UPurpleprintCoreMisc::GetActiveCameraLocation(this, WorldCameraRotation);

	if (!bTickActorsInEditor) return;

	if (!GetWorld()->IsPlayInEditor())
	{
		// Enable editor tick
		TimeSinceLastEditorTick += DeltaTime;

		if (TimeSinceLastEditorTick >= VirtualEditorTickIntervalInEditor)
		{
			TimeSinceLastEditorTick = 0.0f;
			VirtualFixedTickEditorComponent(DeltaTime);
		}

		for (AActor* Actor : ActorsPool)
		{
			if (IsValid(Actor))
			{
				// Call the interface function on the actor
				IPurpleprintCoreManagerInterface::Execute_ManagerVirtualEditorTick(Actor, DeltaTime);
			}
			else
			{
				RemoveActorFromPool(Actor);
			}
		}
	}
#endif
}

void UPurpleprintCoreManagerComponent::VirtualFixedTickEditorComponent(float DeltaTime)
{
#if WITH_EDITORONLY_DATA
	// Override this function in derived classes to implement custom editor tick logic

	if (!bFixedTickActorsInEditor) return;

	for(AActor* Actor : ActorsPool)
	{
		if (IsValid(Actor))
		{
			// Call the interface function on the actor
			IPurpleprintCoreManagerInterface::Execute_ManagerVirtualEditorFixedTick(Actor, DeltaTime);
		}
		else 
		{
			RemoveActorFromPool(Actor);
		}
	}
#endif
}

void UPurpleprintCoreManagerComponent::AddToPool(AActor* Actor)
{
	if (Actor)
	{
		if (Actor->GetWorld())
		{
			// Check if the actor implements the PurpleprintCoreManagerInterface
			if (Actor->GetClass()->ImplementsInterface(UPurpleprintCoreManagerInterface::StaticClass()))
			{
				ActorsPool.AddUnique(Actor);
			}
		}
	}
}

void UPurpleprintCoreManagerComponent::RemoveActorFromPool(AActor* Actor)
{
	if (Actor)
	{
		if (Actor->GetWorld())
		{
			if( INDEX_NONE != ActorsPool.Find(Actor))
			{
				// Remove the actor from the pool
				ActorsPool.Remove(Actor);
			}
		}
	}
}

//
// Utility
//
void UPurpleprintCoreManagerComponent::GenerateRandomSeed()
{
	int32 rI = FMath::RandRange(0, 99999);
	SetSeed(rI);
}

void UPurpleprintCoreManagerComponent::SetSeed(int32 Seed)
{
	RandomSeed = Seed;
	RandomStream.Initialize(Seed);
}