#include <iostream>
using namespace std;

// Creates a new array, copies the existing records, and returns it.
// The caller is responsible for deleting the old array.
int* resizeArray(const int* oldArray, int size, int newCapacity) {
    int* newArray = new int[newCapacity];

    for (int i = 0; i < size; i++) {
        newArray[i] = oldArray[i];
    }

    return newArray;
}

int main() {
    int* foodRecords = new int[1];
    int size = 0;
    int capacity = 1;
    int choice;

    do {
        cout << "\n1. Add daily food record\n";
        cout << "2. Remove most recent record\n";
        cout << "3. Display records\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int amount;
            cout << "Enter food amount: ";
            cin >> amount;

            // Grow the array when there are no free slots.
            if (size == capacity) {
                int newCapacity = capacity * 2;
                int* biggerArray = resizeArray(foodRecords, size, newCapacity);

                delete[] foodRecords;
                foodRecords = biggerArray;
                capacity = newCapacity;
            }

            foodRecords[size] = amount;
            size++;
        } else if (choice == 2) {
            if (size == 0) {
                cout << "There are no records to remove.\n";
            } else {
                size--;

                // Shrink when the array is at most one-quarter full.
                // Never reduce capacity below one.
                if (capacity > 1 && size <= capacity / 4) {
                    int newCapacity = capacity / 2;

                    if (newCapacity < 1) {
                        newCapacity = 1;
                    }

                    // Ensure the new allocation can hold all valid records.
                    if (newCapacity < size) {
                        newCapacity = size;
                    }

                    int* smallerArray = resizeArray(foodRecords, size, newCapacity);

                    delete[] foodRecords;
                    foodRecords = smallerArray;
                    capacity = newCapacity;
                }

                cout << "Most recent record removed.\n";
            }
        } else if (choice == 3) {
            cout << "Food records: ";
            if (size == 0) {
                cout << "(none)";
            }

            for (int i = 0; i < size; i++) {
                cout << foodRecords[i] << ' ';
            }

            cout << "\nStored records (size): " << size;
            cout << "\nAllocated capacity: " << capacity << '\n';
        } else if (choice != 4) {
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    delete[] foodRecords;
    foodRecords = nullptr;

    return 0;
}