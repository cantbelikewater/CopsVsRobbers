// Fill out your copyright notice in the Description page of Project Settings.

#include "FThePolice.h"
#include "GameMode_Default.h"
#include "WorldBuilder.h"

void AGameMode_Default::StartPlay(){
	Super::StartPlay();
	UE_LOG(LogTemp, Warning, TEXT("call to start play"));
	UWorld* const world_pointer = GetWorld();
	WorldBuilder worldBuilder_t = WorldBuilder();
	worldBuilder_t.createMap(world_pointer);

	
}