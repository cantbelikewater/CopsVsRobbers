// Fill out your copyright notice in the Description page of Project Settings.

#include "FThePolice.h"
#include "DoorActor.h"

ADoorActor::ADoorActor(const class FObjectInitializer& ObjectInitializer)
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
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'"));
	CubeMesh->SetMaterial(0, Material.Object);

}
