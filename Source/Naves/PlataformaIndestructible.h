// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaIndestructible.generated.h"


UCLASS()
class NAVES_API APlataformaIndestructible : public APlataforma
{
	GENERATED_BODY()

public:
	APlataformaIndestructible();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void AlChocarConNave() override;
	
};
