// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorInteractionComponent.h"
#include "Engine/TriggerBox.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"

// Sets default values for this component's properties
UDoorInteractionComponent::UDoorInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
	//DesiredRotation = FRotator(0.0f, -90.0f, 0.0f);
	StartRotation = GetOwner()->GetActorRotation();
	FinalRotation = GetOwner()->GetActorRotation() + DesiredRotation;
	//GetOwner()->SetActorRotation(DesiredRotation);
	//CurrentRotationTime = 1.0f;
	
}

// TODO : After a DOOR fully opens, CurrentRotationTime == TimeToRotate meaning the door opening logic will not trigger at all anymore, refactor to allow re-updating of door interactions
// Called every frame
void UDoorInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UE_LOG(LogTemp, Warning, TEXT("TICK...\n"));

	if (CurrentRotationTime < TimeToRotate)
	{
		if ((TriggerBox1 || TriggerBox2) && GetWorld() && GetWorld()->GetFirstLocalPlayerFromController())
		{
			APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
			if (PlayerPawn)// && (TriggerBox1->IsOverlappingActor(PlayerPawn) || TriggerBox2->IsOverlappingActor(PlayerPawn)) )
			{
				float direction = 1.0f;
				if (TriggerBox1->IsOverlappingActor(PlayerPawn))
				{
					direction = 1.0f;
					CurrentRotationTime += DeltaTime;
					//const float RotationAlpha = FMath::Clamp(CurrentRotationTsime / TimeToRotate, 0.0f, 1.0f);
					const float TimeRatio = FMath::Clamp(CurrentRotationTime / TimeToRotate, 0.0f, 1.0f);
					const float RotationAlpha = OpenCurve.GetRichCurveConst()->Eval(TimeRatio);
					const FRotator CurrentRotation = FMath::Lerp(StartRotation, FinalRotation * direction, RotationAlpha);
					GetOwner()->SetActorRotation(CurrentRotation);
					UE_LOG(LogTemp, Warning, TEXT("INSIDE Trigger Box 1...\n"));

				}
				else if (TriggerBox2->IsOverlappingActor(PlayerPawn))
				{
					direction = -1.0f;
					CurrentRotationTime += DeltaTime;
					//const float RotationAlpha = FMath::Clamp(CurrentRotationTsime / TimeToRotate, 0.0f, 1.0f);
					const float TimeRatio = FMath::Clamp(CurrentRotationTime / TimeToRotate, 0.0f, 1.0f);
					const float RotationAlpha = OpenCurve.GetRichCurveConst()->Eval(TimeRatio);
					const FRotator CurrentRotation = FMath::Lerp(StartRotation, FinalRotation * direction, RotationAlpha);
					GetOwner()->SetActorRotation(CurrentRotation);
					UE_LOG(LogTemp, Warning, TEXT("INSIDE Trigger Box 2...\n"));

				}
				else if (!TriggerBox1->IsOverlappingActor(PlayerPawn) && !TriggerBox2->IsOverlappingActor(PlayerPawn))
				{
					//CurrentRotationTime += DeltaTime;
					////const float RotationAlpha = FMath::Clamp(CurrentRotationTsime / TimeToRotate, 0.0f, 1.0f);
					//const float TimeRatio = FMath::Clamp(CurrentRotationTime / TimeToRotate, 0.0f, 1.0f);
					//const float RotationAlpha = OpenCurve.GetRichCurveConst()->Eval(TimeRatio);
					//const FRotator CurrentRotation = FMath::Lerp(GetOwner()->GetActorRotation(), StartRotation, RotationAlpha);
					//GetOwner()->SetActorRotation(CurrentRotation);
					UE_LOG(LogTemp, Warning, TEXT("Outside Trigger Boxes...\n"));
				}
				//CurrentRotationTime += DeltaTime;
				////const float RotationAlpha = FMath::Clamp(CurrentRotationTsime / TimeToRotate, 0.0f, 1.0f);
				//const float TimeRatio = FMath::Clamp(CurrentRotationTime / TimeToRotate, 0.0f, 1.0f);
				//const float RotationAlpha = OpenCurve.GetRichCurveConst()->Eval(TimeRatio);
				//const FRotator CurrentRotation = FMath::Lerp(StartRotation, FinalRotation * direction, RotationAlpha * direction);
				//GetOwner()->SetActorRotation(CurrentRotation);
			}
		}

		
	}

}

