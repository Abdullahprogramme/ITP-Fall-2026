#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int number;

    cout << "Enter a three-digit number: ";
    cin >> number;

    int hundreds = number / 100;
    int tens = (number - hundreds * 100) / 10;
    int units = number - hundreds * 100 - tens * 10;

    int sum = hundreds + tens + units;
    int product = hundreds * tens * units;

    int swapped = units * 100 + tens * 10 + hundreds;

    string heading = "NUMBER " + string("FORENSICS REPORT");

    cout << "\n========================================\n";
    cout << setw(32) << heading << "\n";
    cout << "========================================\n";

    cout << left << setw(22) << "Original Number:" << number << "\n";
    cout << setw(22) << "Hundreds Digit:" << hundreds << "\n";
    cout << setw(22) << "Tens Digit:" << tens << "\n";
    cout << setw(22) << "Units Digit:" << units << "\n";
    cout << setw(22) << "Digit Sum:" << sum << "\n";
    cout << setw(22) << "Digit Product:" << product << "\n";
    cout << setw(22) << "Swapped Number:" << swapped << "\n";

    if (sum / 2 * 2 == sum)
        cout << setw(22) << "Digit Sum:" << "Even\n";
    else
        cout << setw(22) << "Digit Sum:" << "Odd\n";


        
    if (sum / 3 * 3 == sum)
        cout << setw(22) << "Divisible by 3:" << "Yes\n";
    else
        cout << setw(22) << "Divisible by 3:" << "No\n";

    cout << "========================================\n";

    return 0;
}