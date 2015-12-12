// Fill out your copyright notice in the Description page of Project Settings.
/*
#include "FThePolice.h"
#include "WorldBuilder.h"

WorldBuilder::WorldBuilder()
{
}

WorldBuilder::~WorldBuilder()
{
}
*/

// Fill out your copyright notice in the Description page of Project Settings.

#include "FThePolice.h"
#include "WorldBuilder.h"
#include "WallActor.h"
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


mapPoint mapGrid[gridSize][gridSize];

WorldBuilder::WorldBuilder()
{
	// clear grid
	for (int i = 0; i < gridSize; i++){
		for (int j = 0; j < gridSize; j++){
			grid[i][j].occupied = false;
			grid[i][j].inside = false;
			grid[i][j].LRTB = '0';
		}
	}
}

WorldBuilder::~WorldBuilder()
{
}
// given a world this function draws the grid onto the world
void WorldBuilder::createMap(UWorld * world_t){
	createOutline();
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			if (grid[i][j].occupied) {
				FVector Position = FVector(i * CUBE_MESH_SIZE, j * CUBE_MESH_SIZE, 0);
				FRotator Rotation = FRotator(0);
				world_t->SpawnActor<AWallActor>(AWallActor::StaticClass(), Position, Rotation);
			}
		}
	}

}

// creates a mapGrid from grid
void WorldBuilder::createMapGrid(){
	std::string str, str2;

	// print outside
	// copy occupied grid onto mapGrid
	UE_LOG(LogTemp, Warning, TEXT("grid: "));
	for (int y = (gridSize - 1); y >= 0; y--){
		str = "";
		for (int x = 0; x < gridSize; x++) {
			if (grid[x][y].occupied){
				mapGrid[x][y].occupied = 'W';
				str.append("W");
				//str.append(std::string(1,grid[x][y].LRTB));
			}
			/*
			if (grid[x][y].inside)
			str.append("I");
			*/
			else {
				str.append("O");
			}
			//str.append(std::string(1,grid[x][y].LRTB));

			if (x == gridSize - 1) {
				str.append("\n");
				UE_LOG(LogTemp, Warning, TEXT("string1 %s"), *FString(str.c_str()));
				//UE_LOG(LogTemp, Warning, TEXT("%d"), i);
			}
		}
	}
	// print inside
	for (int y = (gridSize - 1); y >= 0; y--){
		str = "";
		for (int x = 0; x < gridSize; x++) {
			if (grid[x][y].inside)
				str.append("I");
			else {
				str.append("O");
			}
			//str.append(std::string(1,grid[x][y].LRTB));

			if (x == gridSize - 1) {
				str.append("\n");
				UE_LOG(LogTemp, Warning, TEXT("string1 %s"), *FString(str.c_str()));
				//UE_LOG(LogTemp, Warning, TEXT("%d"), i);
			}
		}
	}
}

// draws all the rectangles onto grid
void WorldBuilder::createOutline(){
	int x, y, testWidth, testLength;
	int offset = gridSize / 2;
	rectangle rect_t;


	// initialize random seed:
	srand(time(NULL));
	int numRect = rand() % 7 + 3;

	//create first rectangle
	int length = rand() % 15 + 3;
	int width = rand() % 15 + 3;
	rect_t.x = 0;
	rect_t.y = 0;
	rect_t.length = length;
	rect_t.width = width;

	drawRectangle(rect_t);

	for (int i = 0; i < numRect; i++) {

		length = rand() % 10 + 3;
		width = rand() % 10 + 3;
		int trys = 0;

		do {
			trys++;

			// prevent too many tries
			if (trys > 200)
			{ // set next coordinates to gauranteed valid location // first rectangle area?
				x = width;
				y = length;
				break;
			}

			x = (gridSize - 1) / 2 - rand() % (gridSize - 1);
			y = (gridSize - 1) / 2 - rand() % (gridSize - 1);

			if (y + offset + length >= gridSize)
				testLength = length - (y + offset + length - (gridSize - 1));
			else
				testLength = length;
			if (x + offset + width >= gridSize)
				testWidth = width - (x + offset + width - (gridSize - 1));
			else
				testWidth = width;

			// make sure x and y are not in dead zone range
			// or origin
			// check all 4 corners of rectangle are inside
		} while (
			((x < 0 && x > -width) && (y < 0 && y > -length))
			|| (x == 0 && y == 0)
			|| !(grid[x + testWidth + offset - 1][y + testLength + offset - 1].inside
			|| grid[x + offset][y + offset].inside
			|| grid[x + testWidth + offset - 1][y + offset].inside
			|| grid[x + offset][y + testLength + offset - 1].inside)
			|| testLength<3
			|| testWidth <3
			);
		rect_t.x = x;
		rect_t.y = y;
		rect_t.length = length;
		rect_t.width = width;

		drawRectangle(rect_t);
	}

	// do not make a wall on the inside
	// clears the inside walls out of grid
	for (int x = 0; x < gridSize; x++) {
		for (int y = 0; y < gridSize; y++) {
			if (grid[x][y].occupied && grid[x][y].inside)
				grid[x][y].occupied = false;
		}
	}


	return;
}

void WorldBuilder::drawRectangle(rectangle rectangle_p) {
	int shiftedX, shiftedY, correctedLength, correctedWidth;
	shiftedX = rectangle_p.x + gridSize / 2;
	shiftedY = rectangle_p.y + gridSize / 2;


	if (shiftedY + rectangle_p.length >= gridSize)
		correctedLength = rectangle_p.length - (shiftedY + rectangle_p.length - (gridSize - 1));
	else
		correctedLength = rectangle_p.length;

	if (shiftedX + rectangle_p.width >= gridSize)
		correctedWidth = rectangle_p.width - (shiftedX + rectangle_p.width - (gridSize - 1));
	else
		correctedWidth = rectangle_p.width;

	UE_LOG(LogTemp, Warning, TEXT("rectangle  (%d, %d), %d x %d"), rectangle_p.x, rectangle_p.y, correctedLength, correctedWidth);
	for (int y = 0; y < correctedLength; y++) {
		for (int x = 0; x < correctedWidth; x++) {
			// default occupied true (spawn a wall)
			// default inside false (not the inside of the structure)
			char LRTB_t = '0';
			bool occupied_t = true; //grid[shiftedX + x][shiftedY + y].occupied;
			bool inside_t = grid[shiftedX + x][shiftedY + y].inside;

			// draw bottom
			if (y == 0) {
				LRTB_t = 'B';
			}
			// draw top
			else if (y == correctedLength - 1) {
				LRTB_t = 'T';
			}
			// draw left
			else if (x == 0) {
				LRTB_t = 'L';
			}
			// draw right
			else if (x == correctedWidth - 1) {
				LRTB_t = 'R';
			}
			else {
				// not occupied (dont spawn a wall here)
				LRTB_t = 'E';
				occupied_t = false;
				inside_t = true;
			}

			grid[shiftedX + x][shiftedY + y].occupied = occupied_t;
			grid[shiftedX + x][shiftedY + y].LRTB = LRTB_t;
			grid[shiftedX + x][shiftedY + y].inside = inside_t;

		}
	}
	return;
}
