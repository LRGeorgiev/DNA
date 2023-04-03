#pragma once;

#include "Main.h"



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