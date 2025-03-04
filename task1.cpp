#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

    std::srand(static_cast<unsigned int>(std::time(0)));

    int randomNumber = std::rand() % 100 + 1;
    int userGuess = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a random number between 1 and 100." << std::endl;


    while (userGuess != randomNumber) {
        std::cout << "Please enter your guess: ";
        std::cin >> userGuess;

        if (userGuess < randomNumber) {
            std::cout << "Your guess is too low. Try again!" << std::endl;
        } else if (userGuess > randomNumber) {
            std::cout << "Your guess is too high. Try again!" << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the correct number: " << randomNumber << std::endl;
        }
    }

    return 0;
}