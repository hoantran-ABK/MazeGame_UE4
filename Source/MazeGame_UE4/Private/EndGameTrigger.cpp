// Fill out your copyright notice in the Description page of Project Settings.


#include "EndGameTrigger.h"
#include "Engine/TriggerBox.h"


// Sets default values for this component's properties
UEndGameTrigger::UEndGameTrigger()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

}


// Called when the game starts
void UEndGameTrigger::BeginPlay()
{
	Super::BeginPlay();

	// ...
	PC = GetWorld()->GetFirstPlayerController();

}


// Called every frame
void UEndGameTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (EndGameBox && GetWorld() && PC)
	{
		if (PC->GetPawn() && EndGameBox->IsOverlappingActor(PC->GetPawn()))
		{
			
		}
	}

}

