/*
Mystery 1:
    int* scorePtr;
    *scorePtr = 250;

Type: Wild pointer.
Reason: scorePtr is uninitialized and does not point to a known object.

Safe correction:
    int score = 250;
    int* scorePtr = &score;
    cout << *scorePtr << '\n';

Mystery 2:
    int* bonusPtr = nullptr;
    *bonusPtr = 50;

Type: Null pointer.
Reason: nullptr represents that the pointer points to no object.
       Dereferencing it is invalid.

Safe correction using dynamic memory:
    int* bonusPtr = new int(50);
    cout << *bonusPtr << '\n';
    delete bonusPtr;
    bonusPtr = nullptr;

Mystery 3:
    int* rewardPtr = new int(100);
    delete rewardPtr;
    cout << *rewardPtr << endl;

Type: Dangling pointer.
Reason: The memory has been released, but rewardPtr still contains
        the old address. Dereferencing it is invalid.

Safe correction:
    int* rewardPtr = new int(100);
    cout << *rewardPtr << '\n';
    delete rewardPtr;
    rewardPtr = nullptr;

The following main function demonstrates all three safe cases.
*/

#include <iostream>
using namespace std;

int main() {
    // Safe use of a pointer to an existing variable.
    int score = 250;
    int* scorePtr = &score;
    cout << "Score: " << *scorePtr << '\n';

    // Safe use of a dynamically allocated integer.
    int* bonusPtr = new int(50);
    cout << "Bonus: " << *bonusPtr << '\n';
    delete bonusPtr;
    bonusPtr = nullptr;

    // Set the pointer to nullptr after deleting its memory.
    int* rewardPtr = new int(100);
    cout << "Reward: " << *rewardPtr << '\n';
    delete rewardPtr;
    rewardPtr = nullptr;

    return 0;
}
