
#include <iostream>
using namespace std;

struct Rectangle {
    double x1, y1, x2, y2;
};

double calculateArea(Rectangle rect) {
    double width = rect.x2 - rect.x1;
    double height = rect.y2 - rect.y1;

    return width * height;
}

int main() {
    Rectangle rect;

    cout << "Enter x1: ";
    cin >> rect.x1;

    cout << "Enter y1: ";
    cin >> rect.y1;

    cout << "Enter x2: ";
    cin >> rect.x2;

    cout << "Enter y2: ";
    cin >> rect.y2;

    cout << "\nRectangle Coordinates:\n";
    cout << "First Corner: (" << rect.x1 << ", " << rect.y1 << ")\n";

    cout << "Opposite Corner: (" << rect.x2 << ", " << rect.y2 << ")\n";

    cout << "\nArea of Rectangle: " << calculateArea(rect) << endl;

    return 0;
}
