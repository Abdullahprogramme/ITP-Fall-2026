#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int value;

    cout << "Enter integers, -1 to end: ";
    cin >> value;

    // Special case: the first value is the sentinel.
    if (value == -1) {
        cout << "The stream is empty." << endl;
        return 0;
    }

    // The first input begins the first run.
    int currentValue = value;
    int runLength = 1;
    int originalCount = 1;
    int compressedCount = 0;

    // Read the rest of the stream.
    while (true) {
        cin >> value;

        // -1 terminates the input and is not part of the stream.
        if (value == -1) {
            break;
        }

        originalCount++;

        if (value == currentValue) {
            runLength++;
        } else {
            // Previous run is complete.
            if (compressedCount == 0) {
                cout << "Compressed output:" << endl;
            }

            cout << "[" << runLength << " x " << currentValue << "] ";
            compressedCount++;

            // Start a new run.
            currentValue = value;
            runLength = 1;
        }
    }

    // If no run has been printed yet, print the heading now.
    if (compressedCount == 0) {
        cout << "Compressed output:" << endl;
    }

    // Print the final run.
    cout << "[" << runLength << " x " << currentValue << "]";
    compressedCount++;

    cout << endl;

    // Calculate percentage reduction.
    double reduction = (static_cast<double>(originalCount - compressedCount) / originalCount) * 100.0;

    cout << "Original values      : " << originalCount << endl;
    cout << "Compressed entries   : " << compressedCount << endl;

    cout << fixed << setprecision(2);
    cout << "Reduction            : " << reduction << "%" << endl;

    return 0;
}