// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorInteractionSlidingComponent.h"
#include "Engine/TriggerBox.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"

// Sets default values for this component's properties
UDoorInteractionSlidingComponent::UDoorInteractionSlidingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorInteractionSlidingComponent::BeginPlay()
{
	// TODO : Replace all Rotation-related functionality with Position shifting

	Super::BeginPlay();
	//DesiredRotation = FRotator(0.0f, -90.0f, 0.0f);
	StartLocation = GetOwner()->GetActorLocation();
	FinalLocation = GetOwner()->GetActorLocation() + DesiredLocation;
	//GetOwner()->SetActorRotation(DesiredRotation);
	//CurrentRotationTime = 1.0f;
	UE_LOG(LogTemp, Warning, TEXT("FinalLocation: %"), FinalLocation.X);
}


// Called every frame
void UDoorInteractionSlidingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//UE_LOG(LogTemp, Warning, TEXT("TICK...\n"));

	// TODO : Replace all Rotation-related functionality with Position shifting
	if (CurrentSlideTime < TimeToSlide)
	{
		if ((TriggerBox1 || TriggerBox2) && GetWorld() && GetWorld()->GetFirstLocalPlayerFromController())
		{
			APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
			if (PlayerPawn && (TriggerBox1->IsOverlappingActor(PlayerPawn) || TriggerBox2->IsOverlappingActor(PlayerPawn)) )
			{
				//float direction = 1.0f;
				//if (TriggerBox1->IsOverlappingActor(PlayerPawn))
				{
					//direction = 1.0f;
					//FinalLocation = StartLocation + DesiredLocation;
					CurrentSlideTime += DeltaTime;
					//const float RotationAlpha = FMath::Clamp(CurrentRotationTsime / TimeToRotate, 0.0f, 1.0f);
					const float TimeRatio = FMath::Clamp(CurrentSlideTime / TimeToSlide, 0.0f, 1.0f);
					const float TranslationAlpha = OpenCurve.GetRichCurveConst()->Eval(TimeRatio);
					const FVector CurrentRotation = FMath::Lerp(StartLocation, FinalLocation, TranslationAlpha);
					GetOwner()->SetActorLocation(CurrentRotation);
					//UE_LOG(LogTemp, Warning, TEXT("INSIDE Trigger Box 1...\n"));

				}
				//else if (TriggerBox2->IsOverlappingActor(PlayerPawn))
				//{
				//	direction = -1.0f;
				//	FinalLocation = StartLocation - DesiredLocation;
				//	CurrentSlideTime += DeltaTime;
				//	//const float RotationAlpha = FMath::Clamp(CurrentRotationTsime / TimeToRotate, 0.0f, 1.0f);
				//	const float TimeRatio = FMath::Clamp(CurrentSlideTime / TimeToSlide, 0.0f, 1.0f);
				//	const float TranslationAlpha = OpenCurve.GetRichCurveConst()->Eval(TimeRatio);
				//	const FVector CurrentRotation = FMath::Lerp(StartLocation, FinalLocation, TranslationAlpha);
				//	GetOwner()->SetActorLocation(CurrentRotation);
				//	//UE_LOG(LogTemp, Warning, TEXT("INSIDE Trigger Box 2...\n"));

				//}
			}
		}


	}
}

