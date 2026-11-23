#include <iostream>
using namespace std;

int countOpenCells(int** map, int rows, int columns) {
    int openCells = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            if (map[r][c] == 1) {
                openCells++;
            }
        }
    }

    return openCells;
}

int main() {
    int rows, columns;

    do {
        cout << "Enter number of rows and columns: ";
        cin >> rows >> columns;
    } while (rows <= 0 || columns <= 0);

    // Allocate the array of row pointers.
    int** map = new int*[rows];

    // Allocate each row separately.
    for (int r = 0; r < rows; r++) {
        map[r] = new int[columns];
    }

    cout << "Enter map values (0 = blocked, 1 = open):\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            do {
                cout << "Cell [" << r << "][" << c << "]: ";
                cin >> map[r][c];
            } while (map[r][c] != 0 && map[r][c] != 1);
        }
    }

    cout << "\nTreasure map:\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            cout << map[r][c] << ' ';
        }

        cout << '\n';
    }

    cout << "Number of open cells: " << countOpenCells(map, rows, columns) << '\n';

    // Free each row before freeing the outer pointer array.
    for (int r = 0; r < rows; r++) {
        delete[] map[r];
        map[r] = nullptr;
    }

    delete[] map;
    map = nullptr;

    return 0;
}