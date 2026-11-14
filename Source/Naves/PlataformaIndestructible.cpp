// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaIndestructible.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"


APlataformaIndestructible::APlataformaIndestructible()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlataformaMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	// Create mesh component for the projectile sphere
	mallaPlataforma->SetStaticMesh(PlataformaMeshAsset.Object);

	tipoPlataforma = ETipoPlataforma::PLATAFORMA_INDESTRUCTIBLE;
}

void APlataformaIndestructible::BeginPlay()
{
	Super::BeginPlay();
	if (MaterialDinamico)
	{
		// Asigna un color azul (R, G, B, A)
		MaterialDinamico->SetVectorParameterValue(FName("Color"), FLinearColor::Blue);
	}
}

void APlataformaIndestructible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void APlataformaIndestructible::AlChocarConNave()
{
	UE_LOG(LogTemp, Warning, TEXT("Indestructible destruida por la nave"));
	Destroy();
}