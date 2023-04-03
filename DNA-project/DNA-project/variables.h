#pragma once


#include "Main.h"
// Set screen size
const int screenWidth = 1600;
const int screenHeight = 900;

// Define the number of levels and the size of each level
const int levelsCount = 10;
const int levelWidth = 80;
const int levelHeight = 80;
const int levelPadding = 20;

// Set up boolean flags to track whether a question is displayed and whether it has been answered
bool isQuestionDisplayed = false;
bool hasAnsweredQuestion = false;

// Set the current question index to 0 and the current level index to -1 to start at the beginning of the game
int currentQuestionIndex = 0;
int currentLevelIndex = -1;

// Set the current score to 0 to start at the beginning of the game
int currentScore = 0; 