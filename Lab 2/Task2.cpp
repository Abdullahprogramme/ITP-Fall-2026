#include <iostream>
using namespace std;

int main() {
    int year;

    cout << "Enter year: ";
    cin >> year;

    string result = (year % 4 == 0)
                    ? ((year % 100 == 0)
                       ? ((year % 400 == 0) ? "Leap Year" : "Not a Leap Year")
                       : "Leap Year")
                    : "Not a Leap Year";

    cout << year << " is a " << result << ".";

    return 0;
}