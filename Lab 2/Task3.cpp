#include <iostream>
using namespace std;

int main() {
    int marks, attendance;

    cout << "Enter marks: ";
    cin >> marks;

    cout << "Enter attendance: ";
    cin >> attendance;

    if ((marks >= 50 && attendance >= 75) || marks >= 80)
        cout << "Student is Eligible.";
    else
        cout << "Student is Not Eligible.";

    return 0;
}