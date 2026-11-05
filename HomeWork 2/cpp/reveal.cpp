#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const int MAX = 50;
    int rows, cols, secretRows, secretCols;
    int recovered[MAX][MAX], secret[MAX][MAX];

    ifstream stegoFile("../data/stego.txt");
    ifstream secretFile("../data/secret.txt");
    if (!stegoFile) {
        cout << "Error: could not open ../data/stego.txt\n";
        return 1;
    }

    if (!secretFile) {
        cout << "Error: could not open ../data/secret.txt\n";
        stegoFile.close();
        return 1;
    }

    if (!(stegoFile >> rows >> cols) ||
        rows < 1 || rows > MAX || cols < 1 || cols > MAX) {
        cout << "Error: invalid stego dimensions.\n";
        stegoFile.close(); secretFile.close();
        return 1;
    }

    if (!(secretFile >> secretRows >> secretCols) || secretRows < 1 || secretRows > MAX || secretCols < 1 || secretCols > MAX) {
        cout << "Error: invalid secret dimensions.\n";
        stegoFile.close(); secretFile.close();
        return 1;
    }

    if (rows != secretRows || cols != secretCols) {
        cout << "Error: stego and secret dimensions differ.\n";
        stegoFile.close(); secretFile.close();
        return 1;
    }

    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c) {
            int pixel;

            if (!(stegoFile >> pixel)) {
                cout << "Error: stego file has too few or invalid values.\n";
                stegoFile.close(); 
                secretFile.close();
                return 1;
            }

            if (pixel < 0 || pixel > 255) {
                cout << "Error: stego pixel outside 0..255.\n";
                stegoFile.close(); 
                secretFile.close();
                return 1;
            }

            recovered[r][c] = pixel % 2;
        }

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (!(secretFile >> secret[r][c])) {
                cout << "Error: secret file has too few or invalid values.\n";
                stegoFile.close(); 
                secretFile.close();
                return 1;
            }

            if (secret[r][c] != 0 && secret[r][c] != 1) {
                cout << "Error: secret contains a value other than 0 or 1.\n";
                stegoFile.close(); 
                secretFile.close();
                return 1;
            }
        }
    }

    stegoFile.close();
    secretFile.close();

    ofstream outFile("../data/recovered.txt");
    if (!outFile) {
        cout << "Error: could not create ../data/recovered.txt\n";
        return 1;
    }

    outFile << rows << " " << cols << "\n";
    int differences = 0;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (c > 0) outFile << " ";
            outFile << recovered[r][c];
            if (recovered[r][c] != secret[r][c]) ++differences;
        }

        outFile << "\n";
    }

    outFile.close();

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c)
            cout << (recovered[r][c] == 1 ? '#' : ' ');
        cout << '\n';
    }

    if (differences == 0)
        cout << "Secret recovered perfectly (0 of " << rows * cols << " cells differ).\n";
    else
        cout << "Secret recovery differs in " << differences << " of " << rows * cols << " cells.\n";
    cout << "Recovered grid written to ../data/recovered.txt\n";

    return 0;
}
