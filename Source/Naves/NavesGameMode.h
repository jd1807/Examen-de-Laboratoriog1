// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NavesGameMode.generated.h"

class APlataforma;

UCLASS(MinimalAPI)
class ANavesGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANavesGameMode();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	int32 tipoPlataformaActual;

	UPROPERTY()
	TArray<FVector> PuntosSpawn;

	UPROPERTY()
	TArray<APlataforma*> aPlataformas;

	FTimerHandle TimerHandle_SpawnPlataformas;

	void SpawnPlataformasEnPuntos();
};



