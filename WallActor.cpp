/*
// Fill out your copyright notice in the Description page of Project Settings.

#include "FThePolice.h"
#include "WallActor.h"


// Sets default values
AWallActor::AWallActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWallActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWallActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

*/

// Fill out your copyright notice in the Description page of Project Settings.

#include "FThePolice.h"
#include "WallActor.h"


// Sets default values

AWallActor::AWallActor(const class FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	CubeMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("CubeMesh"));
	RootComponent = CubeMesh;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("StaticMesh'/Game/FirstBoxMesh.FirstBoxMesh'"));
	if (StaticMeshAsset.Succeeded())
	{
		CubeMesh->SetStaticMesh(StaticMeshAsset.Object);
		CubeMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		CubeMesh->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	}
	// select texture
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Rock_Basalt.M_Rock_Basalt'"));
	CubeMesh->SetMaterial(0, Material.Object);

}

/*
// Called when the game starts or when spawned
void AWallActor::BeginPlay()
{
Super::BeginPlay();

}

// Called every frame
void AWallActor::Tick( float DeltaTime )
{
Super::Tick( DeltaTime );

}
*/
