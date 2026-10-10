#include <iostream>
using namespace std;

int main() {

    const int SIZE_A = 8;
    const int SIZE_B = 7;

    int sectionA[SIZE_A] = {104, 117, 125, 138, 149, 163, 172, 185};
    int sectionB[SIZE_B] = {109, 125, 131, 149, 158, 172, 194};

    int binaryComparisons = 0;
    int linearComparisons = 0;

    cout << "Duplicate IDs:" << endl;

    for (int i = 0; i < SIZE_B; i++) {

        int target = sectionB[i];

        int low = 0;
        int high = SIZE_A - 1;
        bool foundBinary = false;

        while (low <= high) {

            int mid = (low + high) / 2;
            binaryComparisons++;

            if (sectionA[mid] == target) {
                foundBinary = true;
                break;
            } else if (sectionA[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        bool foundLinear = false;

        for (int j = 0; j < SIZE_A; j++) {

            linearComparisons++;

            if (sectionA[j] == target) {
                foundLinear = true;
                break;
            }
        }

        if (foundBinary && foundLinear) {
            cout << target << " ";
        }
    }

    cout << "\n\nBinary Search Comparisons: " << binaryComparisons << endl;
    cout << "Linear Search Comparisons: " << linearComparisons << endl;

    return 0;
}