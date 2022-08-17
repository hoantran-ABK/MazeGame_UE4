// Fill out your copyright notice in the Description page of Project Settings.


#include "InteratableDoor.h"
#include "DoorInteractionComponent.h"


AInteratableDoor::AInteratableDoor()
{
	DoorInteractionComponent = CreateDefaultSubobject<UDoorInteractionComponent>(TEXT("DoorInteractionComponent"));
}