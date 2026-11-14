// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaDestructible.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"


APlataformaDestructible::APlataformaDestructible()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlataformaMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	// Create mesh component for the projectile sphere
	mallaPlataforma->SetStaticMesh(PlataformaMeshAsset.Object);

	tipoPlataforma = ETipoPlataforma::PLATAFORMA_DESTRUCTIBLE;

	

}
void APlataformaDestructible::BeginPlay()
{
	Super::BeginPlay();

	if (MaterialDinamico)
	{
		// Asigna un color rojo (R, G, B, A)
		MaterialDinamico->SetVectorParameterValue(FName("Color"), FLinearColor::Red);
	}
}

void APlataformaDestructible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void APlataformaDestructible::AlChocarConProyectil()
{
	UE_LOG(LogTemp, Warning, TEXT("Destructible destruida por el proyectil"));
	Destroy();
}