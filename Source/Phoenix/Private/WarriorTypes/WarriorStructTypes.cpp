// Jacobus Johannes Jacobs. All rights Reserved


#include "WarriorTypes/WarriorStructTypes.h"
#include "AbillitySystem/Abilities/WarriorGameplayAbility.h"
#include "AbillitySystem/Abilities/WarriorHeroGameplayAbility.h"

bool FWarriorHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}