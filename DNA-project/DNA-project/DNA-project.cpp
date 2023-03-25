#include "raylib.h"

int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "DNA");
    SetTargetFPS(60);

    // Main menu variables
    int menuOption = 0;
    const char* menuOptions[] = { "Play", "Options", "Exit" };

    while (!WindowShouldClose()) // Main game loop
    {
        // Update
        if (IsKeyPressed(KEY_UP)) menuOption--;
        if (IsKeyPressed(KEY_DOWN)) menuOption++;
        if (menuOption < 0) menuOption = 2;
        if (menuOption > 2) menuOption = 0;

        if (IsKeyPressed(KEY_ENTER))
        {
            switch (menuOption)
            {
            case 0:
                // Open new game window
                CloseWindow(); // Close main menu window
                InitWindow(screenWidth, screenHeight, "Play");
                SetTargetFPS(60);
                // Add game logic here...
                break;
            case 1:
                // Open options menu
                break;
            case 2:
                // Exit game
                CloseWindow();
                break;
            }
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("DNA", screenWidth / 2 - MeasureText("DNA", 40) / 2, screenHeight / 4, 40, MAROON);

        for (int i = 0; i < 3; i++)
        {
            if (i == menuOption)
            {
                DrawText(TextFormat("> %s <", menuOptions[i]), screenWidth / 2 - MeasureText(menuOptions[i], 20) / 2, screenHeight / 2 + 50 * i, 20, DARKGRAY);
            }
            else
            {
                DrawText(menuOptions[i], screenWidth / 2 - MeasureText(menuOptions[i], 20) / 2, screenHeight / 2 + 50 * i, 20, GRAY);
            }
        }

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
