// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "GenericCharacter.generated.h"

UCLASS()
class FTHEPOLICE_API AGenericCharacter : public ACharacter
{

	GENERATED_BODY()

public:
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Assets")
	//USkeletalMesh* SkeletalMeshAsset;
	UStaticMeshComponent* SkeletalPlaceholder;

	//UPROPERTY(VisibleAnywhere, Category = "Switch Components")
	//UCapsuleComponent* CapsuleComponent;

	// Sets default values for this character's properties
	AGenericCharacter(const class FObjectInitializer& ObjectInitiailzier);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
