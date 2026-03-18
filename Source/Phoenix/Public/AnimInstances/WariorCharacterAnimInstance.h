// Jacobus Johannes Jacobs. All rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorBaseAnimInstance.h"
#include "WariorCharacterAnimInstance.generated.h"

class AWarriorBaseCharacter;
class UCharacterMovementComponent;
/**
 * 
 */
UCLASS()
class PHOENIX_API UWariorCharacterAnimInstance : public UWarriorBaseAnimInstance
{
	GENERATED_BODY()
public: 
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
protected:
	UPROPERTY()
	AWarriorBaseCharacter* OwningCharacter;
	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bHasAccelaration;
};
