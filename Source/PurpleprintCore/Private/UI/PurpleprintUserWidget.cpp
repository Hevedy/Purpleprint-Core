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
PurpleprintUserWidget.cpp
================================================
*/

#include "UI/PurpleprintUserWidget.h"
#include "Internationalization/Text.h"
#include "SubtitleManager.h"

#define LOCTEXT_NAMESPACE "Game.UI"


UPurpleprintUserWidget::UPurpleprintUserWidget(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

}

void UPurpleprintUserWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UPurpleprintUserWidget::NativeConstruct()
{

	// ISSUES AS USING THE NON NATIVE CONSTRUCT, need to use this one in C++ otherwise don't load
	FSubtitleManager* subtitleManager = FSubtitleManager::GetSubtitleManager();
	if (subtitleManager) 
	{
		subtitleManager->OnSetSubtitleText().AddUObject(this, &UPurpleprintUserWidget::DisplaySubtitles);
	}

	Super::NativeConstruct();
}

void UPurpleprintUserWidget::OnSettingsUpdate() {
	/*
	* Example code to update during settings push update
	UCGameInstance* gi = Cast<UCGameInstance>(GetWorld()->GetGameInstance());
	if (gi) {
		if (gi->GetGameSettings()) {
			//ShakeIntensity = gi->GetGameSettings()->CameraShakeIntensity;
			// Tritanopia, Protanopia, Deuteranopia, Common
			SubtitlesColor = gi->GetGameSettings()->ColorBlindMode == 3 ? FLinearColor::Gray : FLinearColor::White;
			SubtitlesBackgroundColor = gi->GetGameSettings()->ColorBlindMode == 3 ? FLinearColor::Gray : FLinearColor::White;
			// Disabled, Subtitles, Visual Indicators, Subtitles and Visual Indicators
			bSubtitlesEnabled = (gi->GetGameSettings()->VisualHelpers == 1 || gi->GetGameSettings()->VisualHelpers == 3) ? true : false;
			// Small, Default, Big
			SubtitlesSize = gi->GetGameSettings()->UIPreset;
		}
	}
	*/
}

void UPurpleprintUserWidget::DisplaySubtitles(const FText& Text)
{
	bool bVisible = false;
	FSubtitleManager* subtitleManager = FSubtitleManager::GetSubtitleManager();
	if (subtitleManager) 
	{
		if (!subtitleManager->HasSubtitles()) 
		{
			bVisible = false;
		}
		else 
		{
			bVisible = true;
		}
	}
	else 
	{
		bVisible = false;
	}
	if (bVisible) 
	{
		//UE_LOG(LogTemp, Warning, TEXT("UPurpleprintUserWidget::DisplaySubtitles(%s)"), *Text.ToString());
	}
	DisplaySubtitlesWidget(Text, bSubtitlesEnabled ? bVisible : false);
}

void UPurpleprintUserWidget::DisplaySubtitlesWidget_Implementation(const FText& Text, const bool bVisible)
{

}

void UPurpleprintUserWidget::SetSubtitlesInfo(const int32& Size, const FLinearColor& Color, const FLinearColor& BackgroundColor)
{
	SubtitlesSize = Size;
	SubtitlesColor = Color;
	SubtitlesBackgroundColor = BackgroundColor;
}

void UPurpleprintUserWidget::GetSubtitlesInfo(int32& Size, FLinearColor& Color, FLinearColor& BackgroundColor)
{
	Size = SubtitlesSize;
	Color = SubtitlesColor;
	BackgroundColor = SubtitlesBackgroundColor;
}

// Called every frame
void UPurpleprintUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UPurpleprintUserWidget::OnDisplayInGameMenu_Implementation(bool bDisplay) {

}

void UPurpleprintUserWidget::ReturnToMenu_Implementation() 
{

}

void UPurpleprintUserWidget::ReturnToGame_Implementation() 
{

}


#undef LOCTEXT_NAMESPACE