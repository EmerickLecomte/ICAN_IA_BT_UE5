// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"

class AProjectileActor;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ICAN_BT_TP_API UWeaponComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UWeaponComponent();

    UFUNCTION(BlueprintCallable)
        void Fire();

private:
    void EndCooldown() { IsOnCooldown = false; }

private:
    bool IsOnCooldown = false;

    UPROPERTY(EditAnywhere)
        float ProjectileForce = 5000.0f;

    UPROPERTY(EditAnywhere)
        TSubclassOf<AProjectileActor> CurrentWeapon = nullptr;


};
