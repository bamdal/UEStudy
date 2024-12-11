// Fill out your copyright notice in the Description page of Project Settings.


#include "JMS_CollisionComponent.h"

#include "Kismet/KismetSystemLibrary.h"


// Sets default values for this component's properties
UJMS_CollisionComponent::UJMS_CollisionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	
}


// Called when the game starts
void UJMS_CollisionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UJMS_CollisionComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	OnHit.Unbind();
}


// Called every frame
void UJMS_CollisionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(IsCollisionEnabled)
	{
		CollisionTrace();
	}
}


void UJMS_CollisionComponent::EnableCollision_Implementation()
{
	ClearHitActors();
	IsCollisionEnabled = true;
}

void UJMS_CollisionComponent::DisableCollision_Implementation()
{
	IsCollisionEnabled = false;
}

void UJMS_CollisionComponent::ClearHitActors()
{
	AlreadyActors.Empty();
}

void UJMS_CollisionComponent::SetCollisionMesh_Implementation(UPrimitiveComponent* Component)
{
	CollisionMeshComponent = Component;
}

void UJMS_CollisionComponent::CollisionTrace()
{
	FVector Start = CollisionMeshComponent->GetSocketLocation(StartSocketName);
	FVector End = CollisionMeshComponent->GetSocketLocation(EndSocketName);

	bool hit = UKismetSystemLibrary::SphereTraceMultiForObjects(GetWorld(), Start, End, TraceRadius, CollisionObjectType, false, ActorsToIgnore, EDrawDebugTrace::ForDuration, LastHits, true);

	if(hit)
	{
		for (const FHitResult& Element : LastHits)
		{
			
			AlreadyActors.AddUnique(Element.GetActor());
			OnHit.Execute(Element);
		}
	}
}

void UJMS_CollisionComponent::AddActorToIgnore(AActor* Actor)
{
	ActorsToIgnore.Add(Actor);
}

