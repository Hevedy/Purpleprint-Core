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
PurpleprintCoreManagerInterface.h
================================================
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PurpleprintCoreManagerInterface.generated.h"


class APurpleprintCoreManagerActor;

/**
 * 
 */
UINTERFACE(MinimalAPI, Blueprintable)
class UPurpleprintCoreManagerInterface : public UInterface
{
	GENERATED_BODY()
};

class PURPLEPRINTCORE_API IPurpleprintCoreManagerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = Manager)
	void RegisterToManager();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = Manager)
	void ManagerVirtualTick(float DeltaTime);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = Manager)
	void ManagerVirtualEditorTick(float DeltaTime);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = Manager)
	void ManagerVirtualEditorFixedTick(float DeltaTime);

	virtual class APurpleprintCoreManagerActor* FindManager(UWorld* World) const;
};