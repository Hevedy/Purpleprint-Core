# Purpleprint - Core
Purpleprint - Core is the main base for the new set of tools for Unreal Engine.  
The assets will be released at FAB and Itch, in combo of the other modules and plugins.

## Information:
Project Name: Purpleprint - Core   
Current Version: 1.0.2.0  
Author: Hevedy <https://github.com/Hevedy>  
Ready to work with Unreal Engine 4.27 & 5.4+  



Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
Unreal® Engine, Copyright 1998 – 2025, Epic Games, Inc. All rights reserved.  



## Core Modules:

### Editor Module (Classes & Library):
Camera tracking framework to get from Blueprints and different tools the location of the viewport camera in realtime.   

> - FVector GetEditorActiveCameraLocation()  
>   Get realtime camera location from the viewport in editor.  

> - FRotator GetEditorActiveCameraRotation()  
>   Get realtime camera rotation from the viewport in editor.  

### Purpleprint Manager (Component & Actor):
Specific actors with tick enabled in the editor and real-time camera tracking, both in-editor and in-game. These serve as the base for any kind of manager within the engine.  

### Purpleprint HUD & Widget (Classes):
Access native engine subtitles and other useful features to serve as a foundation for game development.  

### Purpleprint Cable (Component):
A modified cable component that simulates in local space, useful when you need a cable inside a moving actor, such as a car.  

### Math Library:
A set of utility functions that are either missing or not exposed in the engine, designed to speed up workflow.  

> - float Log2(float Value)  

> - float Log2S(float Value)  
>   Slower than Log2 but more accurate  

> - float Log10(float Value)  

> - double Log10S(float Value)  

> - float Deg2Rad()  

> - float Deg2RadFixed()  

> - float SinD(const float A )  

> - float AsinD(const float A )  

> - float CosD(const float A )  

> - float AcosD(const float A )  

> - float TanD(const float A )  

> - float AtanD(const float A )  

> - float Atan2D(const float A, const float B )  

> - float Log10Fast(const float Value)  

> - float Log10Slow(const float Value)  

> - float Cbrt( const float Value )  
>   Returns cube root  

> - float OneLimit(const float Value)  

> - float OneMinus(const float Value)  

> - int32 NegateInt(const int32 Value)  

> - float Negate(const float Value)  

> - int32 ReverseInt(const int32 Value)  

> - float Reverse(const float Value)  

> - double CalculateCameraHeightForArea(double DesiredWidthUU, float VerticalFOVDegrees)  

> - float CalculateCameraHeightForAreaFloat(float DesiredWidthUU, float VerticalFOVDegrees)  

> - FTransform TransformsAddMasked(const FTransform& A, const FTransform& B, bool bLocation = true, bool bRotation = true, bool bScale = false, bool bReturnFirst = true)  

> - FTransform TransformsSubMasked(const FTransform& A, const FTransform& B, bool bLocation = true, bool bRotation = true, bool bScale = false, bool bReturnFirst = true)  

> - FTransform TransformsMulMasked(const FTransform& A, const FTransform& B, bool bLocation = true, bool bRotation = true, bool bScale = false, bool bbReturnFirst = true)  

> - FTransform TransformsCombine(const FTransform& A, const FTransform& B)  

> - FVector GetClosestPointOnSphereSurface(const FVector& SphereCenter, float SphereRadius, const FVector& TargetPoint)  

> - FVector GetClosestPointOnDomeSurface(const FVector& DomeCenter, float DomeRadius, const FVector& TargetPoint)  

> - float SpringFloat(float Current, float Target, float& Velocity, float Frequency, float Damping, float DeltaTime)  

> - bool FLinearColorNearEqual(const FLinearColor A, const FLinearColor B, const bool bIgnoreAlpha = true)  

> - float BoxPerimeter(const float SizeX, const float SizeY)  

> - float BoxDiagonal(const float SizeX, const float SizeY)  

> - float BoxSide(const float Diagonal)  

> - float VectorDistance(const FVector A, const FVector B)  

> - float Distance2D(const FVector2D A, const FVector2D B)  

> - float GetVectorsAngleRadiants(FVector A, FVector B)  

> - float GetVectorsAngleDegrees(FVector A, FVector B)  

> - FVector GetPointOnLineAtDistance(FVector Start, FVector End, float Distance)  

> - float LerpLinearBounce(float Alpha)  

> - float LerpLinearBounceAuto(float& Alpha, float Delta, float DeltaSpeed = 1.0f)  

> - int32 NormalizeInRangeRoulette(const int32 Value, const int32 Min, const int32 Max)  
>   Returns the float in range of min and max can cross up or down 

> - int32 IntegerCount(const int32 IntValue, const bool Fast = true)  
>   Returns the number of characters in the int

> - int32 FloatCount(const float FloatValue, const bool Fast = true)  
>   Returns the number of characters in the float

> - int32 DecimalCount(const float FloatValue)  
>   Returns the number decimals in the float


### Random Library:
New nodes for generating random points in space with fewer function calls.  

> - int32 GetRandomIndexByWeight( const TArray<float> Weights)  

> - int32 GetRandomIndexByWeightStream(FRandomStream const& Stream, const TArray<float> Weights)  

> - FVector RandomVector(FVector Min, FVector Max)  

> - FVector RandomVectorStream(FRandomStream const& Stream, FVector Min, FVector Max)  

> - FVector RandomVectorBox(FBox Range)  

> - FVector RandomVectorBoxStream(FRandomStream const& Stream, FBox Range)  

> - FRotator RandomRotatorBox(FBox Range)  

> - FRotator RandomRotatorBoxStream(FRandomStream const& Stream, FBox Range)  

> - int32 RandomRange(FInt32Range Range)  

> - int32 RandomRangeStream(FRandomStream const& Stream, FInt32Range Range)  

> - float RandomFloatRange(FFloatRange Range)  

> - float RandomFloatRangeStream(FRandomStream const& Stream, FFloatRange Range)  

> - FVector2D GetRandomPointInCircle(const float Radius = 100.f, const float InnerRadius = 0.0f)  

> - FVector2D GetRandomPointInCircleStream(FRandomStream const& Stream, const float Radius = 100.f, const float InnerRadius = 0.0f)  

> - FVector GetRandomPointInSphere(const float Radius = 100.f, const bool bAlt = false, const FVector Location = FVector::ZeroVector)  

> - FVector GetRandomPointInSphereStream(FRandomStream const& Stream, const float Radius = 100.f, const bool bAlt = false, const FVector Location = FVector::ZeroVector)  

> - FVector GetRandomPointInBoundingBoxStream(FRandomStream const& Stream, const FVector Origin, const FVector BoxExtent)  


### Misc Library:
A collection of utility functions for cloning actors, calculating directions, splitting vectors, and other helpful operations.  

> - EPurpleCoreAxis PurpleCoreAlignAxisToAxis(EPurpleCoreAlignAxis Align)  

> - EPurpleCoreAlignAxis PurpleCoreAxisToAlignAxis(EPurpleCoreAxis Axis)  

> - FVector GetAxisVectorFromTransform(const FTransform& Transform, EPurpleCoreAxis Align)  

> - FVector GetAlignVectorFromTransform(const FTransform& Transform, EPurpleCoreAlignAxis Align)  

> - FVector2D FloatSplitToVector2D( const float FloatValue )  
>   Returns FVector2D(A,B) from a float A.B

> - FVector FloatSplitToVector( const float FloatValue )  
>   Returns FVector(A,B,0) from a float A.B

> - FVector4 FloatSplitToVector4( const float FloatValue )  
>   Returns FVector4(A,B,0,0) from a float A.B

> - FVector2D ClampVector2D(FVector2D Value, FVector2D Min, FVector2D Max)  

> - FVector ClampVector(FVector Value, FVector Min, FVector Max)  

> - FVector4 ClampVector4(FVector4 Value, FVector4 Min, FVector4 Max)  

> - FVector2D VectorToVector2D( const FVector &VecValue )  
>   Returns FVector2D(A,B) from the FVector(A,B,C)

> - FVector2D Vector4ToVector2D( const FVector4 &Vec4Value )  
>   Returns FVector2D(A,B) from the FVector4(A,B,C,D)

> - FVector VectorIntToVector( const FIntVector &VecIntValue )  
>   Returns FVector(A,B,0) from the FVector2D(A,B)

> - FVector Vector2DToVector( const FVector2D &Vec2Value )  
>   Returns FVector(A,B,0) from the FVector2D(A,B)

> - FVector Vector4ToVector( const FVector4 &Vec4Value )  
>   Returns FVector(A,B,C) from the FVector4(A,B,C,D)

> - FIntVector VectorToVectorInt( const FVector &VecValue )  
>   Returns FVector(A,B,0) from the FVector2D(A,B)

> - FVector4 Vector2DToVector4( const FVector2D &Vec2Value )  
>   Returns FVector4(A,B,0,0) from the FVector2D(A,B)

> - FVector4 VectorToVector4( const FVector &VecValue )  
>   Returns FVector4(A,B,C,0) from the FVector(A,B,C)

> - FRotator RotatorOrderInvert( const FRotator &RotValue )  
>   Returns FRotator(C,B,A) from the FRotator(A,B,C)

> - FVector2D Vector2DOrderInvert( const FVector2D &Vec2Value )  
>   Returns FVector2D(B,A) from the FVector2D(A,B)

> - FVector VectorOrderInvert( const FVector &VecValue )  
>   Returns FVector(C,B,A) from the FVector(A,B,C)

> - FVector4 Vector4OrderInvert( const FVector4 &Vec4Value )  
>   Returns FVector4(D,C,B,A) from the FVector4(A,B,C,D)

> - FRotator RotatorOrderRight( const FRotator &RotValue )  
>   Returns FRotator(C,A,B) from the FRotator(A,B,C)

> - FVector VectorOrderRight( const FVector &VecValue )  
>   Returns FVector(C,A,B) from the FVector(A,B,C)

> - FVector4 Vector4OrderRight( const FVector4 &Vec4Value )  
>   Returns FVector(D,A,B,C) from the FVector(A,B,C) 

> - FRotator RotatorOrderLeft( const FRotator &RotValue )  
>   Returns FRotator(B,C,A) from the FRotator(A,B,C)

> - FVector VectorOrderLeft( const FVector &VecValue )  
>   Returns FVector(B,C,A) from the FVector(A,B,C)

> - FVector4 Vector4OrderLeft( const FVector4 &Vec4Value )  
>   Returns FVector(B,C,D,A) from the FVector(A,B,C,D)

> - uint8 GetByteArrayAlpha(const TArray<uint8>& Array, const float Alpha)  
>   Given an Alpha value get the aprox value in the array

> - int32 GetIntegerArrayAlpha(const TArray<int32>& Array, const float Alpha)  
>   Given an Alpha value get the aprox value in the array

> - float GetFloatArrayAlpha(const TArray<float>& Array, const float Alpha)  
>   Given an Alpha value get the aprox value in the array

> - FVector2D GetVector2DArrayAlpha(const TArray<FVector2D>& Array, const float Alpha)  
>   Given an Alpha value get the aprox value in the array

> - FVector GetVectorArrayAlpha(const TArray<FVector>& Array, const float Alpha)  
>   Given an Alpha value get the aprox value in the array

> - FRotator GetRotatorArrayAlpha(const TArray<FRotator>& Array, const float Alpha)  
>   Given an Alpha value get the aprox value in the array

> - FTransform GetTransformArrayAlpha(const TArray<FTransform>& Array, const float Alpha)  
>   Given an Alpha value get the aprox value in the array

> - FTransform GetTransformArrayAlphaLerp(const TArray<FTransform>& Array, const float Alpha, const bool bLoop = false)  
>   Given an Alpha value get the aprox value in the array

> - FVector GetActiveCameraLocation(const UObject* WorldContextObject)  

> - AActor* SpawnActorClone(AActor* Actor, const FTransform& Transform)  

> - void CopySceneComponentParams(USceneComponent* Source, USceneComponent* Target)  

> - void CopyPrimitiveComponentParams(UPrimitiveComponent* Source, UPrimitiveComponent* Target, bool bCopyMaterials = true)  
	
> - void CopyStaticMeshComponentParams(UStaticMeshComponent* Source, UStaticMeshComponent* Target)  

> - void CopyDecalComponentParams(UDecalComponent* Source, UDecalComponent* Target)  

> - void CopyNiagaraComponentParams(UNiagaraComponent* Source, UNiagaraComponent* Target)  

> - void CopyParticleComponentParams(UParticleSystemComponent* Source, UParticleSystemComponent* Target)  

> - bool IsValidCollisionProfileName(FName ProfileName)  

> - TArray<FName> GetAllCollisionProfileNames()  

> - bool SetPrimitiveComponentMaterials(UPrimitiveComponent* Component, TArray<UMaterialInterface*> Materials)  

> - bool SetActorStaticMeshMaterials(AStaticMeshActor* Actor, TArray<UMaterialInterface*> Materials)  

### Platform Library:  
Utility functions for retrieving object names, build types, computer specifications, and monitor information.  

> - static FString GetObjectFullName(UObject* Object)

> - static FString GetSoftObjectName(TSoftObjectPtr<UObject> InObject)

> - static FName GetPersistentLevelName(class UObject* WorldContextObject)

> - static FName GetStreamLevelNameFromActor(AActor* Actor)

> - static FName GetStreamLevelNameFromReference(const TSoftObjectPtr<UWorld> World)

> - static FName GetCorrectAssetName(const FString String)

> - static bool IsEditorBuild()

> - static bool IsDebugBuild()

> - static bool IsDevelopmentBuild()

> - static bool IsShippingBuild()

> - static void GetPrimaryMonitorResolution(int32& Width, int32& Height)  
>   Returns the primary monitor resolution.

> - static TArray<FPurpleDisplayInfo> GetMonitorsInfo()

> - static int32 GetMonitorsNum()

> - static FPurpleDisplayInfo GetPrimaryMonitorInfo()

> - static int32 GetPrimaryMonitorIndex()

> - static FString GetPrimaryMonitorName()

> - static bool IsIndexPrimaryMonitor(const int32 Index)

> - static FPurpleDisplayInfo GetMonitorInfoByIndex(const int32 Index)

> - static FString GetMonitorName(const int32 Index)

> - static bool GetSupportedFullscreenResolutionsByIndex(TArray<FIntPoint>& Resolutions, const int32 Index)
>   FIntPoint not exposed to Blueprints sadly

> - static int32 DateTimeToUnixTimeStamp(const FDateTime& DateTime)

> - static int64 DateTimeToUnixTimeStamp64(const FDateTime& DateTime)

> - static FString GetCPUBrandName()

> - static FString GetCPUVendorName()

> - static int32 GetCPUCores()

> - static FString GetGPUBrandName()

> - static FString GetGPUDriverInfo()

> - static FString GetOSVersion()

> - static FString GetNetRoleString(const ENetRole Role)

> - static FString GetNetModeString(const ENetMode Mode)  
>   Undefined for Blueprints so cannot be exposed

## Websites:
- [Purpleprint Website][PurpleprintWeb]
- [Purpleprint Documentation][PurpleprintWiki]
- [Hevedy - Website][HevedyWeb]
- [Hevedy - Twitter][HevedyTwitter]
- [Hevedy - Github][HevedyGithub]
- [Hevedy - Purpleprint Kit][PurpleprintKitGithub]
- [Unreal Engine 4 - Purpleprint Kit Post][UE4PostPK]
- [Unreal Engine 4 - Website][UE4Website]
- [Unreal Engine 4 - Github][UE4Github]




By Hevedy <https://github.com/Hevedy>.


[PurpleprintWeb]: https://www.hevedy.com/purpleprint/
[PurpleprintWiki]: https://www.hevedy.com/wiki/
[HevedyWeb]: https://www.hevedy.com/
[HevedyTwitter]: https://twitter.com/Hevedy
[HevedyGithub]: https://github.com/Hevedy
[PurpleprintKitGithub]: https://github.com/Hevedy/PurpleprintKit
[UE4Github]: https://github.com/EpicGames/UnrealEngine
[UE4Website]: https://www.unrealengine.com/
[Trello]: https://trello.com/b/vx7Ydo7I/public-projects
