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

        // Draw the title of the game
        DrawText("Biology quiz", screenWidth / 2 - MeasureText("Biology quiz", 40) / 2, screenHeight / 3, 40, BLACK);

        // Draw the prompt to start the game
        DrawText("Press ENTER to start the game", screenWidth / 2 - MeasureText("Press ENTER to start the game", 20) / 2, screenHeight / 2, 20, GREEN);

        // Draw the prompt to show instructions
        DrawText("Press I for instructions", screenWidth / 2 - MeasureText("Press I for instructions", 20) / 2, screenHeight / 2 + 50, 20, MAROON);

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
            DrawText("Instructions:", 10, 10, 30, BLACK);
            DrawText("- Click on the level to show the question", 10, 60, 20, BLACK);
            DrawText("- Answer questions by selecting the corresponding number", 10, 90, 20, BLACK);
            DrawText("- Each correct answer earns you a point", 10, 120, 20, BLACK);

            // Wait for the user to confirm they've read the instructions before returning to the title screen
            if (IsKeyPressed(KEY_ENTER)) {
                showInstructions = false;
            }
        }

        EndDrawing();
    }

    // Return whether the user has chosen to start the game or not
    return startGame;
}

