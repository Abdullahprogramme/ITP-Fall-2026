#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int startingMoney, rounds;
    
    cout << "Enter starting money: ";
    cin >> startingMoney;

    cout << "Enter number of rounds: ";
    cin >> rounds;

    int money = startingMoney;

    srand(time(0));

    for (int i = 1; i <= rounds; i++) {
        int randomNumber = rand() % 2;

        if (randomNumber == 1) {
            money++;
        } else {
            money--;
        }
    }

    cout << "\nFinal Money: " << money << endl;

    if (money > startingMoney) {
        cout << "Result: Profit" << endl;
    } else if (money < startingMoney) {
        cout << "Result: Loss" << endl;
    } else {
        cout << "Result: No Change" << endl;
    }

    return 0;
}