// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StatePatternGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class STATEPATTERN_API AStatePatternGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AStatePatternGameModeBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	
};
