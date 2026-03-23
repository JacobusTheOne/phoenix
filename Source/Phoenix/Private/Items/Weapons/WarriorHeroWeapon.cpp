// Jacobus Johannes Jacobs. All rights Reserved


#include "Items/Weapons/WarriorHeroWeapon.h"

TArray<FGameplayAbilitySpecHandle> AWarriorHeroWeapon::GetGrantedAbilitySpecHandles() const
{
    return GrantedAbilitySpecHandles;
}

void AWarriorHeroWeapon::AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InGrantedAbilitySpecHandles)
{
    GrantedAbilitySpecHandles = InGrantedAbilitySpecHandles;
}
