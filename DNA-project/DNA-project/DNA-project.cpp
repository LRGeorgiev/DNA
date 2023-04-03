#include "Main.h"



int main(){

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

                // Add exit button
                DrawText("Press Esc to exit", 10, screenHeight - 30, 20, BLACK);

                if (IsKeyPressed(KEY_ONE)) {
                    if (checkAnswer(questions[currentQuestionIndex], 1)) {
                        currentScore++;
                        levels[currentLevelIndex].rect.width = 0;
                        levels[currentLevelIndex].rect.height = 0;
                    }
                    hasAnsweredQuestion = true;
                }
                else if (IsKeyPressed(KEY_TWO)) {
                    if (checkAnswer(questions[currentQuestionIndex], 2)) {
                        currentScore++;
                        levels[currentLevelIndex].rect.width = 0;
                        levels[currentLevelIndex].rect.height = 0;
                    }
                    hasAnsweredQuestion = true;
                }
                else if (IsKeyPressed(KEY_THREE)) {
                    if (checkAnswer(questions[currentQuestionIndex], 3)) {
                        currentScore++;
                        levels[currentLevelIndex].rect.width = 0;
                        levels[currentLevelIndex].rect.height = 0;
                    }
                    hasAnsweredQuestion = true;
                }
                else if (IsKeyPressed(KEY_FOUR)) {
                    if (checkAnswer(questions[currentQuestionIndex], 4)) {
                        currentScore++;
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

                EndDrawing();
            }
            else {
                // End game screen
                BeginDrawing();
                ClearBackground(RAYWHITE);

                DrawText("You finished!", screenWidth / 2 - 100, screenHeight / 2 - 50, 40, BLACK);
            
                DrawText("Press Esc to exit", 10, screenHeight - 30, 20, BLACK);

                EndDrawing();

                // Add exit functionality
                if (IsKeyPressed(KEY_ESCAPE)) {
                    break;
                }
            }
        }


    CloseWindow();

    return 0;
}

    
	}