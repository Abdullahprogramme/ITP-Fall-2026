#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int scores[5];

    cout << "Enter 5 exam scores: ";
    for (int i = 0; i < 5; i++) {
        cin >> scores[i];
    }

    // Write scores to the file
    ofstream outFile("scores.txt");

    if (!outFile) {
        cout << "Unable to open file for writing." << endl;
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        outFile << scores[i] << endl;
    }

    outFile.close();

    cout << "Scores successfully written to scores.txt." << endl;

    // Read scores from the file
    ifstream inFile("scores.txt");

    if (!inFile) {
        cout << "Unable to open file for reading." << endl;
        return 1;
    }

    int score;
    int count = 0;
    double average = 0.0;

    cout << "Reading scores from file: ";

    while (inFile >> score) {
        cout << score << " ";

        count++;

        // Update the running average
        average = average + (score - average) / count;
    }

    inFile.close();

    cout << endl;
    cout << "Average Score: " << average << endl;

    return 0;
}