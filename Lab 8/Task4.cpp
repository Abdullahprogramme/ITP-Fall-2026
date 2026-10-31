#include <iostream>
using namespace std;

void analyzeDigits(int n, int &count, int &sum, double &average) {
    count = 0;
    sum = 0;

    while (n > 0) {
        int digit = n - (n / 10) * 10;

        sum += digit;
        count++;

        n /= 10;
    }

    average = static_cast<double>(sum) / count;
}

int main() {
    int n;
    int count, sum;
    double average;

    cout << "Enter a positive integer: ";
    cin >> n;

    analyzeDigits(n, count, sum, average);

    cout << "Number of digits = " << count << endl;
    cout << "Sum of digits = " << sum << endl;
    cout << "Average of digits = " << average << endl;

    return 0;
}