
#include <iostream>
using namespace std;

void insertionSort(int arr[], int size, bool ascending, int start = 1) {

    for (int i = start; i < size; i++) {

        int key = arr[i];

        int j = i - 1;

        while (j >= 0 && (ascending ? arr[j] > key : arr[j] < key)) {

            arr[j + 1] = arr[j];

            j--;
        }

        arr[j + 1] = key;
    }
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {
    int arr[6] = {8, 3, 6, 1, 9, 4};
    int size = 6;
    bool ascending;

    cout << "Sort in ascending order? (1 for Yes, 0 for No): ";
    cin >> ascending;

    insertionSort(arr, size, ascending);

    cout << "Sorted Array:" << endl;
    displayArray(arr, size);

    return 0;
}
