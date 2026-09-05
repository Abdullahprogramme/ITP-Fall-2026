#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;

    cout << "Enter your name: ";
    cin >> name;

    cout << "\n--------------------------------\n";
    cout << "       STUDENT INTRODUCTION\n";
    cout << "--------------------------------\n";
    cout << "Welcome, " << name << "!\n";
    cout << "You are now part of the class.\n";
    cout << "--------------------------------\n";

    return 0;
}