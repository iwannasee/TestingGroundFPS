// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TestingGroundFPSGameMode.h"
#include "TestingGroundFPSHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestingGroundFPSGameMode::ATestingGroundFPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATestingGroundFPSHUD::StaticClass();
}
