#pragma once

#include "raylib.h"
#include <Questions.h>




bool checkAnswer(Question question, int selectedOption) {
    bool isCorrect = (selectedOption - 1 == question.correctOption);
    if (isCorrect) {
        currentScore++;
        DrawText("Correct!", 50, 400, 20, GREEN);
    }
    else {
        DrawText("Incorrect!", 50, 400, 20, RED);
    }
    return isCorrect;
}
