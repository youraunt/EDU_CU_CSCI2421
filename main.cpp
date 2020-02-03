

#include "guess.h"
#include "functions.h"

/// @brief Debugging lambda
#define WHAT_IS(x) std::cerr << #x << " is " << x << std::endl;

using namespace std;


int main() {
    try {
        while (true) {
            /// @brief Logical error on i/o operation
            ///        Fail() = true
            /// @param except, set to failbit, the error
            /// flag here, is a bitmask value of iostate
            std::cin.exceptions(std::istream::failbit);
            std::cout << MENU_TITLE << std::endl
                      << GAME_EXPLANATION << std::endl;
            const int min = 1;
            int max = maxRange();
            unsigned int size = numIntToGuess();


            /// @brief 1 instance is initialized here this call generates random numbers
            GuessingGame instance(min, max, size);

            /// @brief activate 1 instance of game
            instance.startGuess();

            /// @brief Call playAgain function to handle user input
            int anotherRound = playAgain();
            if (anotherRound != 'Y') exitProgram();
        }///#while
    } catch (const std::exception &) {
        unknownInput();
    }///#catch
}///#main

