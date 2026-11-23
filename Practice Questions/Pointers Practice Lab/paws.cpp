#include <iostream>
using namespace std;

int calculateTotal(const int* treats, int count) {
    int total = 0;
    
    for (int i = 0; i < count; i++) {
        total += treats[i];
    }

    return total;
}

void findMostTreats(const int* treats, int count) {
    int bestIndex = 0;

    for (int i = 1; i < count; i++) {
        if (treats[i] > treats[bestIndex]) {
            bestIndex = i;
        }
    }

    cout << "Cat with the most treats: Cat " << bestIndex + 1 << '\n';
    cout << "Treat count: " << treats[bestIndex] << '\n';
}

int main() {
    int numberOfCats;

    do {
        cout << "Enter the number of cats: ";
        cin >> numberOfCats;
    } while (numberOfCats <= 0);

    int* treats = new int[numberOfCats];

    for (int i = 0; i < numberOfCats; i++) {
        do {
            cout << "Enter treats received by cat " << i + 1 << ": ";
            cin >> treats[i];
        } while (treats[i] < 0);
    }

    cout << "\nDaily treat counts: ";
    for (int i = 0; i < numberOfCats; i++) {
        cout << treats[i] << ' ';
    }
    cout << '\n';

    cout << "Total treats: " << calculateTotal(treats, numberOfCats) << '\n';
    findMostTreats(treats, numberOfCats);

    delete[] treats;
    treats = nullptr;

    return 0;
}