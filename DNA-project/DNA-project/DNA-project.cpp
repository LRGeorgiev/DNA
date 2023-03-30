


#include "Main.h"


const int screenWidth = 1920;
const int screenHeight = 1080;
const int levelsCount = 10;
const int levelWidth = 80;
const int levelHeight = 80;
const int levelPadding = 20;

struct Level {
    Rectangle rect;
    int number;
};

std::vector<Level> levels;

const int MAX_QUESTIONS = 3;

struct Question {
    std::string text;
    std::string options[4];
    int correctAnswer;
};

Question questions[MAX_QUESTIONS] = {
    {"What is the largest organ in the human body?", {"Liver", "Heart", "Skin", "Brain"}, 3},
    {"What is the powerhouse of the cell?", {"Ribosome", "Nucleus", "Mitochondria", "Golgi Apparatus"}, 3},
    {"What is the smallest bone in the human body?", {"Stapes", "Coccyx", "Femur", "Radius"}, 1}
};

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
    DrawText(question.text.c_str(), screenWidth / 2 - MeasureText(question.text.c_str(), 30) / 2, screenHeight / 4, 30, BLACK);
    for (int i = 0; i < 4; i++) {
        DrawText(question.options[i].c_str(), screenWidth / 2 - MeasureText(question.options[i].c_str(), 20) / 2, screenHeight / 2 + i * 50, 20, BLACK);
    }
}

bool checkAnswer(Question question, int answer) {
    return answer == question.correctAnswer;
}

int main() {
    InitWindow(screenWidth, screenHeight, "Levels and Questions");

    SetTargetFPS(60);

    generateLevels();

    bool isQuestionDisplayed = false;
    bool hasAnsweredQuestion = false; // new variable
    int currentQuestionIndex = 0;
    int currentLevelIndex = -1;
    int currentScore = 0;

    while (!WindowShouldClose()) {
        if (!isQuestionDisplayed) {
            BeginDrawing();
            ClearBackground(RAYWHITE);

            drawLevels();

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                for (int i = 0; i < levelsCount; i++) {
                    if (CheckCollisionPointRec(GetMousePosition(), levels[i].rect)) {
                        currentLevelIndex = i;
                        currentQuestionIndex = getRandomQuestionIndex();
                        isQuestionDisplayed = true;
                    }
                }

            }


            EndDrawing();
        }
        else {
            BeginDrawing();
            drawQuestion(questions[currentQuestionIndex]);
            if (IsKeyPressed(KEY_ONE)) {
                if (checkAnswer(questions[currentQuestionIndex], 1)) {
                    currentScore++;
                    levels[currentLevelIndex].rect.width = 0;
                    levels[currentLevelIndex].rect.height = 0;
                }
                isQuestionDisplayed = false;
            }
            else if (IsKeyPressed(KEY_TWO)) {
                if (checkAnswer(questions[currentQuestionIndex], 2)) {
                    currentScore++;
                    levels[currentLevelIndex].rect.width = 0;
                    levels[currentLevelIndex].rect.height = 0;
                }
                isQuestionDisplayed = false;
            }
            else if (IsKeyPressed(KEY_THREE)) {
                if (checkAnswer(questions[currentQuestionIndex], 3)) {
                    currentScore++;
                    levels[currentLevelIndex].rect.width = 0;
                    levels[currentLevelIndex].rect.height = 0;
                }
                isQuestionDisplayed = false;
            }
            else if (IsKeyPressed(KEY_FOUR)) {
                if (checkAnswer(questions[currentQuestionIndex], 4)) {
                    currentScore++;
                    levels[currentLevelIndex].rect.width = 0;
                    levels[currentLevelIndex].rect.height = 0;
                }
                isQuestionDisplayed = false;
            }
            EndDrawing();
        }
    }

    CloseWindow();

    return 0;
}