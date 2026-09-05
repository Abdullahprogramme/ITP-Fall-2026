#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int A, B, C;

    cout << "Enter A: ";
    cin >> A;

    cout << "Enter B: ";
    cin >> B;

    cout << "Enter C: ";
    cin >> C;

    // Swap A and B
    A = A + B;
    B = A - B;
    A = A - B;

    // Swap B and C
    B = B + C;
    C = B - C;
    B = B - C;

    // Swap A and C
    A = A + C;
    C = A - C;
    A = A - C;

    int sum = A + B + C;

    double average = (double) sum / 3;

    int largest;

    if (A >= B && A >= C)
        largest = A;
    else if (B >= A && B >= C)
        largest = B;
    else
        largest = C;

    int smallest;

    if (A <= B && A <= C)
        smallest = A;
    else if (B <= A && B <= C)
        smallest = B;
    else
        smallest = C;

    int difference = largest - smallest;

    string heading = "NUMBER " + string("TRANSFORMATION");

    cout << fixed << setprecision(2);

    cout << "\n========================================\n";
    cout << setw(32) << heading << "\n";
    cout << "========================================\n";

    cout << left << setw(22) << "Final A:" << A << "\n";
    cout << setw(22) << "Final B:" << B << "\n";
    cout << setw(22) << "Final C:" << C << "\n";
    cout << setw(22) << "Sum:" << sum << "\n";
    cout << setw(22) << "Average:" << average << "\n";
    cout << setw(22) << "Largest:" << largest << "\n";
    cout << setw(22) << "Smallest:" << smallest << "\n";
    cout << setw(22) << "Difference:" << difference << "\n";

    cout << "========================================\n";

    return 0;
}