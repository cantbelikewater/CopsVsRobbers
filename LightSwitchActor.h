// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "LightSwitchActor.generated.h"

UCLASS()
class FTHEPOLICE_API ALightSwitchActor : public AActor
{
	GENERATED_BODY()

private:
	bool enableToggle;
	UPROPERTY(VisibleAnywhere, Category = "Switch Components")
	class UStaticMeshComponent* CubeMesh;
public:	
	
	/** point light component */
	UPROPERTY(VisibleAnywhere, Category = "Switch Components")
	class UPointLightComponent* PointLight1;
	
	/** sphere component */
	UPROPERTY(VisibleAnywhere, Category = "Switch Components")
	class USphereComponent* Sphere1;

	ALightSwitchActor(const class FObjectInitializer& ObjectInitiailzier);

	/** called when something enters the sphere component */
	UFUNCTION()
		void OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/** called when something leaves the sphere component */
	UFUNCTION()
		void OnOverlapEnd(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	/** Toggles the light component's visibility*/
	UFUNCTION()
		void ToggleLight();

	/** the desired intensity for the light */
	UPROPERTY(VisibleAnywhere, Category = "Switch Variables")
		float DesiredIntensity;
	/*
	// Sets default values for this actor's properties
	ALightSwitchActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	*/

	
	
};
