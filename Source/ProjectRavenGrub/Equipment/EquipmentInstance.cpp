// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipmentInstance.h"

#include "EquipmentDefinition.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ProjectRavenGrub/Fragments/InventoryFragment_Equippable.h"
#include "ProjectRavenGrub/Items/ItemInstance.h"

void UEquipmentInstance::Initialize(UItemInstance* ItemInstance, ACharacter* Character)
{
	if (!ItemInstance) return;
	
	SourceItemInstance = ItemInstance;
	
	const UInventoryFragment_Equippable* EquippableFragment =  Cast<UInventoryFragment_Equippable>(
		ItemInstance->FindFragmentByClass(UInventoryFragment_Equippable::StaticClass())
		);
	
	if (!EquippableFragment) return;
	
	EquipmentDefinition = EquippableFragment->EquipmentDefinition;
	HandleEquipItem(Character);
}

void UEquipmentInstance::HandleEquipItem(ACharacter* Character)
{
	UEquipmentDefinition* DefinitionCDO = EquipmentDefinition.GetDefaultObject();
	
	if (!DefinitionCDO) return;
	
	SpawnedEquipmentActor = GetWorld()->SpawnActor(DefinitionCDO->EquipmentActorClass);
	
	if (!SpawnedEquipmentActor) return;
	
	SpawnedEquipmentActor->AttachToComponent(Character->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, DefinitionCDO->AttachSocketName);
	
	float WeaponAttackPower = SourceItemInstance-> GetStatValue(FGameplayTag::RequestGameplayTag(FName("Item.Stat.AttackPower")));
}

void UEquipmentInstance::HandleUnequipItem(ACharacter* Character)
{
	if (SpawnedEquipmentActor)
	{
		SpawnedEquipmentActor->Destroy();
		SpawnedEquipmentActor = nullptr;
	}
	
	float WeaponAttackPower = SourceItemInstance-> GetStatValue(FGameplayTag::RequestGameplayTag(FName("Item.Stat.AttackPower")));
	
}
