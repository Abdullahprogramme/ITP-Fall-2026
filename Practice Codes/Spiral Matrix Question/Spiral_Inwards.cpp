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

    // These are the directions in order that we want to traverse the matrix: right, down, left, ups
    int directions[4][2] = {
        {0, 1}, // add 0 to row and 1 to column to move right
        {1, 0}, // add 1 to row and 0 to column to move down
        {0, -1}, // add 0 to row and -1 to column to move left
        {-1, 0} // add -1 to row and 0 to column to move up
    };

    // Initialize starting position and direction
    int row = 0;
    int col = 0;
    int dir = 0;

    // Calculate the number of moves needed to traverse the matrix in a spiral order
    /*
    The number of moves comes from the fact that we need to move N-1 times in the first direction, 
    then N-1 times in the second direction, 
    then N-1 times in the third direction, 
    then N-2 times in the fourth direction,
    then N-2 times in the fifth direction,
    and so on until we reach the center of the matrix.

    so for example N = 4:
    we move 3 times right, 3 times down, 3 times left, 2 times up, 2 times right, 1 time down, 1 time left = 7 moves
    */

    const int numberOfMoves = 2 * N - 1;
    int moves[numberOfMoves]; // Array to store the number of moves in each direction

    // Calculate moves dynamically, starting with N-1 moves in the first direction and decreasing by 1 every two directions
    int moveCount = N - 1;

    // The first move is always N-1, then we decrease by 1 every two moves
    moves[0] = moveCount;

    for (int i = 1; i < numberOfMoves; i++) {
        moves[i] = moveCount;

        if (i % 2 == 0) {
            moveCount--;
        }
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
        /*
        dir = 0: (0 + 1) % 4 = 1 (down)
        dir = 1: (1 + 1) % 4 = 2 (left)
        dir = 2: (2 + 1) % 4 = 3 (up)
        dir = 3: (3 + 1) % 4 = 0 (right)
        */
       
        dir = (dir + 1) % 4;
    }

    return 0;
}