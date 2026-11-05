#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const int MAX = 50;
    int coverRows, coverCols, secretRows, secretCols;
    int cover[MAX][MAX], secret[MAX][MAX];

    ifstream coverFile("../data/cover.txt");
    ifstream secretFile("../data/secret.txt");
    if (!coverFile) {
        cout << "Error: could not open ../data/cover.txt\n";
        return 1;
    }

    if (!secretFile) {
        cout << "Error: could not open ../data/secret.txt\n";
        coverFile.close();
        return 1;
    }

    if (!(coverFile >> coverRows >> coverCols) ||
        coverRows < 1 || coverRows > MAX || coverCols < 1 || coverCols > MAX) {
        cout << "Error: invalid cover dimensions.\n";
        coverFile.close(); 
        secretFile.close();
        return 1;
    }

    if (!(secretFile >> secretRows >> secretCols) ||
        secretRows < 1 || secretRows > MAX || secretCols < 1 || secretCols > MAX) {
        cout << "Error: invalid secret dimensions.\n";
        coverFile.close(); 
        secretFile.close();
        return 1;
    }

    if (coverRows != secretRows || coverCols != secretCols) {
        cout << "Error: cover and secret dimensions differ.\n";
        coverFile.close(); 
        secretFile.close();
        return 1;
    }

    for (int r = 0; r < coverRows; ++r) {
        for (int c = 0; c < coverCols; ++c) {
            if (!(coverFile >> cover[r][c])) {
                cout << "Error: cover file has too few or invalid values.\n";
                coverFile.close(); 
                secretFile.close();
                return 1;
            }

            if (cover[r][c] < 0 || cover[r][c] > 255) {
                cout << "Error: cover value outside 0..255 at cell " << r + 1 << "," << c + 1 << ".\n";
                coverFile.close(); 
                secretFile.close();
                return 1;
            }
        }
    }

    for (int r = 0; r < secretRows; ++r) {
        for (int c = 0; c < secretCols; ++c) {
            if (!(secretFile >> secret[r][c])) {
                cout << "Error: secret file has too few or invalid values.\n";
                coverFile.close(); 
                secretFile.close();
                return 1;
            }

            if (secret[r][c] != 0 && secret[r][c] != 1) {
                cout << "Error: secret value must be 0 or 1 at cell " << r + 1 << "," << c + 1 << ".\n";
                coverFile.close(); 
                secretFile.close();
                return 1;
            }
        }
    }

    coverFile.close();
    secretFile.close();

    int changed = 0;
    for (int r = 0; r < coverRows; ++r) {
        for (int c = 0; c < coverCols; ++c) {
            if (cover[r][c] % 2 != secret[r][c]) {
                // Prefer +1 except at 255; otherwise use -1.
                if (cover[r][c] < 255) ++cover[r][c];
                else --cover[r][c];

                ++changed;
            }
        }
    }

    ofstream outFile("../data/stego.txt");
    if (!outFile) {
        cout << "Error: could not create ../data/stego.txt\n";
        return 1;
    }

    outFile << coverRows << " " << coverCols << "\n";
    for (int r = 0; r < coverRows; ++r) {
        for (int c = 0; c < coverCols; ++c) {
            if (c > 0) outFile << " ";
            outFile << cover[r][c];
        }

        outFile << "\n";
    }

    outFile.close();
    cout << changed << " of " << coverRows * coverCols << " values changed.\n";
    cout << "Stego grid written to ../data/stego.txt\n";

    return 0;
}
