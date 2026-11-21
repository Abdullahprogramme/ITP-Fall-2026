#include <iostream>
using namespace std;

int** createMatrix(int rows, int columns) {
    int** matrix = new int*[rows];

    for (int i = 0; i < rows; i++)
        matrix[i] = new int[columns];

    return matrix;
}

void inputMatrix(int** matrix, int rows, int columns) {
    cout << "\nEnter matrix elements:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            cin >> matrix[i][j];
    }
}

void findRowMaxMin(int** matrix, int rows, int columns, int* evenMax, int* oddMin) {
    int evenIndex = 0;
    int oddIndex = 0;

    for (int i = 0; i < rows; i++) {
        int value = matrix[i][0];

        for (int j = 1; j < columns; j++) {
            if (i % 2 == 0) {
                if (matrix[i][j] > value)
                    value = matrix[i][j];
            } else {
                if (matrix[i][j] < value)
                    value = matrix[i][j];
            }
        }

        if (i % 2 == 0)
            evenMax[evenIndex++] = value;
        else
            oddMin[oddIndex++] = value;
    }
}

void displayResults(int* evenMax, int evenCount, int* oddMin, int oddCount) {
    cout << "\nMaximum values of even-indexed rows:\n";

    for (int i = 0; i < evenCount; i++)
        cout << evenMax[i] << " ";

    cout << "\n\nMinimum values of odd-indexed rows:\n";

    for (int i = 0; i < oddCount; i++)
        cout << oddMin[i] << " ";

    cout << endl;
}

int main() {
    int rows, columns;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> columns;

    if (rows <= 0 || columns <= 0) {
        cout << "Invalid matrix dimensions.\n";
        return 0;
    }

    int** matrix = createMatrix(rows, columns);

    inputMatrix(matrix, rows, columns);

    int evenCount = (rows + 1) / 2;
    int oddCount = rows / 2;

    int* evenMax = new int[evenCount];
    int* oddMin = new int[oddCount];

    findRowMaxMin(matrix, rows, columns, evenMax, oddMin);

    displayResults(evenMax, evenCount, oddMin, oddCount);

    for (int i = 0; i < rows; i++)
        delete[] matrix[i];

    delete[] matrix;

    delete[] evenMax;
    delete[] oddMin;

    return 0;
}