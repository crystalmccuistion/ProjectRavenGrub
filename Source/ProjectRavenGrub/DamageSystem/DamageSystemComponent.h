// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageSystemTypes.h"
#include "DamageSystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECTRAVENGRUB_API UDamageSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UDamageSystemComponent();
	
	UPROPERTY()
	float MaxHealth = 100.0f;
	
private:
	UPROPERTY()
	float CurrentHealth = MaxHealth;

	UPROPERTY()
	bool IsDead = false;

	UPROPERTY()
	bool IsInvincible = false;

	UPROPERTY()
	bool IsMoreVulnerable = false;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "Damage")
	bool HandleIncomingDamage(const FDamageInfo& DamageInfo);

	UFUNCTION(BlueprintCallable, Category = "Health")
	void HandleIncomingHeal(float HealAmount, AActor* Healer);

	// Getter Functions
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Health")
	float GetCurrentHealth() { return CurrentHealth; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Health")
	float GetMaxHealth() { return MaxHealth; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Health")
	bool GetIsDead() { return IsDead; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "States")
	bool GetIsInvincible() { return IsInvincible; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "States")
	bool GetIsMoreVulnerable() { return IsMoreVulnerable; }

	// Setter Functions

	UFUNCTION(BlueprintCallable, Category = "States")
	void SetIsInvincible(bool NewInvincible) { IsInvincible = NewInvincible; }

	UFUNCTION(BlueprintCallable, Category = "States")
	void SetIsMoreVulnerable(bool NewMoreVulnerable) { IsMoreVulnerable = NewMoreVulnerable; }

	
	
};
