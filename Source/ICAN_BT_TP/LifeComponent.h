// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LifeComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ICAN_BT_TP_API ULifeComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    ULifeComponent();

    UFUNCTION()
        void OnTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);
protected:
    virtual void BeginPlay();

private:
    UPROPERTY(EditAnywhere)
        int LifePoint = 3;

};
