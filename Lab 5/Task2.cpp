#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    const int SIZE = 8;
    int cards[SIZE] = {10, 20, 30, 40, 50, 60, 70, 80};

    srand(time(0));

    cout << "Original Cards:" << endl;

    for (int k = 0; k < SIZE; k++) {
        cout << cards[k] << " ";
    }

    cout << endl;

    int swaps = 0;
    int i = SIZE - 1;

    while (i > 0) {

        int j = rand() % (i + 1);

        if (i != j) {

            int temp = cards[i];

            cards[i] = cards[j];

            cards[j] = temp;

            swaps += 1;
        }

        i--;
    }

    cout << "\nShuffled Cards:" << endl;

    for (int k = 0; k < SIZE; k++) {
        cout << cards[k] << " ";
    }

    cout << "\nActual Swaps: " << swaps << endl;

    return 0;
}