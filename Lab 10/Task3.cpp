
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    // Create the result matrix, initially filled with zeros
    vector<vector<int>> C(rowsA, vector<int>(colsB, 0));

    // Matrix multiplication
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

int main() {
    int rowsA, colsA;
    int rowsB, colsB;

    cout << "Enter rows and columns of Matrix A: ";
    cin >> rowsA >> colsA;

    if (rowsA <= 0 || colsA <= 0) {
        cout << "Invalid dimensions.";
        return 0;
    }

    vector<vector<int>> A(rowsA, vector<int>(colsA));

    cout << "Enter elements of Matrix A:" << endl;

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter rows and columns of Matrix B: ";
    cin >> rowsB >> colsB;

    if (rowsB <= 0 || colsB <= 0) {
        cout << "Invalid dimensions.";
        return 0;
    }

    vector<vector<int>> B(rowsB, vector<int>(colsB));

    cout << "Enter elements of Matrix B:" << endl;

    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            cin >> B[i][j];
        }
    }

    // Check whether multiplication is possible
    if (colsA != rowsB) {
        cout << "Matrix multiplication is not possible.";
        return 0;
    }

    vector<vector<int>> result = multiplyMatrices(A, B);

    cout << "\nProduct Matrix:" << endl;

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
