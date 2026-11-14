// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Plataforma.generated.h"

class UStaticMeshComponent;

enum class ETipoPlataforma
{
	PLATAFORMA_INDESTRUCTIBLE,
	PLATAFORMA_DESTRUCTIBLE
};

UCLASS()
class NAVES_API APlataforma : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlataforma();

	
	ETipoPlataforma tipoPlataforma;

	UPROPERTY()
	class UMaterialInstanceDynamic* MaterialDinamico;

	UPROPERTY()
	UStaticMeshComponent* mallaPlataforma;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Colision")
	class UBoxComponent* CajaColision;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Velocidad a la que baja en el eje X
	UPROPERTY(EditAnywhere, Category = "Movimiento")
	float VelocidadCaida = 200.0f;

	
	

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	// Hooks que las hijas sobreescriben. Por defecto no hacen nada.
protected: 
	virtual void AlChocarConNave();
	virtual void AlChocarConProyectil();

	
};
