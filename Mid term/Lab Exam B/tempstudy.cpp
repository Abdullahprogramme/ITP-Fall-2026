#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream input("temps.txt");

    if (!input) {
        cout << "Error opening temps.txt" << endl;
        return 0;
    }

    int readings[100];
    int count = 0;

    // Read unknown number of readings
    while (count < 100 && input >> readings[count]) {
        count++;
    }

    input.close();

    // Calculate sum
    int sum = 0;

    for (int i = 0; i < count; i++) {
        sum += readings[i];
    }

    double average = static_cast<double>(sum) / count;

    // Count readings above average
    int above = 0;

    for (int i = 0; i < count; i++) {
        if (readings[i] > average) {
            above++;
        }
    }

    // Selection sort - descending
    for (int i = 0; i < count - 1; i++) {
        int maxIndex = i;

        for (int j = i + 1; j < count; j++) {
            if (readings[j] > readings[maxIndex])
            {
                maxIndex = j;
            }
        }

        int temp = readings[i];
        readings[i] = readings[maxIndex];
        readings[maxIndex] = temp;
    }

    // Write result.txt
    ofstream output("result.txt");

    for (int i = 0; i < count; i++) {
        output << readings[i] << " ";
    }

    output << endl;
    output << fixed << setprecision(2);
    output << "Average: " << average << endl;

    output.close();

    // Console output
    cout << fixed << setprecision(2);
    cout << "Average: " << average << endl;
    cout << "Above average: " << above << endl;
    cout << "(result.txt written)" << endl;

    return 0;
}