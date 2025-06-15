# Purpleprint - Core
Purpleprint - Core is the main base for the new set of tools for Unreal Engine.  
The assets will be released at FAB and Itch, in combo of the other modules and plugins.

## 📌 Project Details:
Project Name: Purpleprint - Core   
Current Version: 1.0.4.0  
Author: Hevedy <https://github.com/Hevedy>  
Ready to work with Unreal Engine 4.27 & 5.4+  



Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
Unreal® Engine, Copyright 1998 – 2025, Epic Games, Inc. All rights reserved.  

---

## 🔗 External Modules:
🔁 [Purpleprint Bridge][PurpleprintBridge]

---

## 🧱 Core Modules:

### 🛠 Editor Module (Classes & Library):
Camera tracking framework to get from Blueprints and different tools the location of the viewport camera in realtime.   

> - FVector GetEditorActiveCameraLocation()  
>   Get realtime camera location from the viewport in editor.  

> - FRotator GetEditorActiveCameraRotation()  
>   Get realtime camera rotation from the viewport in editor.  

### 🧭 Purpleprint Manager (Component & Actor):
Specific actors with tick enabled in the editor and real-time camera tracking, both in-editor and in-game. These serve as the base for any kind of manager within the engine.  

### 🧾 Purpleprint HUD & Widget (Classes):
Access native engine subtitles and other useful features to serve as a foundation for game development.  

### 🔌 Purpleprint Cable (Component):
A modified cable component that simulates in local space, useful when you need a cable inside a moving actor, such as a car.  

### 🧮 Math Library:
A set of utility functions that are either missing or not exposed in the engine, designed to speed up workflow.  
Examples: ```Log2(float Value), Log10(float Value), CalculateCameraHeightForArea(double DesiredWidthUU, float VerticalFOVDegrees), TransformsCombine(const FTransform& A, const FTransform& B), IntegerCount(const int32 IntValue, const bool Fast), DecimalCount(const float FloatValue)...```  
More: (Documentation)[https://www.hevedy.com/wiki/purpleprint/core/api/purpleprint-core-math.html]

### 🎲 Random Library:
New nodes for generating random points in space with fewer function calls.  
Examples: ```GetRandomIndexByWeight( const TArray<float> Weights), GetRandomIndexByWeightStream(FRandomStream const& Stream, const TArray<float> Weights), RandomVectorBox(FBox Range), RandomFloatRange(FFloatRange Range), GetRandomPointInBoundingBoxStream(FRandomStream const& Stream, const FVector Origin, const FVector BoxExtent)...```  
More: (Documentation)[https://www.hevedy.com/wiki/purpleprint/core/api/purpleprint-core-random.html]

### 🧰 Misc Library:
A collection of utility functions for cloning actors, calculating directions, splitting vectors, and other helpful operations.  
Examples: ```ClampVector2D(FVector2D Value, FVector2D Min, FVector2D Max), GetFloatArrayAlpha(const TArray<float>& Array, const float Alpha), GetActiveCameraLocation(const UObject* WorldContextObject), SpawnActorClone(AActor* Actor, const FTransform& Transform)...```  
More: (Documentation)[https://www.hevedy.com/wiki/purpleprint/core/api/purpleprint-core-misc.html]

### 🖥️ Platform Library:  
Utility functions for retrieving object names, build types, computer specifications, and monitor information.  
Examples: ```IsEditorBuild(), IsShippingBuild(), GetPrimaryMonitorResolution(int32& Width, int32& Height), GetCPUCores()...```
More: (Documentation)[https://www.hevedy.com/wiki/purpleprint/core/api/purpleprint-core-platform.html]

## 🌐 Useful Links:
- [Purpleprint Website][PurpleprintWeb]
- [Purpleprint Documentation][PurpleprintWiki]
- [Purpleprint Birdge][PurpleprintBridge]
- [Hevedy - Website][HevedyWeb]
- [Hevedy - Twitter][HevedyTwitter]
- [Hevedy - Github][HevedyGithub]
- [Hevedy - Purpleprint Kit][PurpleprintKitGithub]
- [Unreal Engine 4 - Website][UE4Website]
- [Unreal Engine 4 - Github][UE4Github]




By Hevedy <https://github.com/Hevedy>.


[PurpleprintWeb]: https://www.hevedy.com/purpleprint/
[PurpleprintWiki]: https://www.hevedy.com/wiki/
[PurpleprintBridge]: https://github.com/Hevedy/Purpleprint-Bridge
[HevedyWeb]: https://www.hevedy.com/
[HevedyTwitter]: https://twitter.com/Hevedy
[HevedyGithub]: https://github.com/Hevedy
[PurpleprintKitGithub]: https://github.com/Hevedy/PurpleprintKit
[UE4Github]: https://github.com/EpicGames/UnrealEngine
[UE4Website]: https://www.unrealengine.com/
[Trello]: https://trello.com/b/vx7Ydo7I/public-projects
