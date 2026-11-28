
#include <iostream>
#include <string>
using namespace std;

struct TrainBogey {
    string name;
    int compartmentNumber;
    int capacity;
    TrainBogey* next;
};

int main() {
    // Dynamically create exactly three bogeys
    TrainBogey* first = new TrainBogey;
    TrainBogey* second = new TrainBogey;
    TrainBogey* third = new TrainBogey;

    // Assign values to the first bogey
    first->name = "Bogey 1";
    first->compartmentNumber = 101;
    first->capacity = 50;

    // Assign values to the second bogey
    second->name = "Bogey 2";
    second->compartmentNumber = 102;
    second->capacity = 60;

    // Assign values to the third bogey
    third->name = "Bogey 3";
    third->compartmentNumber = 103;
    third->capacity = 70;

    // Connect the bogeys
    first->next = second;
    second->next = third;
    third->next = nullptr;

    // Head points to the first bogey
    TrainBogey* head = first;

    // Display all three bogeys manually
    cout << "\n========== TRAIN DETAILS ==========\n";

    cout << "\nBogey 1:\n";
    cout << "Name: " << head->name << endl;
    cout << "Compartment Number: " << head->compartmentNumber << endl;
    cout << "Capacity: " << head->capacity << endl;

    cout << "\nBogey 2:\n";
    cout << "Name: " << head->next->name << endl;
    cout << "Compartment Number: " << head->next->compartmentNumber << endl;
    cout << "Capacity: " << head->next->capacity << endl;

    cout << "\nBogey 3:\n";
    cout << "Name: " << head->next->next->name << endl;
    cout << "Compartment Number: " << head->next->next->compartmentNumber << endl;
    cout << "Capacity: " << head->next->next->capacity << endl;

    // Release dynamically allocated memory
    delete head->next->next;
    delete head->next;
    delete head;

    cout << "\nAll bogeys have been released.\n";

    return 0;
}
