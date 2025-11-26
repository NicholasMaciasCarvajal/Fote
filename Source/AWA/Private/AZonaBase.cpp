#include "ZonaBase.h"
#include "Components/BoxComponent.h"
#include "IZonaInterface.h"

AZonaBase::AZonaBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	SetRootComponent(Trigger);

	Trigger->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Trigger->SetCollisionResponseToAllChannels(ECR_Overlap);

	// Enlazar eventos
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AZonaBase::OnTriggerBegin);
	Trigger->OnComponentEndOverlap.AddDynamic(this, &AZonaBase::OnTriggerEnd);
}

void AZonaBase::BeginPlay()
{
	Super::BeginPlay();
}

void AZonaBase::OnTriggerBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->Implements<UZonaInterface>())
	{
		IZonaInterface::Execute_OnEnterZone(OtherActor, true, ZoneTag);
	}
}

void AZonaBase::OnTriggerEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor->Implements<UZonaInterface>())
	{
		IZonaInterface::Execute_OnEnterZone(OtherActor, false, ZoneTag);
	}
}
