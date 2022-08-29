// Fill out your copyright notice in the Description page of Project Settings.


#include "AbstractionPlayerCharacter.h"
#include "Engine/TriggerBox.h"


// Sets default values
AAbstractionPlayerCharacter::AAbstractionPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));

}

// Called when the game starts or when spawned
void AAbstractionPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	PC = GetWorld()->GetFirstPlayerController();

	UE_LOG(LogTemp, Warning, TEXT("Current Health? %f"), GetCurrentHealth());
}

// Called every frame
void AAbstractionPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HealthComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Is Dead? %"), HealthComponent->IsDead());
	}

}

// Called to bind functionality to input
void AAbstractionPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

const bool AAbstractionPlayerCharacter::IsAlive() const
{
	if (HealthComponent)
	{
		return !HealthComponent->IsDead();
	}

	return false;
}

const float AAbstractionPlayerCharacter::GetCurrentHealth() const
{
	if (HealthComponent)
	{
		return HealthComponent->GetCurrentHealth();
	}
	return 0.0f;
}

void AAbstractionPlayerCharacter::SetCurrentHealth(float health)
{
	if (HealthComponent)
	{
		HealthComponent->SetCurrentHealth(health);
	}

	if (HealthComponent->IsDead())
	{
		OnDeath();
	}
}

void AAbstractionPlayerCharacter::SetOnFire(float BaseDamage, float DamageTotalTime, float TakeDamageInterval)
{
	// TODO : Change this to account for Damage Over Time mechanics later
	if (HealthComponent)
	{
		HealthComponent->TakeDamage(BaseDamage);
	}

}

void AAbstractionPlayerCharacter::OnDeath()
{
	APlayerController* PlayerController = GetController<APlayerController>();
	if (PlayerController)
	{
		PlayerController->DisableInput(PlayerController);
	}
}

