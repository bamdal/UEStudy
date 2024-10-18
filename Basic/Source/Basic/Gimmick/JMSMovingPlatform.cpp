

#include "JMSMovingPlatform.h"


AJMSMovingPlatform::AJMSMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRoot);

	StaticMesh= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("STATIC_MESH"));
	StaticMesh->SetupAttachment(DefaultSceneRoot);
	
}

void AJMSMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	StaticMesh->OnComponentHit.AddDynamic(this,&AJMSMovingPlatform::PlayerOnHit);
}

void AJMSMovingPlatform::PlayerOnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	
}

void AJMSMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);	
	
}


void AJMSMovingPlatform::MovePlatform(float DeltaTime)
{
	if(MoveDistance!=0)
	if(ShouldPlatformReturn())
	{
		// 방향 벡터
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation += MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation += PlatformVelocity * DeltaTime;
		SetActorLocation(CurrentLocation);

		
	}
}

void AJMSMovingPlatform::RotatePlatform(float DeltaTime)
{
	/*FRotator CurrentRotation = GetActorRotation();
	CurrentRotation +=  RotationVelocity * DeltaTime;
	SetActorRotation(CurrentRotation);	*/
	FQuat CurrentQuat = GetActorQuat();
	CurrentQuat *= FQuat(RotationVelocity * DeltaTime);
	AddActorLocalRotation(CurrentQuat);
	FRotator CurrentRotator = GetActorRotation();
	SetActorRotation(CurrentQuat.Rotator());
}

bool AJMSMovingPlatform::ShouldPlatformReturn() const
{
	
	return GetDistancMoved() > MoveDistance;
}

float AJMSMovingPlatform::GetDistancMoved() const
{
	//return  FVector::DistSquared(StartLocation,GetActorLocation());
	return FVector::Dist(StartLocation,GetActorLocation());
}
