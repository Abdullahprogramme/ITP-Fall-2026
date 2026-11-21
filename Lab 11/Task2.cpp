#include <iostream>
using namespace std;

void inputArray(int* arr, int size) {
    cout << "\nEnter " << size << " elements:\n";

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

int calculateSum(int* arr, int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

int* resizeArray(int* arr, int oldSize, int newSize) {
    int* newArr = new int[newSize];

    // Case 1: New size is greater than old size
    if (newSize > oldSize) {
        for (int i = 0; i < oldSize; i++) {
            newArr[i] = arr[i];
        }

        for (int i = oldSize; i < newSize; i++) {
            newArr[i] = 0; // Initialize new elements to 0
        }
    } else { // Case 2: New size is less than or equal to old size
        for (int i = 0; i < newSize; i++) {
            newArr[i] = arr[i];
        }
    }

    delete[] arr; // Free the old array memory
    arr = nullptr; // Avoid dangling pointer
    return newArr;
}

int main() {
    int size;

    cout << "Enter initial array size: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid array size.\n";
        return 0;
    }

    int* numbers = new int[size];

    inputArray(numbers, size);

    cout << "\nOriginal Array:\n";

    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }

    cout << "\n\nSum = " << calculateSum(numbers, size) << endl;

    int choice = 1;

    while (choice == 1) {
        int newSize;

        cout << "\nEnter new array size: ";
        cin >> newSize;

        if (newSize <= 0) {
            cout << "New size must be greater than zero.\n";
            continue;
        }

        numbers = resizeArray(numbers, size, newSize);
        size = newSize;

        cout << "\nUpdated Array:\n";

        for (int i = 0; i < size; i++) {
            cout << numbers[i] << " ";
        }

        cout << "\n\nUpdated Sum = " << calculateSum(numbers, size) << endl;

        cout << "\nDo you want to resize the array again? " << "(1 = Yes, 0 = No): ";

        cin >> choice;
    }

    delete[] numbers;

    cout << "\nMemory released successfully.\n";

    return 0;
}