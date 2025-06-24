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
PurpleprintCoreManagerActor.h
================================================
*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "PurpleprintCoreMisc.h"
#include "PurpleprintCoreManagerActor.generated.h"


class UBillboardComponent;
class UPurpleprintCoreManagerComponent;

UCLASS(Blueprintable, ClassGroup = "World")
class PURPLEPRINTCORE_API APurpleprintCoreManagerActor : public AActor 
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APurpleprintCoreManagerActor ( const FObjectInitializer& ObjectInitializer );

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* SceneComp;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UBillboardComponent* IconBB;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UPurpleprintCoreManagerComponent* ManagerComp;

#if WITH_EDITORONLY_DATA
	virtual bool ShouldTickIfViewportsOnly() const override { return true; }

	virtual void TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction) override;
#endif
	/**
	 * Called when an instance of this class is placed (in editor) or spawned.
	 * @param	Transform			The transform the actor was constructed at.
	 */
	virtual void OnConstruction(const FTransform& Transform) override;

	/** Allow actors to initialize themselves on the C++ side after all of their components have been initialized, only called during gameplay */
	virtual void PostInitializeComponents() override;

#if WITH_EDITORONLY_DATA
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/*
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
	bool bDebug = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tick")
	bool bTickActorsInGame = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tick")
	bool bTickActorsInEditor = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tick")
	bool bFixedTickActorsInEditor = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tick")
	float VirtualEditorTickIntervalInEditor = 1.0f;*/

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void TickEditor(float DeltaTime);

	virtual UPurpleprintCoreManagerComponent* GetManager() { return ManagerComp; };

	UFUNCTION(BlueprintCallable, Category = "Manager", meta = (WorldContext = "WorldContextObject"))
	static APurpleprintCoreManagerActor* FindPurpleprintCoreManager(UObject* WorldContext);

private:


};