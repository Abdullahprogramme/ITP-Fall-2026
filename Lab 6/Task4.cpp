#include <iostream>
using namespace std;

int main() {

    const int MAX_SIZE = 10;

    int N;
    cin >> N;

    if (N < 1 || N > MAX_SIZE) {
        return 0;
    }

    int A[MAX_SIZE][MAX_SIZE];
    int B[MAX_SIZE][MAX_SIZE];
    int C[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {

            C[i][j] = 0;

            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << C[i][j] << " ";
        }
        
        cout << endl;
    }

    return 0;
}