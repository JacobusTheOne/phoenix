#pragma once

#include "CoreMinimal.h"


namespace Debug
{
	static void Print(const FString& msg,const FColor& color = FColor::MakeRandomColor(),int32 inKey = -1)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(inKey, 3.f, color, msg);
			UE_LOG(LogTemp, Warning, TEXT("%s"), *msg);
		}
	}
}