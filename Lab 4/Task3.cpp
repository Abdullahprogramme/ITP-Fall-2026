#include <iostream>
using namespace std;

int main() {

    int N;
    int factorial = 1;

    cout << "Enter a number: ";
    cin >> N;

    for (int i = 1; i <= N; i++) {
        factorial = factorial * i;
    }

    cout << "Factorial of " << N << ": " << factorial << endl;

    return 0;
}