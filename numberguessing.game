#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    std::srand(std::time(0));
    
    // Generate a random number between 1 and 100
    int target = std::rand() % 100 + 1;
    int guess = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I have picked a number between 1 and 100. Try to guess it!\n";

    // Loop until the user guesses the correct number
    while (guess != target) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (guess < target) {
            std::cout << "Too low! Try again.\n";
        } else if (guess > target) {
            std::cout << "Too high! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the number.\n";
        }
    }

    return 0;
}
