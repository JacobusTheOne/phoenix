// Jacobus Johannes Jacobs. All rights Reserved


#include "DataAssets/StartupData/DataAsset_HeroStartUpData.h"
#include "AbillitySystem/Abilities/WarriorGameplayAbility.h"
#include "AbillitySystem/WarriorAbilitySystemComponent.h"

bool FWarriorHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}

void UDataAsset_HeroStartUpData::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	for (const FWarriorHeroAbilitySet& FoundHeroAbility : HeroStartupAbilitySets)
	{
		if (!FoundHeroAbility.IsValid()) continue;
		FGameplayAbilitySpec AbilitySpec(FoundHeroAbility.AbilityToGrant);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(FoundHeroAbility.InputTag);
		InASCToGive->GiveAbility(AbilitySpec);
	}
}
