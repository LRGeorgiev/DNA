#pragma once

#include "Main.h"

// Function to display the title screen and prompt the user to start the game or show instructions
bool showTitleScreen() {
    // Initialize startGame and showInstructions flags to false
    bool startGame = false;
    bool showInstructions = false;

    // While the user has not started the game and the window is still open
    while (!startGame && !WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw a rectangle around the title of the game
        DrawRectangleLines(screenWidth / 2 - MeasureText("Biology quiz", 40) / 2 - 10, screenHeight / 3 - 10, MeasureText("Biology quiz", 40) + 20, 60, BLACK);
        // Draw the title of the game inside the rectangle
        DrawText("Biology quiz", screenWidth / 2 - MeasureText("Biology quiz", 40) / 2, screenHeight / 3, 40, BLACK);

        // Draw a rectangle around the prompt to start the game
        DrawRectangleLines(screenWidth / 2 - MeasureText("Press ENTER to start the game", 20) / 2 - 10, screenHeight / 2 - 10, MeasureText("Press ENTER to start the game", 20) + 20, 40, BLACK);
        // Draw the prompt to start the game inside the rectangle
        DrawText("Press ENTER to start the game", screenWidth / 2 - MeasureText("Press ENTER to start the game", 20) / 2, screenHeight / 2, 20, GREEN);

        // Draw a rectangle around the prompt to show instructions
        DrawRectangleLines(screenWidth / 2 - MeasureText("Press I for instructions", 20) / 2 - 10, screenHeight / 2 + 40 - 10, MeasureText("Press I for instructions", 20) + 20, 40, BLACK);
        // Draw the prompt to show instructions inside the rectangle
        DrawText("Press I for instructions", screenWidth / 2 - MeasureText("Press I for instructions", 20) / 2, screenHeight / 2 + 40, 20, MAROON);

        // Check for user input to start the game or show instructions
        if (IsKeyPressed(KEY_ENTER)) {
            startGame = true;
        }

        if (IsKeyPressed(KEY_I)) {
            showInstructions = true;
        }

        // If the user wants to show instructions, display them and wait for confirmation to return to the title screen
        if (showInstructions) {
            ClearBackground(RAYWHITE);

            // Draw a rectangle around the instructions
            DrawRectangleLines(10, 10, screenWidth - 20, screenHeight - 20, BLACK);
            DrawText("Instructions:", 20, 20, 30, BLACK);
            DrawText("- Click on the level to show the question", 20, 70, 20, BLACK);
            DrawText("- Answer questions by selecting the corresponding number", 20, 100, 20, BLACK);
            DrawText("- Each correct answer earns you a point", 20, 130, 20, BLACK);

            // Draw a prompt to confirm the user has read the instructions
            DrawText("Press C to close the instructionns", screenWidth / 2 - MeasureText("Press ENTER to return to the title screen", 20) / 2, screenHeight - 60, 20, BLACK);

            // Wait for the user to confirm they've read the instructions before returning to the

			// title screen

			if (IsKeyPressed(KEY_C)) {
				showInstructions = false;
			}
		}

		EndDrawing();
	}

	// Return the startGame flag
	return startGame;

}