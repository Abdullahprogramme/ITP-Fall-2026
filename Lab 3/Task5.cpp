#include <iostream>
using namespace std;

int main() {
    int N, M, L;
    int arrivalTime;
    int lateCount = 0;

    cout << "Enter the number of students (N), the maximum allowed late students (M), and the latest arrival time (L): ";
    cin >> N >> M >> L;

    for (int i = 0; i < N; i++) {
        cout << "Enter the arrival time for student " << (i + 1) << ": ";
        cin >> arrivalTime;

        if (arrivalTime > L) {
            lateCount++;
        }
    }

    if (lateCount > M) {
        cout << "Class is Cancelled";
    } else {
        cout << "Class is Not Cancelled";
    }

    return 0;
}