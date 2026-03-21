// Jacobus Johannes Jacobs. All rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/DataAsset_InputConfig.h"
#include "WarriorInputComponent.generated.h"


UCLASS()
class PHOENIX_API UWarriorInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
public:
	template<class UserObject, typename CallBackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallBackFunc Func);

	template<class UserObject, typename CallBackFunc>
	void BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject, CallBackFunc InputPressedFunc, CallBackFunc InputReleasedFunc);
};

template<class UserObject, typename CallBackFunc>
inline void UWarriorInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallBackFunc Func)
{
	checkf(InInputConfig, TEXT("InInputConfig is null cannot proceed with binding."));
	if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(FoundAction,TriggerEvent, ContextObject, Func);
	}

}

template<class UserObject, typename CallBackFunc>
inline void UWarriorInputComponent::BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject, CallBackFunc InputPressedFunc, CallBackFunc InputReleasedFunc)
{
	checkf(InInputConfig, TEXT("InInputConfig is null cannot proceed with binding."));
	for (const FWarriorInputActionConfig& FoundInputActionConfig : InInputConfig->AbilityInputActions)
	{
		if (!FoundInputActionConfig.IsValid()) continue;
		BindAction(FoundInputActionConfig.InputAction, ETriggerEvent::Started, ContextObject, InputPressedFunc, FoundInputActionConfig.InputTag);
		BindAction(FoundInputActionConfig.InputAction, ETriggerEvent::Completed, ContextObject, InputReleasedFunc, FoundInputActionConfig.InputTag);
	}
}
