// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageSystemTypes.generated.h"

UENUM(BlueprintType)
enum class EDamageType : uint8
{
	None UMETA(DisplayName = "None"),
	Combatant UMETA(DisplayName = "Combatant"),
	Environmental UMETA(DisplayName = "Environmental"),
	StatusEffect UMETA(DisplayName = "Status Effect"),
};

USTRUCT(BlueprintType)
struct FDamageInfo
{
	GENERATED_BODY();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float DamageAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float PoiseCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	AActor* DamageCauser;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	bool ShouldDamageInvincible = false;
};