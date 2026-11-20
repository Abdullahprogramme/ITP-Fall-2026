
#include <iostream>
#include <vector>
using namespace std;

// Takes input into the vector
void inputArray(vector<int>& arr, int size) {
    cout << "Enter " << size << " elements:" << endl;

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

// Displays all vector elements
void displayArray(const vector<int>& arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// Recursive Selection Sort
void sortArray(vector<int>& arr, int size, int start = 0) {
    // Base case: no elements left to sort
    if (start >= size - 1)
        return;

    // Find the smallest element in the unsorted portion
    int minIndex = start;

    for (int i = start + 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    // Place the smallest element at the current position
    int temp = arr[start];
    arr[start] = arr[minIndex];
    arr[minIndex] = temp;

    // Recursively sort the remaining elements
    sortArray(arr, size, start + 1);
}

int main() {
    int size;

    cout << "Enter array size: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid array size.";
        return 0;
    }

    vector<int> arr(size);
    inputArray(arr, size);

    cout << "\nOriginal Array:" << endl;
    displayArray(arr, size);

    sortArray(arr, size);

    cout << "\nSorted Array:" << endl;
    displayArray(arr, size);

    return 0;
}
