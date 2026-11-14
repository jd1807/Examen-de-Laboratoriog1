// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaDestructible.generated.h"


UCLASS()
class NAVES_API APlataformaDestructible : public APlataforma
{
	GENERATED_BODY()

public:
	APlataformaDestructible();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;


	virtual void AlChocarConProyectil() override;
	
};
