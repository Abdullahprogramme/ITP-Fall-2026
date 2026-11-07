#include <iostream>
using namespace std;

int count7(int n) {
    // Base case
    if (n == 0) {
        return 0;
    }

    // Check the last digit
    if (n % 10 == 7) {
        return 1 + count7(n / 10);
    }

    // Continue checking the remaining digits
    return count7(n / 10);
}

int main() {
    int number;

    cout << "Enter a non-negative integer: ";
    cin >> number;

    cout << "Occurrences of digit 7: " << count7(number) << endl;

    return 0;
}