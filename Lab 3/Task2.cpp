#include <iostream>
using namespace std;

int main() {
    int choice;

    cout << "1. Library\n";
    cout << "2. Cafeteria\n";
    cout << "3. Computer Lab\n";
    cout << "4. Student Office\n";

    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Library selected.";
            break;

        case 2:
            cout << "Cafeteria selected.";
            break;

        case 3:
            cout << "Computer Lab selected.";
            break;

        case 4:
            cout << "Student Office selected.";
            break;

        default:
            cout << "Invalid choice.";
    }

    return 0;
}