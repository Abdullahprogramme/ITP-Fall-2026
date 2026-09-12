#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    // generate a random number between 100 and 999
    int token = rand() % 900 + 100;


    cout << "Lucky Token Generator\n\n";
    cout << "Your token number is: " << token;

    return 0;
}