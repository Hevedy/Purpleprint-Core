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
PurpleprintCoreManagerActor.cpp
================================================
*/


#include "Actors/PurpleprintCoreManagerActor.h"
#include "Components/PurpleprintCoreManagerComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PurpleprintCoreMath.h"

#include "Runtime/Core/Public/Logging/MessageLog.h"
#include "Components/BillboardComponent.h"
#include "PurpleprintCoreRandom.h"
#include "Engine/World.h"

#include "DrawDebugHelpers.h"


APurpleprintCoreManagerActor::APurpleprintCoreManagerActor(const class FObjectInitializer& ObjectInitializer) 
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	bAllowTickBeforeBeginPlay = false;

	SceneComp = ObjectInitializer.CreateDefaultSubobject<USceneComponent>(this, TEXT("SceneComp0"));
	SceneComp->SetMobility(EComponentMobility::Type::Static);
	RootComponent = SceneComp;

#if WITH_EDITORONLY_DATA
	IconBB = ObjectInitializer.CreateEditorOnlyDefaultSubobject<UBillboardComponent>(this, TEXT("BillboardIcon0"));
	if (IconBB) // Need double check because play in editor jumps over whatever is WITH_EDITOR or WITH_EDITORONLY_DATA
	{
		IconBB->SetMobility(EComponentMobility::Type::Static);
		IconBB->SetupAttachment(RootComponent);
	}
#endif

	ManagerComp = ObjectInitializer.CreateDefaultSubobject<UPurpleprintCoreManagerComponent>(this, TEXT("ManagerComp0"));
	ManagerComp->SetAutoActivate(true);

	/*
	if (ManagerComp)
	{
		ManagerComp->SetDebug(bDebug);
		ManagerComp->SetTickActorsInGame(bTickActorsInGame);
		ManagerComp->SetTickActorsInEditor(bTickActorsInEditor);
		ManagerComp->SetFixedTickActorsInEditor(bFixedTickActorsInEditor);
		ManagerComp->SetVirtualEditorTickIntervalInEditor(VirtualEditorTickIntervalInEditor);
	}*/
}

void APurpleprintCoreManagerActor::OnConstruction(const FTransform& Transform)
{
	FVector scaled = GetActorScale3D();
	SetActorScale3D(FVector::OneVector);

	//Super::OnConstruction(Transform);
	RegisterAllComponents();

	/*
	if (ManagerComp)
	{
		ManagerComp->SetDebug(bDebug);
		ManagerComp->SetTickActorsInGame(bTickActorsInGame);
		ManagerComp->SetTickActorsInEditor(bTickActorsInEditor);
		ManagerComp->SetFixedTickActorsInEditor(bFixedTickActorsInEditor);
		ManagerComp->SetVirtualEditorTickIntervalInEditor(VirtualEditorTickIntervalInEditor);
	}*/
}

/** Allow actors to initialize themselves on the C++ side after all of their components have been initialized, only called during gameplay */
void APurpleprintCoreManagerActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

#if WITH_EDITORONLY_DATA
void APurpleprintCoreManagerActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	FName propertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

}
#endif // WITH_EDITORONLY_DATA

// Called when the game starts or when spawned
void APurpleprintCoreManagerActor::BeginPlay()
{
	Super::BeginPlay();
}

void APurpleprintCoreManagerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Only in game
	if (GetWorld()->IsGameWorld())
	{

	}
	//TickEditor(DeltaTime);
}

#if WITH_EDITORONLY_DATA
void APurpleprintCoreManagerActor::TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
	Super::TickActor(DeltaTime, TickType, ThisTickFunction);

	// Only when isn't in game
	if (!GetWorld()->IsGameWorld())
	{
		TickEditor(DeltaTime);
	}
}
#endif

void APurpleprintCoreManagerActor::TickEditor(float DeltaTime)
{
#if WITH_EDITORONLY_DATA
	if (!GetWorld()->IsPlayInEditor())
	{
		if (ManagerComp)
		{
			ManagerComp->VirtualTickEditorComponent(DeltaTime);
		}
		// Enable editor tick
	}
#endif
}

APurpleprintCoreManagerActor* APurpleprintCoreManagerActor::FindPurpleprintCoreManager(UObject* WorldContext)
{
#if WITH_EDITORONLY_DATA
	UWorld* world = GEngine->GetWorldFromContextObjectChecked(WorldContext);
#else
	UWorld* world = WorldContext ? WorldContext->GetWorld() : nullptr;
#endif

	if (!world) return nullptr;

	TArray<AActor*> FoundManagers;
	UGameplayStatics::GetAllActorsOfClass(world, APurpleprintCoreManagerActor::StaticClass(), FoundManagers);

	if (FoundManagers.Num() > 0)
	{
		return Cast<APurpleprintCoreManagerActor>(FoundManagers[0]);
	}

	return nullptr;
}