// Fill out your copyright notice in the Description page of Project Settings.


#include "Plataforma.h"
#include "NavesPawn.h"
#include "NavesProjectile.h"
#include "Components/BoxComponent.h"


// Sets default values
APlataforma::APlataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlataformaMeshAsset(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));

	mallaPlataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaNave"));
	mallaPlataforma->SetStaticMesh(PlataformaMeshAsset.Object);
	RootComponent = mallaPlataforma;
	
	CajaColision = CreateDefaultSubobject<UBoxComponent>(TEXT("CajaColision"));
	CajaColision->SetupAttachment(RootComponent); // asumiendo que RootComponent sigue siendo mallaPlataforma
	CajaColision->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f)); // ajusta al tamaño real de tu cubo

	// Configuración de colisión: esto es lo que faltaba
	CajaColision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CajaColision->SetCollisionObjectType(ECC_WorldStatic); // o un canal custom si tienes uno para "Plataforma"
	CajaColision->SetCollisionResponseToAllChannels(ECR_Block); // bloquea todo por defecto
	CajaColision->SetNotifyRigidBodyCollision(true); // esto es lo que genera el evento Hit

	// El bind ahora va en la CAJA, no en mallaPlataforma
	CajaColision->OnComponentHit.AddDynamic(this, &APlataforma::OnHit);
	
}

// Called when the game starts or when spawned
void APlataforma::BeginPlay()
{
	Super::BeginPlay();
	if (mallaPlataforma && mallaPlataforma->GetMaterial(0))
	{
		MaterialDinamico = mallaPlataforma->CreateAndSetMaterialInstanceDynamic(0);
	}

	
	
}

// Called every frame
void APlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FHitResult HitResult;
	AddActorWorldOffset(FVector(-VelocidadCaida * DeltaTime, 0.0f, 0.0f), true, &HitResult);

	
}

void APlataforma::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("%s chocó con %s"), *GetName(), OtherActor ? *OtherActor->GetName() : TEXT("NULL"));

	if (OtherActor == nullptr || OtherActor == this)
	{
		return;
	}
	

	if (OtherActor->IsA(ANavesPawn::StaticClass()))
	{
		AlChocarConNave();
	}
	else if (OtherActor->IsA(ANavesProjectile::StaticClass()))
	{
		AlChocarConProyectil();
	}
}
void APlataforma::AlChocarConNave() 
{
	//si la plataforma indestructible choca con plataforma se destruye
}
void APlataforma::AlChocarConProyectil()
{
// si la plataforma destructible choca con la pelota se destruye 
}
