// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "WallActor.generated.h"

UCLASS()
class FTHEPOLICE_API AWallActor : public AActor
{
	GENERATED_BODY()

		UPROPERTY(Category = Meshes, VisibleAnywhere)
	class UStaticMeshComponent* CubeMesh;
public:
	AWallActor(const class FObjectInitializer& ObjectInitiailzier);
	// Sets default values for this actor's properties
	//AWallActor();

	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

	// Called every frame
	//virtual void Tick( float DeltaSeconds ) override;

};

