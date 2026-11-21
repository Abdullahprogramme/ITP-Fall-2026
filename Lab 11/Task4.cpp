#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void analyzeString(string text) {
    int alphabets = 0;
    int digits = 0;
    int spaces = 0;

    cout << "\nString Analysis:\n";
    cout << "Length: " << text.length() << endl;

    if (text.empty()) {
        cout << "The string is empty.\n";
        return;
    }

    for (int i = 0; i < text.length(); i++) {
        char ch = text.at(i);

        if (isalpha(static_cast<unsigned char>(ch))) {
            alphabets++;
        } else if (isdigit(static_cast<unsigned char>(ch))) {
            digits++;
        } else if (isspace(static_cast<unsigned char>(ch))) {
            spaces++;
        }
    }

    cout << "Alphabetic characters: " << alphabets << endl;
    cout << "Digits: " << digits << endl;
    cout << "Spaces: " << spaces << endl;

    string upperText = text;
    string lowerText = text;

    for (int i = 0; i < text.length(); i++) {
        upperText.at(i) = toupper(static_cast<unsigned char>(upperText.at(i)));

        lowerText.at(i) = tolower(static_cast<unsigned char>(lowerText.at(i)));
    }

    cout << "\nUppercase:\n" << upperText << endl;

    cout << "\nLowercase:\n" << lowerText << endl;
}

void modifyString(string &text) {
    // Append text to the end
    text.append(" - Processed");

    // Insert text at the beginning
    text.insert(0, "START ");

    // Find the first occurrence of "bad"
    size_t position = text.find("bad");

    // Remove it if it exists
    if (position != string::npos) {
        text.erase(position, 3);
    }
}

void searchString(string text, string searchWord) {
    size_t position = text.find(searchWord);

    if (position != string::npos) {
        cout << "\nWord found at position: " << position << endl;
    } else {
        cout << "\nWord not found.\n";
    }

    cout << "\nFirst five characters:\n";

    cout << text.substr(0, 5) << endl;

    string anotherString;

    cout << "\nEnter another string to compare:\n";
    getline(cin, anotherString);

    int result = text.compare(anotherString);

    if (result == 0) {
        cout << "\nStrings are equal.\n";
    } else if (result < 0) {
        cout << "\nFirst string is smaller.\n";
    } else {
        cout << "\nFirst string is greater.\n";
    }
}

int main() {
    string text;
    string searchWord;

    cout << "Enter a sentence:\n";
    getline(cin, text);

    analyzeString(text);

    modifyString(text);

    cout << "\nModified String:\n";
    cout << text << endl;

    cout << "\nEnter a word to search: ";
    getline(cin, searchWord);

    searchString(text, searchWord);

    return 0;
}