#pragma once

#include "Main.h"

bool showTitleScreen() {
    bool startGame = false;
    bool showInstructions = false;

    while (!startGame && !WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw title
        DrawText("Biology quiz", screenWidth / 2 - MeasureText("Biology quiz", 40) / 2, screenHeight / 3, 40, BLACK);

        // Draw start game prompt
        DrawText("Press ENTER to start the game", screenWidth / 2 - MeasureText("Press ENTER to start the game", 20) / 2, screenHeight / 2, 20, GREEN);

        // Draw instructions prompt
        DrawText("Press I for instructions", screenWidth / 2 - MeasureText("Press I for instructions", 20) / 2, screenHeight / 2 + 50, 20, MAROON);

        // Check for user input
        if (IsKeyPressed(KEY_ENTER)) {
            startGame = true;
        }

        if (IsKeyPressed(KEY_I)) {
            showInstructions = true;
        }

        // Show instructions
        if (showInstructions) {
            ClearBackground(RAYWHITE);
            DrawText("Instructions:", 10, 10, 30, BLACK);
            DrawText("- Use the arrow keys to select a level", 10, 60, 20, BLACK);
            DrawText("- Answer questions by selecting the corresponding number", 10, 90, 20, BLACK);
            DrawText("- Each correct answer earns you a point", 10, 120, 20, BLACK);
            DrawText("- You have 10 seconds to answer each question", 10, 150, 20, BLACK);
            DrawText("Press ENTER to start the quiz", screenWidth / 2 - MeasureText("Press ENTER to return to the title screen", 20) / 2, screenHeight - 50, 20, GREEN);

            if (IsKeyPressed(KEY_ENTER)) {
                showInstructions = false;
            }
        }

        EndDrawing();
    }

    return startGame;
}
