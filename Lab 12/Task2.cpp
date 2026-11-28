
#include <iostream>
#include <string>
#include <array>
using namespace std;

struct Player {
    string name;
    int score;
};

double calculateAverage(const array<Player, 5>& players, int size) {
    int total = 0;

    for (int i = 0; i < size; i++) {
        total += players[i].score;
    }

    return static_cast<double>(total) / size;
}

int main() {
    array<Player, 5> players;
    int total = 0;

    cout << "Enter details of five players:\n";

    for (int i = 0; i < 5; i++) {
        cout << "\nPlayer " << i + 1 << ":\n";

        cout << "Name: ";
        cin >> players[i].name;

        cout << "Score: ";
        cin >> players[i].score;
    }

    cout << "\nPlayer Details:\n";

    for (int i = 0; i < 5; i++) {
        cout << players[i].name << " - " << players[i].score << endl;

        total += players[i].score;
    }

    cout << "\nTotal Score: " << total << endl;

    cout << "Average Score: " << calculateAverage(players, 5) << endl;

    return 0;
}