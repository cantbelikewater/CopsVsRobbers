// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DoorActor.generated.h"

UCLASS()
class FTHEPOLICE_API ADoorActor : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(Category = Meshes, VisibleAnywhere)
	class UStaticMeshComponent* CubeMesh;
	
public:	
	UPROPERTY(VisibleAnywhere, Category = "Trigger Area")
	class USphereComponent* TriggerSphere;

	ADoorActor(const class FObjectInitializer& ObjectInitiailzier);
	/*
	// called when something enters the sphere component
	UFUNCTION()
	void OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// called when something leaves the sphere component
	UFUNCTION()
	void OnOverlapEnd(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	*/

	/*
	// Sets default values for this actor's properties
	ADoorActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	*/

	
	
};
