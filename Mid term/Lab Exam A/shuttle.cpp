#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int arr[N];

    // Input passenger counts
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int currentStart = 0;

    int longestStart = 0;
    int longestEnd = 0;
    int longestLength = 1;

    for (int i = 1; i < N; i++) {

        // If the sequence is no longer increasing,
        // a new streak starts from the current day.
        if (arr[i] <= arr[i - 1]) {
            currentStart = i;
        }

        int currentLength = i - currentStart + 1;

        // Check whether the current streak is the longest
        if (currentLength > longestLength) {
            longestLength = currentLength;
            longestStart = currentStart;
            longestEnd = i;
        }
    }

    cout << "Longest streak: " << longestLength << endl;
    cout << "Days: " << longestStart + 1 << " to " << longestEnd + 1 << endl;

    return 0;
}