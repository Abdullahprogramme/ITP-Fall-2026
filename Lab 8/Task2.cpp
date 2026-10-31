#include <iostream>
using namespace std;

void printTable(int n = 10) {
    for (int i = 1; i <= n; i++) {
        cout << n << " x " << i << " = " << n * i << endl;
    }
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (n > 10) {
        printTable();
    } else {
        printTable(n);
    }

    return 0;
}