// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BuddyCharacter.generated.h"

class UWeaponComponent;
class ULifeComponent;

UCLASS()
class ICAN_BT_TP_API ABuddyCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    ABuddyCharacter();

private:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
        class UWeaponComponent* WeaponComponent;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
        class ULifeComponent* LifeComponent;
};
