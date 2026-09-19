#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int rounds;
    int scoreA = 0;
    int scoreB = 0;

    bool aWon = false;
    bool bWon = false;

    cout << "Enter number of rounds: ";
    cin >> rounds;

    srand(time(0));

    for (int i = 1; i <= rounds; i++) {

        int number = rand() % 20 + 1;

        cout << "\nRound: " << i << endl;
        cout << "Generated Number: " << number << endl;
        cout << "Score A Before: " << scoreA << endl;
        cout << "Score B Before: " << scoreB << endl;

        if (number % 2 == 0) {
            scoreA = scoreA + number;

            if (number % 5 == 0) {
                scoreA = scoreA - 2;
            }
        } else {
            scoreB = scoreB + number;

            if (number % 5 == 0) {
                scoreB = scoreB - 2;
            }
        }

        cout << "Score A After: " << scoreA << endl;
        cout << "Score B After: " << scoreB << endl;

        if (scoreA == 20) {
            aWon = true;
            break;
        }

        if (scoreB == 20) {
            bWon = true;
            break;
        }

        if (scoreA > 20) {
            scoreA = 0;
            cout << "Player A's score was reset." << endl;
        }

        if (scoreB > 20) {
            scoreB = 0;
            cout << "Player B's score was reset." << endl;
        }
    }

    cout << "\nFinal Score A: " << scoreA << endl;
    cout << "Final Score B: " << scoreB << endl;

    if (aWon) {
        cout << "Player A won." << endl;
    } else if (bWon) {
        cout << "Player B won." << endl;
    } else {
        cout << "Rounds ended without a winner." << endl;
    }

    return 0;
}