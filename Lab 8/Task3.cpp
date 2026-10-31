#include <iostream>
using namespace std;

void inputUnits(int units[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter units for House " << i + 1 << ": ";
        cin >> units[i];
    }
}

void calculateBills(int units[], double bills[], int n) {
    for (int i = 0; i < n; i++) {
        double bill = 0;

        if (units[i] <= 100) {
            bill = units[i] * 10.0;
        } else if (units[i] <= 200) {
            bill = 100 * 10.0 + (units[i] - 100) * 17.5;
        } else {
            bill = 100 * 10.0 + 100 * 17.5 + (units[i] - 200) * 26.5;
        }

        double discount;

        if (units[i] % 2 == 0) {
            discount = 7.5;
        } else {
            discount = 2.5;
        }

        bills[i] = bill - (bill * discount / 100.0);
    }
}

void displayBills(double bills[], int n) {
    cout << "\nElectricity Bills:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "House " << i + 1 << ": Rs. " << bills[i] << endl;
    }
}

int main() {
    int n;

    cout << "Enter number of houses: ";
    cin >> n;

    int units[n];
    double bills[n];

    inputUnits(units, n);
    calculateBills(units, bills, n);
    displayBills(bills, n);

    return 0;
}