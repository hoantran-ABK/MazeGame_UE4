// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Curves/CurveFloat.h"

#include "DoorInteractionSlidingComponent.generated.h"

class ATriggerBox;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAZEGAME_UE4_API UDoorInteractionSlidingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorInteractionSlidingComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	FVector DesiredLocation = FVector::ZeroVector;

	FVector StartLocation = FVector::ZeroVector;
	FVector FinalLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere)
	float TimeToSlide = 1.0f;

	float CurrentSlideTime = 0.0f;

	UPROPERTY(EditAnywhere)
	ATriggerBox* TriggerBox1;

	UPROPERTY(EditAnywhere)
	ATriggerBox* TriggerBox2;

	UPROPERTY(EditAnywhere)
	FRuntimeFloatCurve OpenCurve;
};
