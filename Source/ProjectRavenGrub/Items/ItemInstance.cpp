// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemInstance.h"

#include "ItemDefinition.h"
#include "ProjectRavenGrub/Fragments/InventoryItemFragment.h"

float UItemInstance::GetStatValue(FGameplayTag StatTag)
{
	return StatsMap.FindRef(StatTag);
}

void UItemInstance::SetStatValue(FGameplayTag StatTag, float StatValue)
{
	StatsMap.Add(StatTag, StatValue);
}

void UItemInstance::Initialize(TSubclassOf<UItemDefinition> ItemDef)
{
	if (!ItemDef) return;
	
	ItemDefinition = ItemDef;
	
	UItemDefinition* ItemCDO = ItemDefinition.GetDefaultObject();
	
	for (const TObjectPtr<UInventoryItemFragment>& Fragment : ItemCDO->Fragments)
	{
		Fragment->OnInstanceCreated(this);
	}
}

const UInventoryItemFragment* UItemInstance::FindFragmentByClass(
	const TSubclassOf<UInventoryItemFragment> FragmentClass)
{
	if (!FragmentClass) return nullptr;
	
	UItemDefinition* ItemCDO = ItemDefinition.GetDefaultObject();
	return ItemCDO->FindFragmentByClass(ItemDefinition, FragmentClass);
}
