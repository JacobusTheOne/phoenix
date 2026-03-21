// Jacobus Johannes Jacobs. All rights Reserved

#pragma once

#include "NativeGameplayTags.h"

namespace WarriorGameplayTags
{
	//** Input Tags **//
	PHOENIX_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	PHOENIX_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	PHOENIX_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipAxe);
	PHOENIX_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnequipAxe);

	//** Player Tags **//
	PHOENIX_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);

	PHOENIX_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
	PHOENIX_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Unequip_Axe);
}