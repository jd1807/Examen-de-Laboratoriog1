// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavesGameMode.h"
#include "NavesPawn.h"
#include "Plataforma.h"
#include "PlataformaDestructible.h"
#include "PlataformaIndestructible.h"


ANavesGameMode::ANavesGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = ANavesPawn::StaticClass();

	DefaultPawnClass = ANavesGameMode::StaticClass();
	tipoPlataformaActual = 0;

	// Los 3 puntos fijos (X y Z constantes, Y var¨ªa)
	PuntosSpawn.Add(FVector(780.0f, -1300.0f, 214.0f));
	PuntosSpawn.Add(FVector(780.0f, 0.0f, 214.0f));
	PuntosSpawn.Add(FVector(780.0f, 1300.0f, 214.0f));
}

void ANavesGameMode::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	if (World == nullptr)
	{
		return;
	}

	// Primera tanda inmediata
	SpawnPlataformasEnPuntos();

	// Repite cada 5 segundos
	GetWorldTimerManager().SetTimer(TimerHandle_SpawnPlataformas, this, &ANavesGameMode::SpawnPlataformasEnPuntos, 5.0f, true);

}

void ANavesGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ANavesGameMode::SpawnPlataformasEnPuntos()
{
	UWorld* World = GetWorld();
	if (World == nullptr)
	{
		return;
	}

	FRotator Rotacion = FRotator::ZeroRotator;
	APlataforma* plataformaActual = nullptr;
	int32 tipoPlataformaRandom;

	for (const FVector& Punto : PuntosSpawn)
	{
		// 0 = Destructible, 1 = Indestructible
		tipoPlataformaRandom = FMath::RandRange(0, 1);

		switch (tipoPlataformaRandom)
		{
		case 0:
			plataformaActual = World->SpawnActor<APlataformaDestructible>(Punto, Rotacion);
			break;
		case 1:
			plataformaActual = World->SpawnActor<APlataformaIndestructible>(Punto, Rotacion);
			break;
		default:
			break;
		}

		if (plataformaActual != nullptr)
		{
			aPlataformas.Add(plataformaActual);
		}
	}
}
