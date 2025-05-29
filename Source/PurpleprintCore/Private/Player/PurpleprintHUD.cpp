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
PurpleprintHUD.cpp
================================================
*/

#include "Player/PurpleprintHUD.h"
#include "UI/PurpleprintUserWidget.h"
#include "GameFramework/PlayerController.h"


APurpleprintHUD::APurpleprintHUD( const FObjectInitializer& ObjectInitializer ) : Super( ObjectInitializer )
{

}

void APurpleprintHUD::BeginPlay()
{

	Widget = CreateWidget<UPurpleprintUserWidget>(GetGameInstance(), WidgetClass, FName("MainWidget0"));
	Widget->AddToViewport();

	SetControlMode(false);

	Super::BeginPlay();
}

void APurpleprintHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void APurpleprintHUD::Reset() {
	Super::Reset();
}

void APurpleprintHUD::Destroyed() {
	Super::Destroyed();
}

void APurpleprintHUD::SetControlMode(bool bInGame) {
	UE_LOG(LogTemp, Log, TEXT("Call %s(%s)"), ANSI_TO_TCHAR(__FUNCTION__), bInGame ? TEXT("True") : TEXT("False"));

	// Menu Only 
	if (!bInGame) 
	{
		if (bMenuUIOnly) 
		{
			// Fix the issue that's taking input even if we are on menus
			// Errors?
			// This mode don't work well, use the mixed one and on the main widget to show set focusable and stop action
			FInputModeUIOnly InputMode;
			InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockInFullscreen);
			if (Widget) 
			{
				if (Widget->bIsFocusable) 
				{
					InputMode.SetWidgetToFocus(Widget->TakeWidget());
				}
			}

			GetOwningPlayerController()->SetInputMode(InputMode);
		} 
		else 
		{
			FInputModeGameAndUI InputMode;
			InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockInFullscreen);
			InputMode.SetHideCursorDuringCapture(bInGame); // If mixed only
			if (Widget) 
			{
				if (Widget->bIsFocusable) 
				{
					InputMode.SetWidgetToFocus(Widget->TakeWidget());
				}
			}

			GetOwningPlayerController()->SetInputMode(InputMode);
		}

	}
	// Game only
	else 
	{
		FInputModeGameOnly InputMode;
		GetOwningPlayerController()->SetInputMode(InputMode);
	}

	GetOwningPlayerController()->SetShowMouseCursor(!bInGame);
	APlayerController* pc = Cast<APlayerController>(GetOwningPlayerController());
	if (pc) 
	{
		//pc->SetInMenu(!bInGame);
	}
}

void APurpleprintHUD::DisplayInGameMenu(bool bDisplay, bool bMenuCall) {
	UE_LOG(LogTemp, Log, TEXT("Call %s(%s)"), ANSI_TO_TCHAR(__FUNCTION__), bDisplay ? TEXT("True") : TEXT("False"));
	SetControlMode(!bDisplay);
	if (bMenuCall) return;
	if (Widget) 
	{
		Widget->OnDisplayInGameMenu(bDisplay);
	}
}