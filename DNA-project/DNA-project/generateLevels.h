#pragma once;

#include "Main.h"



// This function generates the levels and their positions on the screen.
// It calculates the x and y coordinates for the first level based on the screen width and height,
// as well as the total number of levels and the dimensions of each level.
// It then creates a Level struct for each level and adds it to the levels vector.
// The level number is set to the index of the level plus one.
void generateLevels() {
	int x = (screenWidth - (levelsCount * levelWidth) - ((levelsCount - 1) * levelPadding)) / 2;
	int y = (screenHeight - levelHeight) / 2;
	for (int i = 0; i < levelsCount; i++) {
		Level level;
		level.rect.x = x + (i * (levelWidth + levelPadding));
		level.rect.y = y;
		level.rect.width = levelWidth;
		level.rect.height = levelHeight;
		level.number = i + 1;
		levels.push_back(level);
	}
}