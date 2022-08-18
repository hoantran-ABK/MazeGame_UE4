// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorInteractionComponent_Locked.h"
#include "Engine/TriggerBox.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Components/SpotLightComponent.h"

// Sets default values for this component's properties
UDoorInteractionComponent_Locked::UDoorInteractionComponent_Locked()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorInteractionComponent_Locked::BeginPlay()
{
	Super::BeginPlay();
	//DesiredRotation = FRotator(0.0f, -90.0f, 0.0f);
	StartRotation = GetOwner()->GetActorRotation();
	FinalRotation = GetOwner()->GetActorRotation() + DesiredRotation;
	//GetOwner()->SetActorRotation(DesiredRotation);
	//CurrentRotationTime = 1.0f;
	OffColor = FLinearColor(0.0f, 0.0f, 0.0f, 0.0f);
}


// Called every frame
void UDoorInteractionComponent_Locked::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//UE_LOG(LogTemp, Warning, TEXT("TICK...\n"));

	if (CurrentRotationTime < TimeToRotate)
	{
		if ((TriggerBox1 && TriggerBox2) && GetWorld() && GetWorld()->GetFirstLocalPlayerFromController())
		{
			APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
			if (PlayerPawn)// && (TriggerBox1->IsOverlappingActor(PlayerPawn) || TriggerBox2->IsOverlappingActor(PlayerPawn)) )
			{
				float direction = 1.0f;
				if (TriggerBox1->IsOverlappingActor(PlayerPawn))
				{
					// TODO : Set a bool to show that Lock1 should be unlocked
					IsLock1Open = true;
					LockLight1->SetLightColor(OffColor);
				}
				else if (TriggerBox2->IsOverlappingActor(PlayerPawn))
				{
					// TODO : Set a bool to show that Lock2 should be unlocked
					IsLock2Open = true;
					LockLight2->SetLightColor(OffColor);
				}
			}

			if (IsLock1Open && IsLock2Open)
			{
				CurrentRotationTime += DeltaTime;
				//const float RotationAlpha = FMath::Clamp(CurrentRotationTsime / TimeToRotate, 0.0f, 1.0f);
				const float TimeRatio = FMath::Clamp(CurrentRotationTime / TimeToRotate, 0.0f, 1.0f);
				const float RotationAlpha = OpenCurve.GetRichCurveConst()->Eval(TimeRatio);
				const FRotator CurrentRotation = FMath::Lerp(StartRotation, FinalRotation, RotationAlpha);
				GetOwner()->SetActorRotation(CurrentRotation);
				//UE_LOG(LogTemp, Warning, TEXT("INSIDE Trigger Box 1...\n"));
			}
		}
	}
}

