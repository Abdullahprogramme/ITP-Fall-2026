#include <iostream>
using namespace std;

int main() {
    const int N = 4;

    int matrix[N][N] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    // Right, Down, Left, Up
    int directions[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };

    int row = 0;
    int col = 0;
    int dir = 0;

    const int numberOfMoves = 2 * N - 1;
    int moves[numberOfMoves];

    // Calculate moves dynamically
    int moveCount = N - 1;

    moves[0] = moveCount;

    for (int i = 1; i < numberOfMoves; i++) {
        moves[i] = moveCount;

        if (i % 2 == 0) {
            moveCount--;
        }
    }

    // Print starting element
    cout << matrix[row][col] << " ";

    for (int i = 0; i < numberOfMoves; i++) {

        for (int j = 0; j < moves[i]; j++) {

            row += directions[dir][0];
            col += directions[dir][1];

            cout << matrix[row][col] << " ";
        }

        dir = (dir + 1) % 4;
    }

    return 0;
}
