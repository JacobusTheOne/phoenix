// Jacobus Johannes Jacobs. All rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

class AWarriorWeaponBase;
/**
 * 
 */
UCLASS()
class PHOENIX_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Weapon|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AWarriorWeaponBase* InWeaponToRegister, bool bRegisterAsEquipedWeapon = false);
	
	UFUNCTION(BlueprintCallable, Category = "Weapon|Combat")
	AWarriorWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InGameplayTag) const;

	
	UFUNCTION(BlueprintCallable, Category = "Weapon|Combat")
	AWarriorWeaponBase* GetCharacterCurrentEquippedWeapon() const;
public:
	UPROPERTY(BlueprintReadWrite, Category = "Weapon|Combat")
	FGameplayTag CurrentEquippedWeaponTag;
private:
	TMap<FGameplayTag, AWarriorWeaponBase*> CharacterWeaponCarriedMap;
};
