
#include <iostream>
using namespace std;

int ack(int m, int n) {
    // Case 1
    if (m == 0) {
        return n + 1;
    }

    // Case 2
    if (n == 0) {
        return ack(m - 1, 1);
    }

    // Case 3
    return ack(m - 1, ack(m, n - 1));
}

int main() {
    int m, n;

    cout << "Enter m and n: ";
    cin >> m >> n;

    if (m < 0 || m > 3 || n < 0 || n > 7) {
        cout << "Invalid input." << endl;
        cout << "Please enter 0 <= m <= 3 and 0 <= n <= 7.";
        return 0;
    }

    // Display Ackermann values using nested loops
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << "ack(" << i << ", " << j << "): " << ack(i, j) << endl;
        }
    }

    return 0;
}
