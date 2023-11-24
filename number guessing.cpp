#include <iostream>
#include <cstdlib>
#include <ctime>

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void playGame() {
    srand(static_cast<unsigned>(time(0)));

    const int minNumber = 1;
    const int maxNumber = 100;
    const int secretNumber = generateRandomNumber(minNumber, maxNumber);

    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "Try to guess the secret number between " << minNumber << " and " << maxNumber << ".\n\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess == secretNumber) {
            std::cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n";
        } else if (guess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Too high! Try again.\n";
        }

    } while (guess != secretNumber);
}

int main() {
    playGame();
    return 0;
}

