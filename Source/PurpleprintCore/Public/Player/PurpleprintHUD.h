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
PurpleprintHUD.h
================================================
*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PurpleprintHUD.generated.h"

class UPurpleprintUserWidget;
/**
 * 
 */
UCLASS()
class PURPLEPRINTCORE_API APurpleprintHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	APurpleprintHUD(const FObjectInitializer& ObjectInitializer);

protected:
	UPurpleprintUserWidget* Widget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	TSubclassOf<class UUserWidget> WidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	bool bMenuUIOnly = true;

public:
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

	virtual void Reset() override;

	virtual void Destroyed() override;

	UFUNCTION(BlueprintPure, Category = "Widget")
	UPurpleprintUserWidget* GetWidget() { return Widget; };

	UFUNCTION(BlueprintCallable, Category = "Widget")
	void SetControlMode(bool bInGame);

	UFUNCTION(BlueprintCallable, Category = "Interface")
	void DisplayInGameMenu(bool bDisplay, bool bMenuCall = false);
};
