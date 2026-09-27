#include <iostream>
using namespace std;

int main() {

    const int MAX_SIZE = 10;
    int grid[MAX_SIZE][MAX_SIZE];

    int rows, columns;

    cout << "Rows = ";
    cin >> rows;

    cout << "Columns = ";
    cin >> columns;

    if (rows < 1 || rows > MAX_SIZE || columns < 1 || columns > MAX_SIZE) {

        cout << "Invalid grid size." << endl;
        return 0;
    }

    int highRiskTotal = 0;
    bool threeOrMore = false;

    for (int i = 0; i < rows; i++) {

        int rowHighRisk = 0;

        for (int j = 0; j < columns; j++) {

            cin >> grid[i][j];

            if (grid[i][j] >= 7) {
                highRiskTotal++;
                rowHighRisk++;
            }
        }

        if (rowHighRisk >= 3) {
            threeOrMore = true;
        }
    }

    cout << "\nSecurity Grid:" << endl;

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < columns; j++) {
            cout << grid[i][j] << " ";
        }

        cout << endl;
    }

    cout << "\nHigh-Risk Rooms = " << highRiskTotal << endl;

    cout << "Three or More in a Row = ";

    if (threeOrMore) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}