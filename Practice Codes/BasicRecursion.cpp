// Online C++ compiler (editor)
// Write and run C++ online using this editor.

#include <iostream>
#include <array>
using namespace std;

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

bool palin(string character, int n, int curr) {
    if (curr == n / 2) return true;

    if (character[curr] != character[n - 1 - curr]) {
        return false;
    }

    return palin(character, n, curr + 1);
}

int main() {
    int n;
    cin >> n;
    cout << endl << fibonacci(n) << endl;

    array<int, 5> arr = {1, 2, 3, 4, 5};
    for (int num : arr) {
        cout << num << " ";
    }

    cout << endl << "aabaa is palindrome: " << (palin("aabaa", 5, 0) == 0 ? "False" : "True");
}
