
#include <iostream>
using namespace std;

int fibonacci(int n) {
    // Base cases
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    cout << "Enter number of terms: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive number of terms.";
        return 0;
    }

    cout << "Fibonacci Sequence:" << endl;

    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }

    cout << endl;

    return 0;
}
