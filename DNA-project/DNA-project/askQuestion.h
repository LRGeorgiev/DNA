#pragma once

#include "raylib.h"
#include <Questions.h>

void askQuestion(Question question) {
    static double startTime = 0.0;
    double elapsedTime = 0.0;
    int remainingTime = 0;

    if (startTime == 0.0) {
        // Start the timer if it hasn't been started yet
        startTime = GetTime();
    }
    else {
        // Calculate the elapsed time
        elapsedTime = GetTime() - startTime;
        remainingTime = (int)(10.0 - elapsedTime); // set the time limit to 10 seconds
        if (remainingTime < 0) {
            // Reset the timer and move on to the next question if time is up
            startTime = 0.0;
            currentQuestionIndex++;
            if (currentQuestionIndex >= MAX_QUESTIONS) {
                currentQuestionIndex = 0;
            }
        }
    }

    // Draw the question and options
    DrawText(question.text, 50, 50, 20, BLACK);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        DrawText(TextFormat("%d. %s", i + 1, question.options[i]), 50, 100 + i * 50, 20, BLACK);
    }

    // Draw the timer
    DrawText(TextFormat("Time Remaining: %d", remainingTime), 50, 400, 20, BLACK);
}
