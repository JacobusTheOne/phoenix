// Jacobus Johannes Jacobs. All rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbillitySystem/Abilities/WarriorGameplayAbility.h"
#include "WarriorEnemyGameplayAbility.generated.h"

class AWarriorEnemyCharacter;	
class UEnemyCombatComponent;
/**
 * 
 */
UCLASS()
class PHOENIX_API UWarriorEnemyGameplayAbility : public UWarriorGameplayAbility
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AWarriorEnemyCharacter* GeEnemyCharacterFromActorInfo();
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	UEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<AWarriorEnemyCharacter> CachedEnemyCharacter;
	TWeakObjectPtr<UEnemyCombatComponent> CachedEnemyCombatComponent;
};
