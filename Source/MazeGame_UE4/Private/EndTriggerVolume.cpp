// Fill out your copyright notice in the Description page of Project Settings.


#include "EndTriggerVolume.h"

AEndTriggerVolume::AEndTriggerVolume()
{
	OnActorBeginOverlap.AddDynamic(this, &AEndTriggerVolume::OnOverlapBegin);
}

void AEndTriggerVolume::BeginPlay()
{
	Super::BeginPlay();
}

void AEndTriggerVolume::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (HasAuthority())
	{
		AAbstractionPlayerCharacter* player = Cast<AAbstractionPlayerCharacter>(OtherActor);
		if (player)
		{
			player->SetCurrentHealth(0.0f);
		}
	}
}
