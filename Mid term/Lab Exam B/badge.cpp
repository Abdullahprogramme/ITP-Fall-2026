#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int checked = 0;
    int accepted = 0;
    int largest = -1;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        // Stop immediately on zero
        if (num == 0) {
            break;
        }

        // Skip negative numbers
        if (num < 0) {
            continue;
        }

        checked++;

        int temp = num;
        int oddSum = 0;
        int evenSum = 0;
        int position = 1;

        while (temp > 0) {
            int digit = temp % 10;

            if (position % 2 == 1) {
                oddSum += digit;
            } else {
                evenSum += digit;
            }

            temp = temp / 10;
            position++;
        }

        int difference = oddSum - evenSum;

        // Absolute value without using a function
        if (difference < 0) {
            difference = -difference;
        }


        if (difference % 3 == 0) {
            accepted++;

            if (largest == -1 || num > largest) {
                largest = num;
            }
        }
    }

    cout << "Checked: " << checked << endl;
    cout << "Accepted: " << accepted << endl;
    cout << "Largest accepted: " << largest << endl;

    return 0;
}
