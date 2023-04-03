#pragma once;

#include "Main.h"




// Define a struct to represent a level in the game
struct Level {
	Rectangle rect; // The rectangle used to draw the level on screen
	int number; // The level number
};

// Create a vector to store all the levels in the game
std::vector<Level> levels;

// Define the maximum number of questions in the game
const int MAX_QUESTIONS = 10;

// Define a struct to represent a question in the game
struct Question {
	std::string text; // The text of the question
	std::string options[4]; // An array of four possible answers to the question
	int correctAnswer; // The index of the correct answer in the options array
};

// Create an array to store all the questions in the game
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

// Note: These code comments provide an explanation for the purpose of each data structure and variable used in the code.