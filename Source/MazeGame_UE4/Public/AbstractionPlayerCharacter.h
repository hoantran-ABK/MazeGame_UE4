// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "HealthComponent.h"

#include "AbstractionPlayerCharacter.generated.h"


UCLASS()
class MAZEGAME_UE4_API AAbstractionPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAbstractionPlayerCharacter();


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	const bool IsAlive() const;

	UFUNCTION(BlueprintCallable)
	const float GetCurrentHealth() const;

	UFUNCTION(BlueprintCallable)
	void SetCurrentHealth(float health);

	UFUNCTION(BlueprintCallable)
	void SetOnFire(float BaseDamage, float DamageTotalTime, float TakeDamageInterval);

	UFUNCTION(BlueprintCallable)
	void OnDeath();

	UPROPERTY(EditAnywhere)
	UParticleSystemComponent* ParticleSystemComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	APlayerController* PC;

	UPROPERTY(EditAnywhere)
	UHealthComponent* HealthComponent;


};
