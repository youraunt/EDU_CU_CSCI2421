//
// Created by BK Allen on 1/31/20.
//

#include "functions.h"


/// @brief Exits program successfully with message
std::string exitProgram() {
    std::cout << "Exiting program!" << std::endl;
    /// @brief I used EXIT_SUCCESS here to unwind the stack
    exit(EXIT_SUCCESS);
}

/// @brief Handles unusable input
void unknownInput() {
    std::cerr << "\nError?! Unknown input.\n" << std::endl;
    sleep(1);
    exitProgram();
}

/// @brief Function to handle user input 
///        handles whether or not to play another game
/// @return user input in its capital state
int playAgain() {
    std::cout << "\nPlay again? (Y/N)" << std::endl
              << "> ";
    char userInput;
    std::cin >> userInput;
    /// @brief I used int here to avoid implicit conversions
    int userInputCapital = toupper(userInput);
    return userInputCapital;
}///# playAgain


/// @brief Function to handle user input when
/// @brief range value m is entered
/// @brief will run until a valid m value is provided
/// @return maximum range or the m value
int maxRange() {
    int tempMax;
    do {
        std::cout << "\nPlease enter your m value, the maximum range within which you shall guess" << std::endl
                  << "Must be two or greater." << std::endl
                  << "> ";
        std::cin >> tempMax;
    } while (tempMax < 2);
    return tempMax;
}


/// @brief Function to handle user input
/// @brief asks user to input their n value
/// @return number of integers to guess
unsigned int numIntToGuess() {
    unsigned int numIntToGuess = 0;
    do {
        std::cout << "\nPlease enter your n, the number of integers to guess." << std::endl
                  << "> ";
        std::cin >> numIntToGuess;

    } while (numIntToGuess < 0);
    return numIntToGuess;
}///# numIntToGuess