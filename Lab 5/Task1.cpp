#include <iostream>
using namespace std;

int main() {

    const int SIZE = 8;
    int scores[SIZE] = {72, 85, 61, 90, 77, 68, 85, 94};

    int target;
    cout << "Enter score to search: ";
    cin >> target;

    int minimum = scores[0];
    int maximum = scores[0];
    int total = scores[0];
    int position = -1;

    for (int i = 1; i < SIZE; i++) {

        total += scores[i];

        if (scores[i] < minimum) {
            minimum = scores[i];
        }

        if (scores[i] > maximum) {
            maximum = scores[i];
        }

        if (scores[i] == target && position == -1) {
            position = i;
        }
    }

    double average = (double) total / SIZE;

    cout << "Minimum Score: " << minimum << endl;
    cout << "Maximum Score: " << maximum << endl;
    cout << "Average Score: " << average << endl;

    if (position == -1) {
        cout << "Score not found." << endl;
    }
    else {
        cout << "Score found at index " << position << "." << endl;
    }

    return 0;
}