#include "Main.h"

bool showTitleScreen() {
    bool startGame = false;
    while (!startGame && !WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Biology quiz", screenWidth / 2 - MeasureText("Biology quiz", 40) / 2, screenHeight / 3, 40, BLACK);
        DrawText("Press ENTER to start the game", screenWidth / 2 - MeasureText("Press ENTER to start the game", 20) / 2, screenHeight / 2, 20, GREEN);

        if (IsKeyPressed(KEY_ENTER)) {
            startGame = true;
        }

        EndDrawing();
    }

    return startGame;
}

int main() {
    InitWindow(screenWidth, screenHeight, "Biology quiz");

    SetTargetFPS(60);

    generateLevels();

    bool isQuestionDisplayed = false;
    bool hasAnsweredQuestion = false; // new variable
    int currentQuestionIndex = 0;
    int currentLevelIndex = -1;
    int currentScore = 0;

    if (showTitleScreen()) {
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
    }

    CloseWindow();

    return 0;
}
