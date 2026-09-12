#include <iostream>
using namespace std;

int main() {
    int counter;
    int result1, result2, result3;

    cout << "Enter initial visitor count: ";
    cin >> counter;

    result1 = counter++;

    cout << "\nAfter post-increment:\n";
    cout << "Stored Value: " << result1 << endl;
    cout << "Counter Value: " << counter << endl;

    result2 = ++counter;

    cout << "\nAfter pre-increment:\n";
    cout << "Stored Value: " << result2 << endl;
    cout << "Counter Value: " << counter << endl;

    result3 = counter++;

    cout << "\nAfter post-increment:\n";
    cout << "Stored Value: " << result3 << endl;
    cout << "Counter Value: " << counter << endl;

    return 0;
}