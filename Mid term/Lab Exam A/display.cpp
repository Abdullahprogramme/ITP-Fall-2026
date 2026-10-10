#include <iostream>
using namespace std;

int main() {
    const int N = 3;
    int arr[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // rotating 90 degrees clockwise, in place
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int temp = arr[i][j]; // store the top element
            arr[i][j] = arr[N - j - 1][i]; // move left to top
            arr[N - j - 1][i] = arr[N - i - 1][N - j - 1]; // move bottom to left
            arr[N - i - 1][N - j - 1] = arr[j][N - i - 1]; // move right to bottom
            arr[j][N - i - 1] = temp; // move top to right
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int sum = 0;
    for (int i = 0, j = 0; i < N, j < N; i++, j++) {
        sum += arr[i][j];
    }

    cout << "Sum of diagonal elements: " << sum << endl;

    return 0;
}