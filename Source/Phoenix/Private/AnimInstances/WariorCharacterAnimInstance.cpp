// Jacobus Johannes Jacobs. All rights Reserved


#include "AnimInstances/WariorCharacterAnimInstance.h"
#include "Characters/WarriorBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UWariorCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<AWarriorBaseCharacter>(TryGetPawnOwner());
	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UWariorCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !OwningMovementComponent)
	{
		return;
	}
	GroundSpeed = OwningCharacter->GetVelocity().Size2D();

	bHasAccelaration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
}
