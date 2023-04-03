#pragma once

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