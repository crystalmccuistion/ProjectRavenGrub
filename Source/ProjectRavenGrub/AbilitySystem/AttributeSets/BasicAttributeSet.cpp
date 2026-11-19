// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicAttributeSet.h"
#include "GameplayEffectExtension.h"

UBasicAttributeSet::UBasicAttributeSet()
{
	AscHealth = 100.0f;
	AscMaxHealth = 100.0f;
	
	AscStamina = 100.0f;
	AscMaxStamina = 100.0f;
	
	AscPoise = 100.0f;
	AscMaxPoise = 100.0f;
}

void UBasicAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	
	if (Attribute == GetAscHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetAscMaxHealth());
	} else if (Attribute == GetAscStaminaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, -100.0f, GetAscMaxStamina());
	} else if (Attribute == GetAscPoiseAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetAscMaxPoise());
	}
}

void UBasicAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	
	if (Data.EvaluatedData.Attribute == GetAscHealthAttribute())
	{
		SetAscHealth(GetAscHealth());
	}
	else if (Data.EvaluatedData.Attribute == GetAscStaminaAttribute())
	{
		SetAscStamina(GetAscStamina());
	}
	else if (Data.EvaluatedData.Attribute == GetAscPoiseAttribute())
	{
		SetAscPoise(GetAscPoise());
		if (GetAscPoise() == 0.0f)
		{
			FGameplayTagContainer HitReactTagContainer; 
			HitReactTagContainer.AddTag(FGameplayTag::RequestGameplayTag("Ability.Animation.HitReaction"));
			GetOwningAbilitySystemComponent()->TryActivateAbilitiesByTag(HitReactTagContainer);
			SetAscPoise(GetAscMaxPoise());
		}

	}
}

void UBasicAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);
	
	if (Attribute == GetAscHealthAttribute() && NewValue <= 0.f)
	{
		FGameplayTagContainer DeathTagContainer; 
		DeathTagContainer.AddTag(FGameplayTag::RequestGameplayTag("Ability.Death"));
		GetOwningAbilitySystemComponent()->TryActivateAbilitiesByTag(DeathTagContainer);
	}
}