
#include <iostream>
using namespace std;

struct Rectangle {
    int x1, y1, x2, y2;
};

void modifyRectangle(Rectangle* rect1, Rectangle* rect2) {
    int width = rect1->x2 - rect1->x1;
    int height = rect1->y2 - rect1->y1;

    rect2->x2 += width;
    rect2->y2 += height;
}

int main() {
    Rectangle rect1, rect2;

    cout << "Enter First Rectangle Coordinates:\n";
    cout << "x1: ";
    cin >> rect1.x1;
    cout << "y1: ";
    cin >> rect1.y1;
    cout << "x2: ";
    cin >> rect1.x2;
    cout << "y2: ";
    cin >> rect1.y2;

    cout << "\nEnter Second Rectangle Coordinates:\n";
    cout << "x1: ";
    cin >> rect2.x1;
    cout << "y1: ";
    cin >> rect2.y1;
    cout << "x2: ";
    cin >> rect2.x2;
    cout << "y2: ";
    cin >> rect2.y2;

    cout << "\nSecond Rectangle Before Modification:\n";
    cout << "First Corner: (" << rect2.x1 << ", " << rect2.y1 << ")\n";
    cout << "Opposite Corner: (" << rect2.x2 << ", " << rect2.y2 << ")\n";

    modifyRectangle(&rect1, &rect2);

    cout << "\nSecond Rectangle After Modification:\n";
    cout << "First Corner: (" << rect2.x1 << ", " << rect2.y1 << ")\n";
    cout << "Opposite Corner: (" << rect2.x2 << ", " << rect2.y2 << ")\n";

    return 0;
}
