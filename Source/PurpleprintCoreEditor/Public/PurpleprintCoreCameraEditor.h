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
PurpleprintCoreCameraEditor.h
================================================
*/

#pragma once

#include "CoreMinimal.h"
#include "TickableEditorObject.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"

// This class don't use UCLASS neither generated headers
class PURPLEPRINTCOREEDITOR_API FPurpleprintCoreCameraEditor : public FTickableEditorObject 
{

private:

protected:

public:
    virtual void Tick(float DeltaTime) override;
    virtual bool IsTickable() const override { return true; }
    virtual TStatId GetStatId() const override 
	{ 
		RETURN_QUICK_DECLARE_CYCLE_STAT(FPurpleprintCoreCameraEditor, STATGROUP_Tickables);
	}

};