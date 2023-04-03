#pragma once
#include "Main.h"


// This function draws the levels on the screen
void drawLevels() {
	for (int i = 0; i < levelsCount; i++) {
		// Draw a rectangle for each level
		DrawRectangleRec(levels[i].rect, RED);
		// Draw the level number inside the rectangle
		DrawText(std::to_string(levels[i].number).c_str(), levels[i].rect.x + levelWidth / 2 - MeasureText(std::to_string(levels[i].number).c_str(), 30) / 2, levels[i].rect.y + levelHeight / 2 - 15, 30, BLACK);
	}
}

// This function returns a random index of a question from the array
int getRandomQuestionIndex() {
	return rand() % MAX_QUESTIONS;
}

// This function draws a question on the screen with its options
void drawQuestion(Question question) {
	ClearBackground(RAYWHITE);
	// Draw a rectangle around the question text
	DrawRectangleLines(screenWidth / 2 - MeasureText(question.text.c_str(), 30) / 2 - 10, screenHeight / 4 - 10, MeasureText(question.text.c_str(), 30) + 20, 50, BLACK);
	// Draw the question text inside the rectangle
	DrawText(question.text.c_str(), screenWidth / 2 - MeasureText(question.text.c_str(), 30) / 2, screenHeight / 4, 30, BLACK);
	for (int i = 0; i < 4; i++) {
		// Draw a rectangle around each option
		DrawRectangleLines(screenWidth / 2 - MeasureText(question.options[i].c_str(), 20) / 2 - 10, screenHeight / 2 + i * 50 - 10, MeasureText(question.options[i].c_str(), 20) + 20, 40, BLACK);
		// Draw each option text inside its rectangle
		DrawText(question.options[i].c_str(), screenWidth / 2 - MeasureText(question.options[i].c_str(), 20) / 2, screenHeight / 2 + i * 50, 20, BLACK);
	}
}

// This function checks if the selected answer is correct and updates the score
bool checkAnswer(Question question, int answer, int& score) {
	bool isCorrect = (answer == question.correctAnswer);
	if (isCorrect) {
		score++;
	}
	return isCorrect;
}

// This function draws the score on the screen
void drawScore(int score) {
	DrawText(("Score: " + std::to_string(score)).c_str(), 10, 10, 20, BLACK);
}