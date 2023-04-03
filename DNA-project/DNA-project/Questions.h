#pragma once;

#include "Main.h"



struct Level {
    Rectangle rect;
    int number;
};

std::vector<Level> levels;

const int MAX_QUESTIONS = 10;

struct Question {
    std::string text;
    std::string options[4];
    int correctAnswer;
};

Question questions[MAX_QUESTIONS] = {
    {"What is the largest organ in the human body?", {"Liver", "Heart", "Skin", "Brain"}, 3},
    {"What is the powerhouse of the cell?", {"Ribosome", "Nucleus", "Mitochondria", "Golgi Apparatus"}, 3},
    {"What is the smallest bone in the human body?", {"Stapes", "Coccyx", "Femur", "Radius"}, 1},
    {"Which organ produces insulin?", {"Pancreas", "Liver", "Kidney", "Stomach"}, 1},
    {"What is the name of the pigment that gives skin its color?", {"Melanin", "Hemoglobin", "Carotene", "Bilirubin"}, 1},
    {"What is the process by which plants convert sunlight into energy?", {"Photosynthesis", "Cellular respiration", "Mitosis", "Meiosis"}, 1},
    {"What is the name of the protein that makes up hair and nails?", {"Keratin", "Collagen", "Elastin", "Myosin"}, 1},
    {"What is the medical term for the windpipe?", {"Trachea", "Bronchus", "Larynx", "Esophagus"}, 1},
    {"What is the scientific name for the kneecap?", {"Patella", "Femur", "Tibia", "Fibula"}, 1},
    {"What is the name of the part of the brain responsible for regulating body temperature?", {"Hypothalamus", "Cerebellum", "Thalamus", "Medulla oblongata"}, 1}
};


