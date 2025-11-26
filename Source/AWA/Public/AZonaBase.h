#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ZonaBase.generated.h"

class UBoxComponent;

UCLASS()
class AWA_API AZonaBase : public AActor
{
	GENERATED_BODY()

public:
	AZonaBase();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBoxComponent* Trigger;

	/** Tag que describe el tipo de zona (Daño, Hielo, Veneno, Ralentizar) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Zona")
	FName ZoneTag = "DefaultZone";

protected:
	virtual void BeginPlay() override;

	// Eventos de colisión
	UFUNCTION()
	void OnTriggerBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void OnTriggerEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
