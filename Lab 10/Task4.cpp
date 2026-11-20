
#include <iostream>
using namespace std;

// Recursively returns the value at row and col
int pascal(int row, int col) {
    // Base cases
    if (col == 0 || col == row)
        return 1;

    // Recursive case
    return pascal(row - 1, col - 1) + pascal(row - 1, col);
}

// Returns true if the number is even
bool isEven(int number) {
    return (number / 2) * 2 == number;
}

int main() {
    int rows;

    cout << "Enter number of rows: ";
    cin >> rows;

    if (rows <= 0) {
        cout << "Please enter a positive number.";
        return 0;
    }

    cout << "\nPascal's Triangle:" << endl;

    // Generate and display Pascal's Triangle
    for (int i = 0; i < rows; i++) {
        // Print spaces for triangular alignment
        for (int space = 0; space < rows - i - 1; space++) {
            cout << "  ";
        }

        for (int j = 0; j <= i; j++) {
            cout << pascal(i, j) << "   ";
        }

        cout << endl;
    }

    // Analyze the last row
    cout << "\nAnalysis of Last Row:" << endl;
    cout << "\nNumber\t\tParity" << endl;

    int lastRow = rows - 1;

    for (int j = 0; j <= lastRow; j++) {
        int number = pascal(lastRow, j);

        cout << number << "\t\t";

        if (isEven(number))
            cout << "Even";
        else
            cout << "Odd";

        cout << endl;
    }

    return 0;
}
