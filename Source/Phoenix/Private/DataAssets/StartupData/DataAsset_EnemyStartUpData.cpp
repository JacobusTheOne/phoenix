// Jacobus Johannes Jacobs. All rights Reserved


#include "DataAssets/StartupData/DataAsset_EnemyStartUpData.h"
#include "AbillitySystem/Abilities/WarriorEnemyGameplayAbility.h"
#include "AbillitySystem/WarriorAbilitySystemComponent.h"

void UDataAsset_EnemyStartUpData::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);
	if (!EnemyCombatAbilities.IsEmpty())
	{
		for (const TSubclassOf<UWarriorEnemyGameplayAbility>& AbilityClass : EnemyCombatAbilities)
		{
			if (!AbilityClass) continue;
			FGameplayAbilitySpec AbilitySpec(AbilityClass);
			AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
			AbilitySpec.Level = ApplyLevel;
			InASCToGive->GiveAbility(AbilitySpec);
		}
	}
}
