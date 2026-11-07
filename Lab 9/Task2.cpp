#include <iostream>
using namespace std;

// Recursive countdown function
void countdown(int n) {
    if (n <= 0) {
        cout << "Liftoff!";
        return;
    }

    cout << n << " ";
    countdown(n - 1);
}

// Recursive factorial function
long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }

    return n * factorial(n - 1);
}

int main() {
    int number;

    cout << "Enter a positive integer: ";
    cin >> number;

    cout << "Countdown: ";
    countdown(number);

    cout << endl;

    cout << "Factorial of " << number << " is: " << factorial(number) << endl;

    return 0;
}