#include <iostream>
#include <vector>
using namespace std;

void generateSequence(const vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        int current = numbers[i];

        cout << "Sequence for " << current << ": ";

        for (;;) {
            cout << current;

            if (current == 1) {
                break;
            }

            cout << " ";

            if (current % 2 == 0) {
                current = current / 2;
            } else {
                current = 3 * current + 1;
            }
        }

        cout << endl;
    }
}

int main() {
    vector<int> numbers(5);

    cout << "Enter 5 numbers: ";

    for (int i = 0; i < numbers.size(); i++) {
        cin >> numbers[i];
    }

    generateSequence(numbers);

    return 0;
}