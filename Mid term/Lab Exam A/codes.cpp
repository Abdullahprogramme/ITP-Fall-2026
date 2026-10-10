#include <iostream>
#include <cctype>
using namespace std;

int main() {
    int n;
    cin >> n;

    int accepted = 0;
    char arr[31];

    for (int i = 0; i < n; i++) {
        cin >> arr;

        bool valid = true;

        // Find length manually
        int length = 0;
        while (arr[length] != '\0') {
            length++;
        }

        // Must have exactly 8 characters
        if (length != 8) {
            valid = false;
        }

        // Only check positions if length is exactly 8
        if (valid) {
            // First three must be uppercase English letters
            if (!(arr[0] >= 'A' && arr[0] <= 'Z'))
                valid = false;

            if (!(arr[1] >= 'A' && arr[1] <= 'Z'))
                valid = false;

            if (!(arr[2] >= 'A' && arr[2] <= 'Z'))
                valid = false;

            // Fourth character must be '-'
            if (arr[3] != '-')
                valid = false;

            // Last four characters must be digits
            for (int j = 4; j <= 7; j++) {
                if (!(arr[j] >= '0' && arr[j] <= '9')) {
                    valid = false;
                }
            }
        }

        // Check final digit rule
        if (valid) {
            int d1 = arr[4] - '0';
            int d2 = arr[5] - '0';
            int d3 = arr[6] - '0';
            int d4 = arr[7] - '0';

            if ((d1 + d2 + d3) % 10 != d4) {
                valid = false;
            }
        }

        if (valid) {
            accepted++;
        }

        cout << arr << ": " << (valid ? "VALID" : "INVALID") << endl;
    }

    cout << "Accepted: " << accepted << endl;

    return 0;
}
