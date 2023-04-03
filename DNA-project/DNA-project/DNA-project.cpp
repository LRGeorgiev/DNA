#include "Main.h"



int main() {
    InitWindow(screenWidth, screenHeight, "Biology quiz");

    SetTargetFPS(60);

    generateLevels();

    bool isQuestionDisplayed = false;
    bool hasAnsweredQuestion = false;
    int currentQuestionIndex = 0;
    int currentLevelIndex = -1;
    int currentScore = 0; // new variable to keep track of the current score

    if (showTitleScreen()) {
        while (!WindowShouldClose()) {

            if (IsKeyPressed(KEY_F11)) {
                ToggleFullscreen();
            }
            
            if (!isQuestionDisplayed && currentLevelIndex < levelsCount) {
                BeginDrawing();
                ClearBackground(RAYWHITE);

                drawLevels();

                // Add exit button
                DrawText("Press Esc to exit", 10, screenHeight - 30, 20, BLACK);

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
            else if (currentLevelIndex < levelsCount) {
                BeginDrawing();
                drawQuestion(questions[currentQuestionIndex]);
                
                drawScore(currentScore);

                // Add exit button
                DrawText("Press Esc to exit", 10, screenHeight - 30, 20, BLACK);

                if (IsKeyPressed(KEY_ONE)) {
                    if (checkAnswer(questions[currentQuestionIndex], 1, currentScore)) {
                        levels[currentLevelIndex].rect.width = 0;
                        levels[currentLevelIndex].rect.height = 0;
                    }
                    hasAnsweredQuestion = true;
                }
                else if (IsKeyPressed(KEY_TWO)) {
                    if (checkAnswer(questions[currentQuestionIndex], 1, currentScore)) {
                        levels[currentLevelIndex].rect.width = 0;
                        levels[currentLevelIndex].rect.height = 0;
                    }
                    hasAnsweredQuestion = true;
                }
                else if (IsKeyPressed(KEY_THREE)) {
                    if (checkAnswer(questions[currentQuestionIndex], 1, currentScore)) {
                        levels[currentLevelIndex].rect.width = 0;
                        levels[currentLevelIndex].rect.height = 0;
                    }
                    hasAnsweredQuestion = true;
                }
                else  if (IsKeyPressed(KEY_FOUR)) {
                    if (checkAnswer(questions[currentQuestionIndex], 1, currentScore)) {
                        levels[currentLevelIndex].rect.width = 0;
                        levels[currentLevelIndex].rect.height = 0;
                    }
                    hasAnsweredQuestion = true;
                }
                if (hasAnsweredQuestion) {
                    currentLevelIndex++;
                    currentQuestionIndex = getRandomQuestionIndex();
                    isQuestionDisplayed = false;
                    hasAnsweredQuestion = false;
                }

                // Display current score
                DrawText(("Score: " + std::to_string(currentScore)).c_str(), 10, 10, 20, BLACK);

                EndDrawing();
            }
            else {
                // End game screen
                BeginDrawing();
                ClearBackground(RAYWHITE);

                DrawText("You finished!", screenWidth / 2 - 100, screenHeight / 2 - 50, 40, BLACK);

                // Display final score
                DrawText(("Final score: " + std::to_string(currentScore)).c_str(), screenWidth / 2 - 100, screenHeight / 2, 40, BLACK);
               

                if (IsKeyPressed(KEY_ENTER)) {
                    generateLevels();
                    isQuestionDisplayed = false;
                    hasAnsweredQuestion = false;
                    currentQuestionIndex = 0;
                    currentLevelIndex = -1;
                    currentScore = 0;
                }

                EndDrawing();
            }
        }
    }

    CloseWindow();

    return 0;
}

