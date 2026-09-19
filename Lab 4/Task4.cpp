#include <iostream>
using namespace std;

int main() {
    int waitingStudents, maxSeats, maxBags;

    cout << "Enter number of students waiting: ";
    cin >> waitingStudents;

    cout << "Enter maximum number of seats: ";
    cin >> maxSeats;

    cout << "Enter maximum total bags allowed: ";
    cin >> maxBags;

    int studentsBoarded = 0;
    int totalBags = 0;
    int heavyStudents = 0;
    bool seatLimitReached = false;
    bool bagLimitReached = false;

    for (int i = 1; i <= waitingStudents; i++) {

        if (studentsBoarded == maxSeats) {
            seatLimitReached = true;
            break;
        }

        int bags;

        cout << "\nEnter bags for student " << i << ": ";
        cin >> bags;

        if (totalBags + bags > maxBags) {
            bagLimitReached = true;
            break;
        }

        studentsBoarded++;
        totalBags = totalBags + bags;

        if (bags > 2) {
            heavyStudents++;
        }

        cout << "Student Number: " << i << endl;
        cout << "Bags: " << bags << endl;
        cout << "Total Bags: " << totalBags << endl;
        cout << "Students Boarded: " << studentsBoarded << endl;
    }

    cout << "\nTotal Students Boarded: " << studentsBoarded << endl;
    cout << "Total Bags: " << totalBags << endl;
    cout << "Heavy-load Students: " << heavyStudents << endl;

    if (seatLimitReached) {
        cout << "Boarding stopped because of the seat limit." << endl;
    } else if (bagLimitReached) {
        cout << "Boarding stopped because of the bag limit." << endl;
    } else {
        cout << "Boarding completed normally." << endl;
    }

    return 0;
}