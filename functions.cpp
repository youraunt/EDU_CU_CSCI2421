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

int playAgain() {
    std::cout << "\nPlay again? (Y/N)" << std::endl;
    std::cout << "> ";
    char userInput;

    std::cin >> userInput;
    int userInputCap = toupper(userInput);
    return userInputCap;
}

unsigned int numberOfElements() {
    unsigned int numberItems = 0;
    while (numberItems <= 0) {
        std::cout << "\nPlease enter your n, the number of integer(s) to guess" << std::endl
                  << "> ";
        if (!(std::cin >> numberItems)) {
            std::cout << "The number must be positive." << std::endl
                      << "Please try again" << std::endl;
            std::cin.clear();
        }
    }
    return numberItems;
}

int maxRange() {
    int tempMax = 0;
    while (tempMax <= 0) {
        std::cout << "\nPlease enter your m value, the maximum range within which you shall guess" << std::endl
                  << "> ";
        if (!(std::cin >> tempMax)) {
            std::cout << "The number must be positive." << std::endl
                      << "Please try again" << std::endl;
            std::cin.clear();
        }
    }
    return tempMax;
}
