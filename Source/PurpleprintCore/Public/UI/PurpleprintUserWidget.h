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
UPurpleprintUserWidget.h
================================================
*/

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PurpleprintUserWidget.generated.h"


/**
 * 
 */
UCLASS()
class PURPLEPRINTCORE_API UPurpleprintUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	// Sets default values for this actor's properties
	UPurpleprintUserWidget(const FObjectInitializer& ObjectInitializer);

protected:
	void NativePreConstruct() override;

	void NativeConstruct() override;

	// Called every frame
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UFUNCTION(Category = "Subtitles")
	void DisplaySubtitles(const FText& Text);

	// Need to be ufunction in order to bind, runtime fail
	UFUNCTION()
	void OnSettingsUpdate();

	int32 SubtitlesSize;

	FLinearColor SubtitlesColor;

	FLinearColor SubtitlesBackgroundColor;

	bool bSubtitlesEnabled = true;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Subtitles")
	void DisplaySubtitlesWidget(const FText& Text, const bool bVisible = false);

public:
	UFUNCTION(BlueprintCallable, Category = "Subtitles")
	void SetSubtitlesInfo(const int32& Size, const FLinearColor& Color, const FLinearColor& BackgroundColor);

	UFUNCTION(BlueprintCallable, Category = "Subtitles")
	void GetSubtitlesInfo(int32& Size, FLinearColor& Color, FLinearColor& BackgroundColor);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
	void OnDisplayInGameMenu(bool bDisplay);

	virtual void OnDisplayInGameMenu_Implementation(bool bDisplay);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
	void ReturnToMenu();

	virtual void ReturnToMenu_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
	void ReturnToGame();

	virtual void ReturnToGame_Implementation();

private:

};