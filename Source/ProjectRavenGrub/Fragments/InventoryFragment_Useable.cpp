// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryFragment_Useable.h"

#include "ProjectRavenGrub/ItemActions/ItemAction.h"
#include "ProjectRavenGrub/Items/ItemInstance.h"

bool UInventoryFragment_Useable::Use(AActor* ItemOwner, UItemInstance* ItemInstance)
{
	bool bAnySucceeded = false; 
	
	for (const TObjectPtr<UItemAction>& Action : OnUseActions)
	{
		if (Action && Action->Execute(ItemOwner, ItemInstance))
		{
			bAnySucceeded = true;
		}
	}
	return bAnySucceeded;
}
