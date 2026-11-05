#include <iostream>
using namespace std;

int main() {
    int number;

    cout << "Enter a four-digit number: ";
    cin >> number;

    // Keep asking until a valid four-digit number is entered.
    while (true) {
        // Check range first.
        if (number < 1000 || number > 9999) {
            cout << "Invalid input. Enter a four-digit number " << "whose digits are not all identical: ";
            cin >> number;
            continue;
        }

        // Extract the four digits numerically.
        int d1 = number / 1000;
        int d2 = (number / 100) % 10;
        int d3 = (number / 10) % 10;
        int d4 = number % 10;

        // Reject numbers such as 1111, 5555, etc.
        if (d1 == d2 && d2 == d3 && d3 == d4) {
            cout << "Invalid input. Enter a four-digit number whose digits are not all identical: ";
            cin >> number;
            continue;
        }

        break;
    }

    int steps = 0;

    // Correct Kaprekar sequences reach 6174 in at most 7 steps.
    // 15 is used as a safety limit as suggested in the homework.
    while (number != 6174 && steps < 15) {
        // Extract digits of the current number.
        // A value such as 999 is automatically interpreted as 0999.
        int d1 = number / 1000;
        int d2 = (number / 100) % 10;
        int d3 = (number / 10) % 10;
        int d4 = number % 10;

        int temp;

        // Sort the digits into descending order.
        // Three passes over adjacent pairs are enough for four digits.
        for (int pass = 1; pass <= 3; pass++) {
            if (d1 < d2) {
                temp = d1;
                d1 = d2;
                d2 = temp;
            }

            if (d2 < d3) {
                temp = d2;
                d2 = d3;
                d3 = temp;
            }

            if (d3 < d4) {
                temp = d3;
                d3 = d4;
                d4 = temp;
            }
        }

        // Descending arrangement gives the largest value.
        int largest =
            d1 * 1000 +
            d2 * 100 +
            d3 * 10 +
            d4;

        // Reverse the sorted digits for the smallest value.
        int smallest =
            d4 * 1000 +
            d3 * 100 +
            d2 * 10 +
            d1;

        int result = largest - smallest;

        steps++;

        cout << "Step " << steps << ": ";

        // Print largest as four digits.
        if (largest < 1000) cout << "0";
        if (largest < 100) cout << "0";
        if (largest < 10) cout << "0";
        cout << largest;

        cout << " - ";

        // Print smallest with leading zeros when required.
        if (smallest < 1000) cout << "0";
        if (smallest < 100) cout << "0";
        if (smallest < 10) cout << "0";
        cout << smallest;

        cout << " = ";

        // Print result as four digits too.
        if (result < 1000) cout << "0";
        if (result < 100) cout << "0";
        if (result < 10) cout << "0";
        cout << result << endl;

        // The result becomes the next number.
        number = result;
    }

    if (number == 6174) {
        cout << "Reached Kaprekar's constant in " << steps << " steps." << endl;
    }

    return 0;
}