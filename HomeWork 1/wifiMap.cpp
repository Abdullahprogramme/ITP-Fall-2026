#include <iostream>
using namespace std;

int main() {
    int n;

    // Validate grid size.
    while (true) {
        cout << "Enter grid size n (odd, 3 to 15): ";
        cin >> n;

        // Range must be checked first.
        if (n < 3 || n > 15) {
            cout << "n must be between 3 and 15. Please try again." << endl;
        } else if (n % 2 == 0) {
            cout << "n must be an odd number. Please try again." << endl;
        } else {
            // Valid value.
            break;
        }
    }

    // For an odd-sized grid, this is the exact center.
    int center = n / 2;

    // Generate each row.
    for (int row = 0; row < n; row++) {
        // Generate each column.
        for (int col = 0; col < n; col++) {
            int rowDistance;
            int colDistance;

            // Calculate vertical distance without abs().
            if (row >= center) {
                rowDistance = row - center;
            } else {
                rowDistance = center - row;
            }

            // Calculate horizontal distance without abs().
            if (col >= center) {
                colDistance = col - center;
            } else {
                colDistance = center - col;
            }

            // Manhattan distance.
            int signalValue = rowDistance + colDistance;

            cout << signalValue;

            // Add a space except after the final number in the row.
            if (col < n - 1) {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}