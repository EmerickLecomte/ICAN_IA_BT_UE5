// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileActor.h"
#include "ICAN_BT_TPCharacter.h"
#include "LifeComponent.h"
#include "Engine/DamageEvents.h"

// Sets default values
AProjectileActor::AProjectileActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
    RootComponent = StaticMesh;
    static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
    check(SphereMeshAsset.Succeeded());

    StaticMesh->SetStaticMesh(SphereMeshAsset.Object);

    StaticMesh->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void AProjectileActor::BeginPlay()
{
    Super::BeginPlay();

    check(StaticMesh != nullptr);
    StaticMesh->OnComponentHit.AddDynamic(this, &AProjectileActor::OnHit);

}

void AProjectileActor::OnHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor != nullptr)
        OtherActor->TakeDamage(1.0f, FDamageEvent(), GetInstigatorController(), GetOwner());

    Destroy();
}

