// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileActor.generated.h"

UCLASS()
class ICAN_BT_TP_API AProjectileActor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AProjectileActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

private:
    UFUNCTION()
        void OnHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

private:
    UPROPERTY(EditAnywhere);
    UStaticMeshComponent* StaticMesh;
};
