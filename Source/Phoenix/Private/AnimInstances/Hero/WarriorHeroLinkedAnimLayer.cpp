// Jacobus Johannes Jacobs. All rights Reserved


#include "AnimInstances/Hero/WarriorHeroLinkedAnimLayer.h"
#include "AnimInstances/Hero/WarriorHeroAnimInstance.h"

UWarriorHeroAnimInstance* UWarriorHeroLinkedAnimLayer::GetWarriorHeroAnimInstance() const
{
    return  Cast<UWarriorHeroAnimInstance> (GetOwningComponent()->GetAnimInstance());
}
