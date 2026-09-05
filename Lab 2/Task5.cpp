#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string name;
    int age, idDigit, failedAttempts;

    cout << "Enter student name: ";
    cin >> name;

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter last digit of student ID: ";
    cin >> idDigit;

    cout << "Enter failed attempts: ";
    cin >> failedAttempts;

    string heading = name + " - ACCESS REPORT";

    cout << "\n========================================\n";
    cout << setw(32) << heading << "\n";
    cout << "========================================\n";

    cout << fixed << setprecision(2);

    cout << left << setw(22) << "Age:" << age << "\n";
    cout << setw(22) << "ID Last Digit:" << idDigit << "\n";
    cout << setw(22) << "Failed Attempts:" << failedAttempts << "\n";

    if (age >= 18) {
        if (idDigit / 2 * 2 == idDigit && failedAttempts < 3) {
            int score = age + (idDigit * 10) - (failedAttempts * 5);
            double percentage = (double) score / 150 * 100;

            cout << setw(22) << "Access Status:" << "GRANTED\n";
            cout << setw(22) << "Security Score:" << score << "\n";
            cout << setw(22) << "Score Percentage:" << percentage << "%\n";
        } else {
            cout << setw(22) << "Access Status:" << "DENIED\n";
            cout << setw(22) << "Reason:" << "Security requirements failed\n";
        }
    } else {
        cout << setw(22) << "Access Status:" << "DENIED\n";
        cout << setw(22) << "Reason:" << "Student must be 18 or older\n";
    }

    cout << "========================================\n";

    return 0;
}