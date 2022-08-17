// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"

#include "InteratableDoor.generated.h"

class UDoorInteractionComponent;

UCLASS()
class MAZEGAME_UE4_API AInteratableDoor : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AInteratableDoor();

protected:
	UPROPERTY(EditAnywhere, NoClear)
	UDoorInteractionComponent* DoorInteractionComponent;
};
