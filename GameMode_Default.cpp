// Fill out your copyright notice in the Description page of Project Settings.

#include "FThePolice.h"
#include "GameMode_Default.h"
#include "WorldBuilder.h"
#include "LightSwitchActor.h"
#include "WallActor.h"

void AGameMode_Default::StartPlay(){
	Super::StartPlay();
	UE_LOG(LogTemp, Warning, TEXT("call to start play"));

	UWorld* const world_pointer = GetWorld();
	WorldBuilder worldBuilder_t = WorldBuilder();
	worldBuilder_t.createMap(world_pointer);
	worldBuilder_t.createMapGrid();
	
	// Testing out coordinates and lights
				FVector Position = FVector(0 , 0, 0);
				FRotator Rotation = FRotator(0);
	world_pointer->SpawnActor<ALightSwitchActor>(ALightSwitchActor::StaticClass(), Position, Rotation);
				Position = FVector(0 , 0, 0);
				Rotation = FRotator(0);
	world_pointer->SpawnActor<AWallActor>(AWallActor::StaticClass(), Position, Rotation);
	// end testing of lights
	
}