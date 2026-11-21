#include <iostream>
using namespace std;

void updateValue(int* ptr) {
    *ptr = *ptr + 10;
}

void swapValues(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int num1, num2;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    int* ptr1 = &num1;
    int* ptr2 = &num2;

    cout << "\nOriginal Values:\n";
    cout << "First Number: " << num1 << endl;
    cout << "Second Number: " << num2 << endl;

    updateValue(ptr1);

    cout << "\nAfter Updating First Number:\n";
    cout << "First Number: " << num1 << endl;
    cout << "Second Number: " << num2 << endl;

    swapValues(ptr1, ptr2);

    cout << "\nAfter Swapping:\n";
    cout << "First Number: " << num1 << endl;
    cout << "Second Number: " << num2 << endl;

    return 0;
}