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
PurpleprintCore.cpp
================================================
*/

#include "PurpleprintCore.h"
#include "CoreMinimal.h"
#include "HAL/PlatformProcess.h"

class FPurpleprintCore : public IPurpleprintCore 
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FPurpleprintCore, PurpleprintCore )



void FPurpleprintCore::StartupModule() 
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
}


void FPurpleprintCore::ShutdownModule() 
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}
