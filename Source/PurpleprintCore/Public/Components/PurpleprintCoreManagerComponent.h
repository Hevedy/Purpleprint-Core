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
UCLASS(Blueprintable, EditInlineNew, hidecategories = (Object, Physics), meta = (BlueprintSpawnableComponent), ClassGroup = Rendering)
class PURPLEPRINTCORE_API UPurpleprintCoreManagerComponent : public UActorComponent
{
	GENERATED_BODY()
	

public:
	UPurpleprintCoreManagerComponent(const FObjectInitializer& ObjectInitializer);

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	virtual void VirtualTickEditorComponent(float DeltaTime);

	virtual void VirtualFixedTickEditorComponent(float DeltaTime);

	//
	// Utility
	//
	UFUNCTION(BlueprintCallable, Category = "Random")
	virtual void SetSeed(int32 Seed);

	UFUNCTION(BlueprintCallable, Category = "Random")
	virtual int32 GetSeed() { return RandomSeed; };

	UFUNCTION(BlueprintCallable, Category = "Random")
	virtual void GenerateRandomSeed();


	virtual void AddToPool(AActor* Actor);

	virtual void RemoveActorFromPool(AActor* Actor);

	UFUNCTION(BlueprintCallable, Category = "Tick")
	void SetDebug(bool Value) { bDebug = Value; };

	UFUNCTION(BlueprintCallable, Category = "Tick")
	void SetTickActorsInGame(bool Value) { bTickActorsInGame = Value; };

	UFUNCTION(BlueprintCallable, Category = "Tick")
	void SetTickActorsInEditor(bool Value) { bTickActorsInEditor = Value; };

	UFUNCTION(BlueprintCallable, Category = "Tick")
	void SetFixedTickActorsInEditor(bool Value) { bFixedTickActorsInEditor = Value; };

	UFUNCTION(BlueprintCallable, Category = "Tick")
	void SetVirtualEditorTickIntervalInEditor(float Value) { VirtualEditorTickIntervalInEditor = Value; };

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Random")
	int32 RandomSeed = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Random")
	FRandomStream RandomStream;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
	bool bDebug = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tick")
	bool bTickActorsInGame = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tick")
	bool bTickActorsInEditor = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tick")
	bool bFixedTickActorsInEditor = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tick")
	float VirtualEditorTickIntervalInEditor = 1.0f;

	float TimeSinceLastEditorTick = 0.0f;

	TArray<AActor*> ActorsPool;
	FVector WorldCameraLocation;
	FRotator WorldCameraRotation;

};
