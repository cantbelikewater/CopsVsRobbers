/*
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class FTHEPOLICE_API WorldBuilder
{
public:
	WorldBuilder();
	~WorldBuilder();
};
*/

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "FThePolice.h"

#define gridSize 30
#define CUBE_MESH_SIZE 200


typedef struct {
	char occupied;
} mapPoint;

extern mapPoint mapGrid[gridSize][gridSize];

class FTHEPOLICE_API WorldBuilder
{

	typedef struct{
		int x;
		int y;
		int length;
		int width;
	} rectangle;

	/*
	occupied   wall should be build here
	inside     inside of the strcture
	keep       keep this wall
	LRTB       left, right, bottom, top wall
	*/
	typedef struct{
		bool occupied;
		bool inside;
		bool keep;
		char LRTB;
	} gridPoint;

	gridPoint grid[gridSize][gridSize];
	int minimumArea = 9;

public:
	WorldBuilder();
	~WorldBuilder();
	void createMapGrid();
	void createOutline();
	void createMap(UWorld* world_t);
private:
	void drawRectangle(rectangle rectangle_p);
};
