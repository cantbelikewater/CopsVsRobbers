// Fill out your copyright notice in the Description page of Project Settings.

#include "FThePolice.h"
#include "GenericCharacter.h"


// Sets default values
AGenericCharacter::AGenericCharacter(const class FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{

		CapsuleComponent->InitCapsuleSize(90, 90);
	/*
	CapsuleComponent = ObjectInitializer.CreateDefaultSubobject<UCapsuleComponent>(this, TEXT("CapsuleComp"));
	if (CapsuleComponent)
	{
		CapsuleComponent->BodyInstance.SetCollisionProfileName("OverlapAll");
	}
	RootComponent = CapsuleComponent;
	*/

	//CapsuleComponent->InitCapsuleSize(200, 200);
	//CapsuleComponent->SetCapsuleHalfHeight(200, true);
	// TODO Temporarily use cube mes
	SkeletalPlaceholder = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("CubeMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("StaticMesh'/Game/FirstBoxMesh.FirstBoxMesh'"));

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGenericCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGenericCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AGenericCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

