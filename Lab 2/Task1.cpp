#include <iostream>
using namespace std;

int main() {
    int number, guess;

    cout << "Enter a number (1 - 100): ";
    cin >> number;

    if (number >= 1 && number <= 100) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess < number)
            cout << "Your guess is lower than the number.";
        else if (guess > number)
            cout << "Your guess is greater than the number.";
        else
            cout << "Your guess is exactly correct.";
    }
    else {
        cout << "Invalid number. Please enter a number between 1 and 100.";
    }

    return 0;
}