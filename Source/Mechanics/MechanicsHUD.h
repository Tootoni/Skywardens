// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MechanicsHUD.generated.h"

UCLASS()
class AMechanicsHUD : public AHUD
{
	GENERATED_BODY()

public:
	AMechanicsHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

