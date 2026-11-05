#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    const int ROWS = 20, COLS = 80;
    char grid[ROWS][COLS];
    double xmin, xmax;

    cout << "Enter xmin and xmax (radians): ";
    if (!(cin >> xmin >> xmax) || !(xmin < xmax)) {
        cout << "Error: enter two valid numbers with xmin < xmax.\n";
        return 1;
    }

    for (int r = 0; r < ROWS; ++r)
        for (int c = 0; c < COLS; ++c)
            grid[r][c] = ' ';

    int middleRow = ROWS / 2;
    int middleCol = COLS / 2;

    for (int c = 0; c < COLS; ++c)
        grid[middleRow][c] = '-';

    for (int r = 0; r < ROWS; ++r)
        grid[r][middleCol] = '|';

    grid[middleRow][middleCol] = '+';

    for (int c = 0; c < COLS; ++c) {
        double x = xmin + c * (xmax - xmin) / (COLS - 1);
        double y = sin(x);
        int row = static_cast<int>(round((1.0 - y) / 2.0 * (ROWS - 1)));
        if (row < 0) row = 0;
        if (row >= ROWS) row = ROWS - 1;
        grid[row][c] = '*';
    }

    ofstream plot("../data/plot.txt");
    if (!plot) {
        cout << "Error: could not create ../data/plot.txt\n";
        return 1;
    }

    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            cout << grid[r][c];
            plot << grid[r][c];
        }

        cout << '\n';
        plot << '\n';
    }

    plot.close();
    cout << "Plot saved to ../data/plot.txt\n";
    
    return 0;
}
