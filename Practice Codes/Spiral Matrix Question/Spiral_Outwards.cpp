#include <iostream>
using namespace std;

int main() {
    // Fixed size
    const int N = 4;

    // Define a 4x4 matrix where row comes first and column comes second
    int matrix[N][N] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    // These are the directions in order that we want to traverse the matrix: up, right, down, left
    int directions[4][2] = {
        {-1, 0}, // add -1 to row and 0 to column to move up
        {0, 1}, // add 0 to row and 1 to column to move right
        {1, 0}, // add 1 to row and 0 to column to move down
        {0, -1} // add 0 to row and -1 to column to move left
    };

    // Initialize starting position and direction
    int row = N / 2; // Start from the middle of the matrix
    int col = N / 2 - 1;
    int dir = 0;

    // Calculate the number of moves needed to traverse the matrix in a spiral order
    /*
    The number of moves comes from the fact that we need to move N/2 times in the first direction,
    then 1 time in the second direction,
    then N-1 times in the third direction,
    then N-1 times in the fourth direction,
    then N-1 times in the fifth direction,
    and so on until we reach the outside of the matrix.
    */

    const int numberOfMoves = 2 * N - 1;
    int moves[numberOfMoves]; // Array to store the number of moves in each direction

    // Calculate moves dynamically, starting with 1 move in the first direction
    int moveCount = 1;

    // The first move is always 1, then we increase by 1 every two moves
    moves[0] = moveCount;

    for (int i = 1; i < numberOfMoves; i++) {
        if (i == numberOfMoves - 1) {
            moveCount = N - 1;
        } else if (i % 2 == 0) {
            moveCount++;
        } else {
            moveCount = moveCount;
        }

        moves[i] = moveCount;
    }

    // Print starting element
    cout << matrix[row][col] << " ";

    // Outer loop iterates through the number of moves
    for (int move = 0; move < numberOfMoves; move++) {

        // For each move, we iterate through the number of steps in that direction
        for (int steps = 0; steps < moves[move]; steps++) {

            row += directions[dir][0];
            col += directions[dir][1];

            cout << matrix[row][col] << " ";
        }

        // Change direction after completing the steps in the current direction
        dir = (dir + 1) % 4;
    }

    return 0;
}
