#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    const int MAX_ROWS = 50, MAX_COLS = 100;
    int rows, cols, steps, burnLimit, seed;
    double p, g;
    char wind;
    char forest[MAX_ROWS][MAX_COLS], nextForest[MAX_ROWS][MAX_COLS];
    int age[MAX_ROWS][MAX_COLS] = {};

    ifstream inFile("../data/forest.txt");
    if (!inFile) {
        cout << "Error: could not open ../data/forest.txt\n";
        return 1;
    }

    if (!(inFile >> rows >> cols) || rows < 1 || rows > MAX_ROWS ||
        cols < 1 || cols > MAX_COLS) {
        cout << "Error: invalid or oversized map dimensions.\n";
        inFile.close();
        return 1;
    }

    if (!(inFile >> steps >> p >> g >> burnLimit >> wind >> seed) ||
        steps < 0 || p < 0.0 || p > 1.0 || g < 0.0 || g > 1.0 ||
        burnLimit < 1 || (wind != 'N' && wind != 'S' &&
        wind != 'E' && wind != 'W')) {
        cout << "Error: invalid simulation parameters.\n";
        inFile.close();
        return 1;
    }

    int originalForest = 0;
    int initialBurning = 0;
    for (int r = 0; r < rows; ++r) {
        string rowText;
        if (!(inFile >> rowText)) {
            cout << "Error: map is missing row " << r + 1 << ".\n";
            inFile.close();
            return 1;
        }

        if (static_cast<int>(rowText.length()) != cols) {
            cout << "Error: row " << r + 1 << " has the wrong length.\n";
            inFile.close();
            return 1;
        }

        for (int c = 0; c < cols; ++c) {
            char ch = rowText[c];
            if (!(ch == 'T' || (ch >= '1' && ch <= '9') || ch == 'A' || ch == '.' || ch == '#')) {
                cout << "Error: invalid map symbol '" << ch << "' at row " << r + 1 << ", column " << c + 1 << ".\n";
                inFile.close();
                return 1;
            }

            forest[r][c] = ch;
            if (ch == 'T' || (ch >= '1' && ch <= '9')) ++originalForest;
            if (ch >= '1' && ch <= '9') ++initialBurning;
        }
    }

    inFile.close();
    srand(seed);

    ofstream report("../data/fire_report.txt");
    if (!report) {
        cout << "Error: could not create ../data/fire_report.txt\n";
        return 1;
    }

    // A single writer lambda keeps screen and report output identical.
    auto printMap = [&](ostream& out, char map[MAX_ROWS][MAX_COLS]) {
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) out << map[r][c];
            out << '\n';
        }
    };

    auto countAndPrint = [&](int step, char map[MAX_ROWS][MAX_COLS], ostream& out) {
        int trees = 0, burning = 0, ash = 0;
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c) {
                if (map[r][c] == 'T') ++trees;
                else if (map[r][c] >= '1' && map[r][c] <= '9') ++burning;
                else if (map[r][c] == 'A') ++ash;
            }
        out << "Step " << step << ": Trees: " << trees
            << ", Burning: " << burning << ", Ash: " << ash << '\n';
    };

    cout << "Initial map:\n";
    report << "Initial map:\n";
    printMap(cout, forest);
    printMap(report, forest);

    for (int step = 1; step <= steps; ++step) {
        bool burningAtStart = false;
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c) {
                nextForest[r][c] = forest[r][c];
                if (forest[r][c] >= '1' && forest[r][c] <= '9')
                    burningAtStart = true;
            }
        if (!burningAtStart) break;

        // Spread using only the old map. Track the strongest successful ignition.
        int ignition[MAX_ROWS][MAX_COLS] = {};
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                char source = forest[r][c];
                if (source < '1' || source > '9') continue;
                int intensity = source - '0';

                int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
                int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};
                int neighbours = (intensity == 9) ? 8 : 4;
                
                for (int k = 0; k < neighbours; ++k) {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                        continue;
                    if (forest[nr][nc] != 'T') continue;

                    double probability = p;
                    bool withWind =
                        (wind == 'N' && k == 0) || (wind == 'S' && k == 1) ||
                        (wind == 'W' && k == 2) || (wind == 'E' && k == 3);
                    bool againstWind =
                        (wind == 'S' && k == 0) || (wind == 'N' && k == 1) ||
                        (wind == 'E' && k == 2) || (wind == 'W' && k == 3);
                    if (withWind) probability = (2.0 * p > 1.0) ? 1.0 : 2.0 * p;
                    else if (againstWind) probability = p / 2.0;

                    double randomValue = rand() / (RAND_MAX + 1.0);
                    if (randomValue < probability) {
                        int newIntensity = 1 + rand() % intensity;
                        if (newIntensity > ignition[nr][nc])
                            ignition[nr][nc] = newIntensity;
                    }
                }
            }
        }

        // Resolve all cells after spread attempts; fuel update applies to old burning cells.
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                char old = forest[r][c];
                if (old == 'T' && ignition[r][c] > 0) {
                    nextForest[r][c] = char('0' + ignition[r][c]);
                    age[r][c] = 0;
                } else if (old >= '1' && old <= '9') {
                    int level = old - '0';
                    ++age[r][c];
                    if (age[r][c] >= burnLimit) {
                        nextForest[r][c] = 'A';
                    } else {
                        double randomValue = rand() / (RAND_MAX + 1.0);
                        if (randomValue < g) {
                            if (level < 9) ++level;
                        } else {
                            --level;
                        }
                        if (level <= 0) nextForest[r][c] = 'A';
                        else nextForest[r][c] = char('0' + level);
                    }
                }
            }
        }

        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                forest[r][c] = nextForest[r][c];

        countAndPrint(step, forest, cout);
        countAndPrint(step, forest, report);
    }

    cout << "Final map:\n";
    report << "Final map:\n";
    printMap(cout, forest);
    printMap(report, forest);

    int destroyed = 0;
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
            if (forest[r][c] == 'A') ++destroyed;

    double percent = (originalForest > 0)
        ? 100.0 * destroyed / originalForest : 0.0;
    cout << "Forest destroyed: " << destroyed << " of " << originalForest
         << " (" << fixed << setprecision(2) << percent << "%)\n";
    report << "Forest destroyed: " << destroyed << " of " << originalForest
           << " (" << fixed << setprecision(2) << percent << "%)\n";
    report.close();
    cout << "Report written to ../data/fire_report.txt\n";
    return 0;
}
