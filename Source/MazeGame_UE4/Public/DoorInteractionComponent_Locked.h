// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Curves/CurveFloat.h"
#include "Engine/SpotLight.h"

#include "DoorInteractionComponent_Locked.generated.h"


class ATriggerBox;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAZEGAME_UE4_API UDoorInteractionComponent_Locked : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorInteractionComponent_Locked();


	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		FRotator DesiredRotation = FRotator::ZeroRotator;

	FRotator StartRotation = FRotator::ZeroRotator;
	FRotator FinalRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere)
		float TimeToRotate = 1.0f;

	float CurrentRotationTime = 0.0f;

	UPROPERTY(EditAnywhere)
		ATriggerBox* TriggerBox1;

	UPROPERTY(EditAnywhere)
		ATriggerBox* TriggerBox2;

	UPROPERTY(EditAnywhere)
		FRuntimeFloatCurve OpenCurve;

	bool IsLock1Open = false;
	bool IsLock2Open = false;
	
	ASpotLight* SpotLight1;

	UPROPERTY(EditAnywhere)
		ASpotLight* LockLight1;

		//AActor* LockLight1;
	UPROPERTY(EditAnywhere)
		ASpotLight* LockLight2;

		//AActor* LockLight2;
	FLinearColor OffColor;
};
