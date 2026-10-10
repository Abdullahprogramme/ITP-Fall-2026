#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int type[N] = {0};
    int hours[N] = {0};

    cout << "Enter number of vehicles (up to " << N << "): ";
    int numVehicles;
    cin >> numVehicles;
    if (numVehicles > N) {
        cout << "Number of vehicles exceeds limit. Setting to " << N << "." << endl;
        numVehicles = N;
    }

    for (int i = 0; i < numVehicles; i++) {
        cout << "Enter type of vehicle (1 for car, 2 for van, 3 for bus): ";
        cin >> type[i];
        cout << "Enter number of hours parked: ";
        cin >> hours[i];
    }

    int total = 0;

    for (int i = 0; i < numVehicles; i++) {
        double fee = 0.0;
        switch (type[i]) {
            case 1: // Car
                fee = hours[i] * 50.0; // 50 Rs per hour
                break;
            case 2: // Van
                fee = hours[i] * 80.0; // 80 Rs per hour
                break;
            case 3: // Bus
                fee = hours[i] * 120.0; // 120 Rs per hour
                break;
            default:
                cout << "Invalid vehicle type." << endl;
                continue;
        }

        if (hours[i] > 5) {
            fee -= fee * 0.1; // 10% discount for more than 5 hours
        }


        total += fee;

        cout << "Vehicle " << (i + 1) << ": Type " << type[i] << ", Hours Parked: " << hours[i] << ", Fee: Rs" << fee << endl;
    }

    cout << "Total Parking Fee: Rs " << total << endl;

    return 0;
}