#include <iostream>
using namespace std;

int main() {
    int m, n, k;

    cin >> m >> n >> k;

    int grid[100][100];
    int result[100][100];

    // Read grid
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Handle k values larger than number of columns
    k = k % n;

    // Shift each row right by k positions
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int newPosition = (j + k) % n;
            result[i][newPosition] = grid[i][j];
        }
    }

    // Display result
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++){
            cout << result[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}