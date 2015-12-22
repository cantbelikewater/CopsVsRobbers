// Fill out your copyright notice in the Description page of Project Settings.

#include "FThePolice.h"
#include "LightSwitchActor.h"


ALightSwitchActor::ALightSwitchActor(const class FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	DesiredIntensity = 9000.0f;
	enableToggle = false;

	PointLight1 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight1"));
	PointLight1->Intensity = DesiredIntensity;
	PointLight1->bVisible = false;
	PointLight1->SetLightColor(FLinearColor(255, 0, 0, 1));
	RootComponent = PointLight1;

	Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
	Sphere1->InitSphereRadius(250.0f);
	Sphere1->AttachParent = RootComponent;

	Sphere1->OnComponentBeginOverlap.AddDynamic(this, &ALightSwitchActor::OnOverlapBegin);        // set up a notification for when this component overlaps something
	Sphere1->OnComponentEndOverlap.AddDynamic(this, &ALightSwitchActor::OnOverlapEnd);      // set up a notification for when this component overlaps something
	
	// TODO add the actual statick mesh
	// add physical representation so we can see the light switch
	// add animation for light toggle
	CubeMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("CubeMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("StaticMesh'/Game/FirstBoxMesh.FirstBoxMesh'"));
	if (StaticMeshAsset.Succeeded())
	{
		CubeMesh->SetStaticMesh(StaticMeshAsset.Object);
		CubeMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		CubeMesh->SetWorldScale3D(FVector(0.2f, 0.2f, 0.2f));
	}
	// select texture
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'"));
	CubeMesh->SetMaterial(0, Material.Object);
	CubeMesh->AttachParent = RootComponent;
	// END TODO

}

void ALightSwitchActor::OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		//ToggleLight();
		enableToggle = true;
	}
}

void ALightSwitchActor::OnOverlapEnd(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		//ToggleLight();
		enableToggle = false;
	}
}

void ALightSwitchActor::ToggleLight()
{
	if (enableToggle)
		PointLight1->ToggleVisibility();
}

