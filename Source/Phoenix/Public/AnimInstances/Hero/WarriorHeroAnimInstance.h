// Jacobus Johannes Jacobs. All rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WariorCharacterAnimInstance.h"
#include "WarriorHeroAnimInstance.generated.h"

class AWarriorHeroCharacter;
/**
 * 
 */
UCLASS()
class PHOENIX_API UWarriorHeroAnimInstance : public UWariorCharacterAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|References")
	AWarriorHeroCharacter* OwningHeroCharacter;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bShouldEnterRelaxState;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float EnterRelaxStateThreshold = 5.f;

	float IdleElapsedTime;
};
