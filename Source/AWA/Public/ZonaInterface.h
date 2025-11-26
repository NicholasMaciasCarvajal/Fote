#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ZonaInterface.generated.h"

UINTERFACE(MinimalAPI)
class UZonaInterface : public UInterface
{
	GENERATED_BODY()
};

class AWA_API IZonaInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnEnterZone(bool bIsInZone, FName ZoneTag);
};
