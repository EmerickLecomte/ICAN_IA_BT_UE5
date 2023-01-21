// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponComponent.h"
#include <Engine/World.h>
#include <Components/ActorComponent.h>
#include "ProjectileActor.h"

// Sets default values for this component's properties
UWeaponComponent::UWeaponComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = false;

    // ...
}


void UWeaponComponent::Fire()
{
    check(CurrentWeapon != nullptr);
    if (IsOnCooldown)
        return;

    const AActor* owner = GetOwner();
    check(owner != nullptr);

    const FVector spawnPoint = owner->GetActorLocation() + owner->GetActorForwardVector() * 100.0f;

    AProjectileActor* projectile = GetWorld()->SpawnActor<AProjectileActor>(CurrentWeapon, spawnPoint, owner->GetActorRotation());
    check(projectile != nullptr);

    UPrimitiveComponent* primitiveComponent = Cast<UPrimitiveComponent>(projectile->GetComponentByClass(UPrimitiveComponent::StaticClass()));
    check(primitiveComponent != nullptr);

    primitiveComponent->AddImpulse(projectile->GetActorForwardVector() * ProjectileForce, NAME_None, true);

    IsOnCooldown = true;

    FTimerHandle stopIgnoreBallTimeHandler;
    owner->GetWorldTimerManager().SetTimer(stopIgnoreBallTimeHandler, this, &UWeaponComponent::EndCooldown, 1.5f, false);
}

