// Jacobus Johannes Jacobs. All rights Reserved


#include "AbillitySystem/Abilities/WarriorEnemyGameplayAbility.h"
#include "Characters/WarriorEnemyCharacter.h"
#include "Components/Combat/EnemyCombatComponent.h"

AWarriorEnemyCharacter* UWarriorEnemyGameplayAbility::GeEnemyCharacterFromActorInfo() 
{
    if(!CachedEnemyCharacter.IsValid())
    {
       
        CachedEnemyCharacter = Cast<AWarriorEnemyCharacter>(CurrentActorInfo->AvatarActor);
	}
    return CachedEnemyCharacter.IsValid()? CachedEnemyCharacter.Get() : nullptr;
}

UEnemyCombatComponent* UWarriorEnemyGameplayAbility::GetEnemyCombatComponentFromActorInfo()
{
    if (!CachedEnemyCombatComponent.IsValid())
    {
        if (AWarriorEnemyCharacter* EnemyCharacter = GeEnemyCharacterFromActorInfo())
        {
            CachedEnemyCombatComponent = EnemyCharacter->GetEnemyCombatComponent();
		}
    }
    return CachedEnemyCombatComponent.IsValid() ? CachedEnemyCombatComponent.Get() : CachedEnemyCombatComponent.Get();
}
