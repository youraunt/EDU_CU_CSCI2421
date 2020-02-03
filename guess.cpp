//
// Created by BK Allen on 1/31/20.
//
#include "guess.h"
#include <iostream>

GuessingGame::GuessingGame (unsigned int min, int max, unsigned int size) {
    // create object for seeding
    std::random_device randomDevice;
    // create engine and seed it
    std::mt19937 engine{randomDevice()};
    // distribution in range [1, max]
    std::uniform_int_distribution<std::mt19937::result_type> dist20(min, max);

    /// @brief Instance Variables
    this->max = max;
    this->size = size;


    /// @brief Generate random numbers for the user to try and guess.
    for (unsigned int i = 0; i < this->size; ++i) {
        /// implicit conversion this is changing signedness
        /// but I don't know that it affects the program
        this->randomIntegers.push_back(dist20(engine));
    }
}

/// @brief game play happens here
void GuessingGame::startGuess() {

    int rounds = 3;
    while (rounds > 0) {
        unsigned int remainingGuesses = this->size;
        /// @brief Vector to store user guesses
        vector<int> guesses;

        /// @brief Explain the game.
        std::cout << "\nEnter your guesses for the " << this->size
                  << " integer(s) in the range from " << GuessingGame::min
                  << " to " << this->max << "." << std::endl
                  << "\nRounds remaining: " << rounds << std::endl;

        /// @brief store data for 1 round
        while (remainingGuesses > 0) {
            for (unsigned int i = 0; i < this->size; ++i) {
                std::cout << "Guesses remaining: " << remainingGuesses << std::endl
                          << "> ";
                int guess;
                std::cin >> guess;
                guesses.push_back(guess);
                --remainingGuesses;
            }
        }///#while

        --rounds;

        /// @brief check for mathces
        unsigned int matches = this->correctGuesses(&guesses);

        //If the user guessed everything correctly, end the game.
        // If the matches is the size, the user guessed everything correctly
        if (matches >= this->size) {
            cout << "You are correct!";
            break;
        } else if (matches != this->size)
            std::cout << "No luck! You matched " << matches
                      << " out of " << size << " guesses." << std::endl;
    }
}


unsigned int GuessingGame::correctGuesses(vector<int> *guesses) {
    //Copy the guess vector and the secret number vector
    // this is a necessary step because we don't want to count a single guess as
    // multiple correct answers or multiple guesses as correct for a single
    // secret sequence element
    // We will remove elements from these arrays if a correct guess is made.
    vector<int> unusedGuesses(*guesses);
    vector<int> unmatchedRondomIntegers(this->randomIntegers);

    //Initialize a count of correct guesses
    unsigned int correctGuessCount = 0;

    //Compare every guess to every secret number
    // If there's a match, it's a correct guess.
    //   Increment the count then remove the pair from the storage vectors
    for (unsigned int i = 0; i < unusedGuesses.size(); i++) {
        for (unsigned int j = 0; j < unmatchedRondomIntegers.size(); j++) {
            //If the guess matches the number, we found a correct guess
            if (unusedGuesses[i] == unmatchedRondomIntegers[j]) {
                //Erase the pair to avoid double count
                unmatchedRondomIntegers.erase(unmatchedRondomIntegers.begin() + j);
                unusedGuesses.erase(unusedGuesses.begin() + i);

                //Decrement i because we removed an element and i is about to be incremented.
                // We actually need to check the same index again.
                // j doesn't need to be decremented because we're about to break out of this loop.
                i--;

                //Increment the guess count; that's the whole point of this
                correctGuessCount++;

                //Break; the same guess can't be used twice, so there's no point in checking the rest.
                break;
            }
        }
    }
    return correctGuessCount;
}
