#include <iostream>
using namespace std;

int square(int n) {
    return n * n;
}

int cube(int n) {
    return n * n * n;
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Square = " << square(n) << endl;
    cout << "Cube = " << cube(n) << endl;

    return 0;
}
