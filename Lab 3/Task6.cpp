#include <iostream>
#include <string>
using namespace std;

int main() {
    string code;

    cout << "Enter secret code: ";
    cin >> code;

    char firstCharacter = code[0];
    char lastCharacter = code[code.length() - 1];

    string matchResult;

    if (firstCharacter == lastCharacter) {
        matchResult = "Match";
    } else {
        matchResult = "No Match";
    }

    string verificationLine = string("[Start]") + code + "[End]";

    cout << "First Character: " << firstCharacter << endl;
    cout << "Last Character: " << lastCharacter << endl;
    cout << "Match Result: " << matchResult << endl;
    cout << "Verification Line: " << verificationLine << endl;

    return 0;
}