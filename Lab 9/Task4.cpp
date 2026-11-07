#include <iostream>
using namespace std;

void rowSums(int mat[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int sum = 0;

        for (int j = 0; j < cols; j++) {
            sum += mat[i][j];
        }

        cout << "Row " << i + 1 << " Sum: " << sum << endl;
    }
}

int main() {
    int matrix[3][3] = {
        {1, 2, 12},
        {4, 5, 9},
        {6, 7, 8}
    };

    rowSums(matrix, 3, 3);

    return 0;
}