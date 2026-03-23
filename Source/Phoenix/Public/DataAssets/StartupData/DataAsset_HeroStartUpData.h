// Jacobus Johannes Jacobs. All rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartupData/DataAsset_StartUpDataBase.h"
#include "WarriorTypes/WarriorStructTypes.h"
#include "DataAsset_HeroStartUpData.generated.h"


/**
 * 
 */
UCLASS()
class PHOENIX_API UDataAsset_HeroStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()
public:
	virtual void GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;
private:
	UPROPERTY(EditDefaultsOnly, Category = "StartupData", meta = (TitleProperty = "InputTag"))
	TArray< FWarriorHeroAbilitySet> HeroStartupAbilitySets;
};
