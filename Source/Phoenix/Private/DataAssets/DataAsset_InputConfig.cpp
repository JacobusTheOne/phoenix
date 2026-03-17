// Jacobus Johannes Jacobs. All rights Reserved


#include "DataAssets/DataAsset_InputConfig.h"

UInputAction* UDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InputTag) const
{
    for (const FWarriorInputActionConfig& InputActionConfig : NativeInputActions)
    {
        if (InputActionConfig.InputTag == InputTag && InputActionConfig.InputAction)
        {
            return InputActionConfig.InputAction;
        }
    }
    return nullptr;
}
