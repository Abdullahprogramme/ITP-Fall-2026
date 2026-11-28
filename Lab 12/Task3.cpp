
#include <iostream>
#include <string>
using namespace std;

struct CPU {
    string brand;
    string model;
    int cores;
    double clockSpeed;
};

struct Computer {
    string name;
    CPU processor;
    int ram;
    int storage;
};

void displayComputer(const Computer &computer) {
    cout << "\n========== COMPUTER DETAILS ==========\n";

    cout << "\nComputer Name: " << computer.name;

    cout << "\n\nCPU Details:\n";
    cout << "Brand: " << computer.processor.brand << endl;
    cout << "Model: " << computer.processor.model << endl;
    cout << "Cores: " << computer.processor.cores << endl;
    cout << "Clock Speed: " << computer.processor.clockSpeed << " GHz\n";

    cout << "\nRAM: " << computer.ram << " GB\n";
    cout << "Storage: " << computer.storage << " TB\n";
}

int main() {
    Computer computer;

    cout << "Enter Computer Name: ";
    getline(cin, computer.name);

    cout << "\nEnter CPU Details:\n";

    cout << "Brand: ";
    getline(cin, computer.processor.brand);

    cout << "Model: ";
    getline(cin, computer.processor.model);

    cout << "Cores: ";
    cin >> computer.processor.cores;

    cout << "Clock Speed: ";
    cin >> computer.processor.clockSpeed;

    cout << "\nEnter RAM (GB): ";
    cin >> computer.ram;

    cout << "Enter Storage (TB): ";
    cin >> computer.storage;

    displayComputer(computer);

    return 0;
}
