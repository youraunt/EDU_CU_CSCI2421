//
// Created by BK Allen on 1/31/20.
//
#include "guess.h"
#include <iostream>

GuessingGame::GuessingGame (unsigned int min, int max, unsigned int size) {
    /// @brief  create object for seeding
    std::random_device randomDevice;
    /// @brief create engine and seed it
    std::mt19937 engine{randomDevice()};
    /// @brief  distribution in range [1, max]
    std::uniform_int_distribution<std::mt19937::result_type> dist20(min, max);

    /// @brief Instance Variables
    this->max = max;
    this->size = size;


    /// @brief Generate random numbers for the user to try and guess.
    for (unsigned int i = 0; i < this->size; ++i) {
       /// @brief Implicit conversion - this is changing signedness
        //         but I don't know that it affects the program
        this->randomIntegers.push_back(dist20(engine));
    }
}

/// @brief game play happens here
void GuessingGame::startGuess() {
    /// @brief each game has up to three rounds
    int rounds = 3;
    /// @brief while loops until rounds are depleted or until user wins the game
    while (rounds > 0) {
        unsigned int remainingGuesses = this->size;
        /// @brief Vector to store user guesses
        vector<int> guesses;

        /// @brief Explain the game.
        std::cout << "\nEnter your guesses for the " << this->size
                  << " integer(s) in the range from " << GuessingGame::min
                  << " to " << this->max << "." << std::endl
                  << "\nRounds remaining: " << rounds << std::endl;

        /// @brief store data for one round.
        ///         while loops until guesses are used up.
        while (remainingGuesses > 0) {
            for (unsigned int i = 0; i < this->size; ++i) {
                std::cout << "Guesses remaining: " << remainingGuesses << std::endl
                          << "> ";
                int guess;
                std::cin >> guess;
                /// @brief push into vector
                guesses.push_back(guess);

                --remainingGuesses;
            }///#for
        }///#while

        --rounds;

        /// @brief check for mathces
        unsigned int matches = this->correctAnswers(&guesses);

        //If the user guessed everything correctly, end the game.
        // If the matches is the size, the user guessed everything correctly
        if (matches >= this->size) {
            cout << "You are correct!";
            break;
        } else if (matches != this->size)
            std::cout << "No luck! You matched " << matches
                      << " out of " << size << " guesses." << std::endl;
    }///#while
}///#startGuess


unsigned int GuessingGame::correctAnswers(vector<int> *guesses) {

    /// @brief Copy both vectors to eliminate duplication false positives.
    /// @brief When a correct answer is provided the mathcing element is removed.
    vector<int> unusedGuesses(*guesses);
    vector<int>unmatchedRandomIntegers(this->randomIntegers);

    /// @brief This is a counter for correct answers.
    unsigned int correctGuessCount = 0;

    //Compare every guess to every secret number
    // If there's a match, it's a correct guess.
    //   Increment the count then remove the pair from the storage vectors
    /// @brief
    for (unsigned int i = 0; i < unusedGuesses.size(); i++) {
        for (unsigned int j = 0; j < unmatchedRandomIntegers.size(); j++) {
            //If the guess matches the number, we found a correct guess
            if (unusedGuesses[i] == unmatchedRandomIntegers[j]) {
                //Erase the pair to avoid double count
                unmatchedRandomIntegers.erase(unmatchedRandomIntegers.begin() + j);
                unusedGuesses.erase(unusedGuesses.begin() + i);

                //Decrement i because we removed an element and i is about to be incremented.
                // We actually need to check the same index again.
                // j doesn't need to be decremented because we're about to break out of this loop.
                i--;

                //Increment the guess count; that's the whole point of this
                correctGuessCount++;

                break;
            }
        }
    }
    return correctGuessCount;
}
