// Include the main header file
#include "Main.h"

// Main function
int main() {
    // Initialize the game window
    InitWindow(screenWidth, screenHeight, "Biology quiz");

    // Set the target frames per second to 60
    SetTargetFPS(60);

    // Generate the levels
    generateLevels();

    // If the title screen is shown, start the game loop
    if (showTitleScreen()) {

        // Game loop
        while (!WindowShouldClose()) {

            // Toggle fullscreen on F11 key press
            if (IsKeyPressed(KEY_F11)) {
                ToggleFullscreen();
            }

            // If a question is not being displayed and the current level is not the last level, draw the level selection screen
            if (!isQuestionDisplayed && currentLevelIndex < levelsCount) {
                BeginDrawing();
                ClearBackground(RAYWHITE);

                // Draw the levels
                drawLevels();

                // Add exit button
                DrawText("Press Esc to exit", 10, screenHeight - 30, 20, BLACK);

                // Check if the player has clicked on a level and start displaying a question if they have
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
            // If a question is being displayed, draw the question screen
            else if (currentLevelIndex < levelsCount) {
                BeginDrawing();

                // Draw the question
                drawQuestion(questions[currentQuestionIndex]);

                // Draw the current score
                drawScore(currentScore);

                // Add exit button
                DrawText("Press Esc to exit", 10, screenHeight - 30, 20, BLACK);

                // Check if the player has answered the question and update the score and level status accordingly
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
            // If all levels have been completed
            else {
                // End game screen
                BeginDrawing();
                ClearBackground(RAYWHITE);

                DrawText("You finished!", screenWidth / 2 - 100, screenHeight / 2 - 50, 40, BLACK);

                // Display final score
				DrawText(("Final score: " + std::to_string(currentScore)).c_str(), screenWidth / 2 - 100, screenHeight / 2, 40, BLACK);

				// Add exit button
				DrawText("Press Esc to exit", 10, screenHeight - 30, 20, BLACK);

				EndDrawing();
			}
		}
	}
    
	// Close the game window
	CloseWindow();

	return 0;

	}
