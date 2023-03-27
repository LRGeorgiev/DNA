#pragma once


#include "raylib.h"

#define MAX_QUESTIONS 4
#define MAX_OPTIONS 4

typedef struct Question {
    char text[256];
    char options[MAX_OPTIONS][128];
    int correctOption;
} Question;


static int currentQuestionIndex = 0;
static int currentScore = 0;

static Question questions[MAX_QUESTIONS] = {
    {"What is the largest organ in the human body?", {"Heart", "Brain", "Skin", "Liver"}, 2},
    {"What is the powerhouse of the cell?", {"Mitochondria", "Nucleus", "Ribosome", "Lysosome"}, 0},
    {"What is the process by which plants convert light energy into food called?", {"Photosynthesis", "Respiration", "Fermentation", "Digestion"}, 0},
    {"What is the name of the process by which DNA is copied?", {"Transcription", "Translation", "Replication", "Mutation"}, 2}
};



