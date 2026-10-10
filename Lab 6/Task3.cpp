#include <iostream>
using namespace std;

int main() {

    const int MAX = 100;

    int a[MAX][MAX];
    int m, n;

    cout << "Enter number of rows: ";
    cin >> m;

    cout << "Enter number of columns: ";
    cin >> n;

    cout << "Enter matrix elements:" << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    bool zeroRow[MAX] = {false};
    bool zeroColumn[MAX] = {false};

    // Find rows and columns containing zeroes
    // in the original matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (a[i][j] == 0) {
                zeroRow[i] = true;
                zeroColumn[j] = true;
            }
        }
    }

    // Set the required rows and columns to zero
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (zeroRow[i] || zeroColumn[j]) {
                a[i][j] = 0;
            }
        }
    }

    cout << "Resulting Matrix:" << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}