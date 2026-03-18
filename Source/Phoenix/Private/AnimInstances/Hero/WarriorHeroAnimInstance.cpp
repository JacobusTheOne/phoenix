// Jacobus Johannes Jacobs. All rights Reserved


#include "AnimInstances/Hero/WarriorHeroAnimInstance.h"
#include "Characters/WarriorHeroCharacter.h"

void UWarriorHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AWarriorHeroCharacter>(OwningCharacter);
	}
}

void UWarriorHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	if (bHasAccelaration)
	{
		IdleElapsedTime = 0.f;
		bShouldEnterRelaxState = false;
	}
	else {
		IdleElapsedTime += DeltaSeconds;
		if (IdleElapsedTime >= EnterRelaxStateThreshold)
		{
			bShouldEnterRelaxState = true;
		
		}
	}
}
