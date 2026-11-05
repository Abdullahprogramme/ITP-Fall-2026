#include <iostream>
using namespace std;

/*
    Direction codes:
        0 = North
        1 = East
        2 = South
        3 = West
*/

int main() {
    // Rover begins at the origin.
    int x = 0;
    int y = 0;

    // Rover initially faces North.
    int direction = 0;

    // Fixed hidden pit location.
    int pitX = -3;
    int pitY = 2;

    // Fixed hidden treasure location.
    int treasureX = 2;
    int treasureY = 3;

    bool missionEnded = false;

    while (!missionEnded) {
        char command;

        cout << "Command: ";
        cin >> command;

        /*
            Convert lowercase letters to uppercase using
            character arithmetic as required.

            ASCII:
            'a' to 'z' are 32 greater than 'A' to 'Z'.
        */
        if (command >= 'a' && command <= 'z') {
            command = command - 32;
        }

        switch (command) {
            case 'F': {
                // Work out the intended new position first.
                int newX = x;
                int newY = y;

                if (direction == 0) {
                    // North increases y.
                    newY++;
                } else if (direction == 1) {
                    // East increases x.
                    newX++;
                } else if (direction == 2) {
                    // South decreases y.
                    newY--;
                } else if (direction == 3) {
                    // West decreases x.
                    newX--;
                }

                /*
                    Check whether the intended move leaves
                    the allowed -5 to 5 coordinate range.
                */
                if (newX < -5 || newX > 5 || newY < -5 || newY > 5) {
                    cout << "Boundary reached." << endl;
                } else {
                    // Commit the legal move.
                    x = newX;
                    y = newY;

                    // Check whether the rover entered the pit.
                    if (x == pitX && y == pitY) {
                        cout << "The rover has fallen into a pit. " << "Mission failed." << endl;

                        missionEnded = true;
                    } else if (x == treasureX && y == treasureY) { // Check whether the rover found the treasure.
                        cout << "Treasure found! Mission successful." << endl;

                        missionEnded = true;
                    }
                }

                break;
            } case 'L': {
                /*
                    Turn left.

                    Adding 3 modulo 4 is equivalent to
                    subtracting 1 without producing negatives.
                */
                direction = (direction + 3) % 4;
                break;
            } case 'R': {
                // Turn right and wrap after West.
                direction = (direction + 1) % 4;
                break;
            } case 'P': {
                cout << "Position: (" << x << ", " << y << ")" << endl;

                cout << "Direction: ";

                // Convert direction code into a readable name.
                switch (direction) {
                    case 0:
                        cout << "North";
                        break;

                    case 1:
                        cout << "East";
                        break;

                    case 2:
                        cout << "South";
                        break;

                    case 3:
                        cout << "West";
                        break;
                }

                cout << endl;

                break;
            } case 'Q': {
                cout << "Mission ended." << endl;
                missionEnded = true;
                break;
            } default: {
                // Invalid commands do not change rover state.
                cout << "Unknown command." << endl;
            }
        }
    }

    // Reveal the hidden locations only after the mission ends.
    cout << "Final map:" << endl;

    /*
        Rows run from y = 5 down to y = -5
        so that North appears at the top.

        Columns run from x = -5 to x = 5.
    */
    for (int mapY = 5; mapY >= -5; mapY--) {
        for (int mapX = -5; mapX <= 5; mapX++) {
            char symbol;

            /*
                If the rover ended on either special square,
                display X instead of P/T/R.
            */
            if (mapX == x && mapY == y && ((x == pitX && y == pitY) || (x == treasureX && y == treasureY))) {
                symbol = 'X';
            } else if (mapX == pitX && mapY == pitY) {
                symbol = 'P';
            } else if (mapX == treasureX && mapY == treasureY) {
                symbol = 'T';
            } else if (mapX == x && mapY == y) {
                symbol = 'R';
            } else {
                symbol = '-';
            }

            cout << symbol;

            // Put spaces between cells.
            if (mapX < 5) {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}