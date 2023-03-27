#include "Main.h"


int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Biology Quiz Game");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        askQuestion(questions[currentQuestionIndex]);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();

            for (int i = 0; i < MAX_OPTIONS; i++) {

                if (mouseX >= 50 && mouseX <= 50 + MeasureText(questions[currentQuestionIndex].options[i], 20) &&
                    mouseY >= 100 + i * 50 && mouseY <= 100 + i * 50 + 20) {



                    bool result = checkAnswer(questions[currentQuestionIndex], i + 1);
                    currentQuestionIndex++;
                    if (currentQuestionIndex >= MAX_QUESTIONS) {
                        currentQuestionIndex = 0;
                    }
                }
            }
        }

        DrawText(TextFormat("Score: %d", currentScore), screenWidth - 150, 20, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}