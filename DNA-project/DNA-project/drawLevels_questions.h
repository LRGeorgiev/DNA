#pragma once
#include "Main.h"


void drawLevels() {
    for (int i = 0; i < levelsCount; i++) {
        DrawRectangleRec(levels[i].rect, BLUE);
        DrawText(std::to_string(levels[i].number).c_str(), levels[i].rect.x + levelWidth / 2 - MeasureText(std::to_string(levels[i].number).c_str(), 30) / 2, levels[i].rect.y + levelHeight / 2 - 15, 30, WHITE);
    }
}

int getRandomQuestionIndex() {
    return rand() % MAX_QUESTIONS;
}

void drawQuestion(Question question) {
    ClearBackground(RAYWHITE);
    // Draw square around the question
    DrawRectangleLines(screenWidth / 2 - MeasureText(question.text.c_str(), 30) / 2 - 10, screenHeight / 4 - 10, MeasureText(question.text.c_str(), 30) + 20, 50, BLACK);
    DrawText(question.text.c_str(), screenWidth / 2 - MeasureText(question.text.c_str(), 30) / 2, screenHeight / 4, 30, BLACK);
    for (int i = 0; i < 4; i++) {
        // Draw square around the option
        DrawRectangleLines(screenWidth / 2 - MeasureText(question.options[i].c_str(), 20) / 2 - 10, screenHeight / 2 + i * 50 - 10, MeasureText(question.options[i].c_str(), 20) + 20, 40, BLACK);
        DrawText(question.options[i].c_str(), screenWidth / 2 - MeasureText(question.options[i].c_str(), 20) / 2, screenHeight / 2 + i * 50, 20, BLACK);
    }
}



bool checkAnswer(Question question, int answer, int& score) {
    bool isCorrect = (answer == question.correctAnswer);
    if (isCorrect) {
        score++;
    }
    return isCorrect;
}


void drawScore(int score) {
    DrawText(("Score: " + std::to_string(score)).c_str(), 10, 10, 20, BLACK);
}