#include <iostream>
using namespace std;

int main() {
    double cgpa, attendance;

    cout << "Enter CGPA: ";
    cin >> cgpa;

    cout << "Enter attendance percentage: ";
    cin >> attendance;

    if (cgpa >= 3.5) {
        cout << "\033[32m90% Scholarship\033[0m";
    } else {
        if (cgpa >= 3.0) {
            if (attendance >= 75) {
                cout << "\033[34m80% Scholarship\033[0m";
            } else {
                cout << "\033[33m70% Scholarship\033[0m";
            }
        } else {
            if (cgpa >= 2.5) {
                if (attendance >= 75) {
                    cout << "\033[36m60% Scholarship\033[0m";
                } else {
                    cout << "\033[35m50% Scholarship\033[0m";
                }
            } else {
                cout << "\033[31mNot Eligible\033[0m";
            }
        }
    }

    return 0;
}