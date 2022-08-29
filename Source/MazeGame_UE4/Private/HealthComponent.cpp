// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
	//UE_LOG(LogTemp, Warning, TEXT("Current Health %f"), CurrentHealth);
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::TakeDamage(float Damage)
{
	CurrentHealth -= Damage;
}

bool UHealthComponent::IsDead()
{
	return CurrentHealth <= FLT_EPSILON;
}

const float UHealthComponent::GetCurrentHealth() const
{
	return CurrentHealth;
}

void UHealthComponent::SetCurrentHealth(float Health)
{
	CurrentHealth = Health;
}

