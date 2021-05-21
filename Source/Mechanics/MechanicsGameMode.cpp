// Copyright Epic Games, Inc. All Rights Reserved.

#include "MechanicsGameMode.h"
#include "MechanicsHUD.h"
#include "MechanicsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMechanicsGameMode::AMechanicsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	//DefaultPawnClass = PlayerPawnClassFinder.Class;

	//// use our custom HUD class
	//HUDClass = AMechanicsHUD::StaticClass();
	/*GetWorldAsset*/

}
