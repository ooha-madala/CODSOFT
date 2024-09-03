#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <limits>  // For std::numeric_limits
using namespace std;
void playGame() {
    //Random number generator
    srand(static_cast<unsigned int>(time(0)));
    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess = 0;
    int numberOfGuesses = 0;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "Best Of Luck!" << endl;
    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;
        if (cin.fail()) {
            // Clear the error flag
            cin.clear();
            // Ignore the remaining input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer." << endl;
            continue;
        }
        numberOfGuesses++;
        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the correct number: " << secretNumber << endl;
            cout << "It took you " << numberOfGuesses << " guesses." << endl;
            break;
        }
    }
}

int main() {
    char playAgain = 'y';

    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (cin.fail()) {
            // Clear the error flag
            cin.clear();
            // Ignore the remaining input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Exiting the game." << endl;
            break;
        }

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing!Have a great day" << endl;
    return 0;
}
