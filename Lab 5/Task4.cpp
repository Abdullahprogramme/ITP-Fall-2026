#include <iostream>
using namespace std;

int main() {

    int N;

    cout << "N = ";
    cin >> N;

    if (N < 3 || N > 9) {
        cout << "Invalid table size." << endl;
        return 0;
    }

    int countA = 0;
    int countB = 0;
    int countX = 0;

    for (int row = 1; row <= N; row++) {

        for (int column = 1; column <= N; column++) {

            int value = row * column;

            if (value % 3 == 0 && value % 5 == 0) {
                cout << "X\t";
                countX++;
            } else if (value % 3 == 0) {
                cout << "A\t";
                countA++;
            } else if (value % 5 == 0) {
                cout << "B\t";
                countB++;
            } else {
                cout << value << "\t";
            }
        }

        cout << endl;
    }

    cout << "\nA Count = " << countA << endl;
    cout << "B Count = " << countB << endl;
    cout << "X Count = " << countX << endl;

    return 0;
}