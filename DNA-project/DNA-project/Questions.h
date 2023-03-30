#pragma once;

#include "Main.h"



struct Level {
    Rectangle rect;
    int number;
};

std::vector<Level> levels;

const int MAX_QUESTIONS = 3;

struct Question {
    std::string text;
    std::string options[4];
    int correctAnswer;
};

Question questions[MAX_QUESTIONS] = {
    {"What is the largest organ in the human body?", {"Liver", "Heart", "Skin", "Brain"}, 3},
    {"What is the powerhouse of the cell?", {"Ribosome", "Nucleus", "Mitochondria", "Golgi Apparatus"}, 3},
    {"What is the smallest bone in the human body?", {"Stapes", "Coccyx", "Femur", "Radius"}, 1}
};
