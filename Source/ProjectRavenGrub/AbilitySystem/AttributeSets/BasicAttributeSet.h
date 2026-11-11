// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "BasicAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTRAVENGRUB_API UBasicAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public: 
	
	UBasicAttributeSet();
	
	// Health Attributes
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData AscHealth;
	ATTRIBUTE_ACCESSORS_BASIC(UBasicAttributeSet, AscHealth)
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData AscMaxHealth;
	ATTRIBUTE_ACCESSORS_BASIC(UBasicAttributeSet, AscMaxHealth)
	
	// Stamina Attributes
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData AscStamina;
	ATTRIBUTE_ACCESSORS_BASIC(UBasicAttributeSet, AscStamina)
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData AscMaxStamina;
	ATTRIBUTE_ACCESSORS_BASIC(UBasicAttributeSet, AscMaxStamina)
	
	// Poise Attributes
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData AscPoise;
	ATTRIBUTE_ACCESSORS_BASIC(UBasicAttributeSet, AscPoise)
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData AscMaxPoise;
	ATTRIBUTE_ACCESSORS_BASIC(UBasicAttributeSet, AscMaxPoise)
	
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
};
