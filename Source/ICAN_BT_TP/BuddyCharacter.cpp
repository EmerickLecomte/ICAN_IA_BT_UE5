// Fill out your copyright notice in the Description page of Project Settings.


#include "BuddyCharacter.h"
#include "WeaponComponent.h"
#include "LifeComponent.h"

// Sets default values
ABuddyCharacter::ABuddyCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    WeaponComponent = CreateDefaultSubobject<UWeaponComponent>(TEXT("Weapon"));
    LifeComponent = CreateDefaultSubobject<ULifeComponent>(TEXT("Life"));
}

