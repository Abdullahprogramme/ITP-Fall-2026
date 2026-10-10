#include <iostream>
using namespace std;

int main() {

    const int SIZE = 8;

    int marks[SIZE] = {72, 91, 65, 88, 54, 79, 96, 83};
    char grades[SIZE] = {'C', 'A', 'D', 'B', 'F', 'C', 'A', 'B'};

    cout << "Original Data:" << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << marks[i] << "(" << grades[i] << ") ";
    }

    cout << endl;

    for (int i = 0; i < SIZE - 1; i++) {

        int maxIndex = i;

        for (int j = i + 1; j < SIZE; j++) {

            if (marks[j] > marks[maxIndex]) {
                maxIndex = j;
            }
        }

        if (maxIndex != i) {

            int temp = marks[i];
            marks[i] = marks[maxIndex];
            marks[maxIndex] = temp;

            char tempGrade = grades[i];
            grades[i] = grades[maxIndex];
            grades[maxIndex] = tempGrade;
        }
    }

    cout << "\nSorted Data:" << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << marks[i] << "(" << grades[i] << ") ";
    }

    cout << endl;

    return 0;
}