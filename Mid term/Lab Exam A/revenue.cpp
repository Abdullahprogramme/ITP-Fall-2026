#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream input("sales.txt");
    ofstream output("ranking.txt");

    if (!input) {
        cout << "Error opening sales.txt";
        return 0;
    }

    int n;
    input >> n;

    int id[100];
    int revenue[100];

    for (int i = 0; i < n; i++) {
        input >> id[i] >> revenue[i];
    }

    // Selection sort
    // Higher revenue first
    // If revenue is same, lower ID first
    for (int i = 0; i < n - 1; i++) {
        int best = i;

        for (int j = i + 1; j < n; j++) {
            if (revenue[j] > revenue[best]) {
                best = j;
            } else if (revenue[j] == revenue[best] && id[j] < id[best]) {
                best = j;
            }
        }

        int temp = revenue[i];
        revenue[i] = revenue[best];
        revenue[best] = temp;

        temp = id[i];
        id[i] = id[best];
        id[best] = temp;
    }

    // Write sorted records to ranking.txt
    for (int i = 0; i < n; i++) {
        output << id[i] << " " << revenue[i] << endl;
    }

    double mean = (static_cast<double>(revenue[0]) + revenue[1]) / 2;

    cout << "Records written: " << n << endl;
    cout << "Top-two mean: " << mean << endl;

    input.close();
    output.close();

    return 0;
}