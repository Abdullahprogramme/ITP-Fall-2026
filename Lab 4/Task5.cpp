#include <iostream>
using namespace std;

int main() {
    int start, end;
    int total = 0;
    int count = 0;

    cout << "Enter starting number: ";
    cin >> start;

    cout << "Enter ending number: ";
    cin >> end;

    for (int i = start; i <= end; i++) {

        cout << "\nNumber: " << i << endl;

        if (i % 7 == 0) {
            cout << "Action: Investigation stopped" << endl;
            break;
        }

        if (i % 3 == 0) {
            cout << "Action: Ignored" << endl;
            continue;
        }

        if (i % 2 == 0) {
            cout << "Action: Accepted - Even" << endl;
        } else {
            cout << "Action: Accepted - Odd" << endl;
        }

        total = total + i;
        count++;

        cout << "Current Total: " << total << endl;
        cout << "Current Count: " << count << endl;
    }

    cout << "\nFinal Total: " << total << endl;
    cout << "Accepted Values: " << count << endl;

    return 0;
}