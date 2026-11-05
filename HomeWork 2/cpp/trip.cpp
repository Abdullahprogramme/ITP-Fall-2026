#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    const int MAX_READINGS = 1000;
    int n;
    double time[MAX_READINGS], speed[MAX_READINGS], distance[MAX_READINGS];

    ifstream inFile("../data/trip.txt");
    if (!inFile) {
        cout << "Error: could not open ../data/trip.txt\n";
        return 1;
    }

    if (!(inFile >> n) || n < 1 || n > MAX_READINGS) {
        cout << "Error: invalid number of readings.\n";
        inFile.close();
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        if (!(inFile >> time[i] >> speed[i])) {
            cout << "Error: missing or invalid data at reading " << i + 1 << ".\n";
            inFile.close();
            return 1;
        }

        if (speed[i] < 0) {
            cout << "Error: negative speed at reading " << i + 1 << ".\n";
            inFile.close();
            return 1;
        }

        if (i > 0 && time[i] <= time[i - 1]) {
            cout << "Error: time does not increase at reading " << i + 1 << ".\n";
            inFile.close();
            return 1;
        }
    }

    inFile.close();

    distance[0] = 0.0;
    double hardestAccel = 0.0, hardestBrake = 0.0;
    double accelStart = time[0], accelEnd = time[0];
    double brakeStart = time[0], brakeEnd = time[0];
    double stoppedTime = 0.0;

    for (int i = 0; i < n - 1; ++i) {
        double dt = time[i + 1] - time[i];
        double acceleration = (speed[i + 1] - speed[i]) / dt;
        double intervalDistance = (speed[i] + speed[i + 1]) * 0.5 * dt;
        distance[i + 1] = distance[i] + intervalDistance;

        if (i == 0 || acceleration > hardestAccel) {
            hardestAccel = acceleration;
            accelStart = time[i];
            accelEnd = time[i + 1];
        }

        if (i == 0 || acceleration < hardestBrake) {
            hardestBrake = acceleration;
            brakeStart = time[i];
            brakeEnd = time[i + 1];
        }

        if (speed[i] == 0.0 && speed[i + 1] == 0.0)
            stoppedTime += dt;
    }

    double duration = (n > 1) ? time[n - 1] - time[0] : 0.0;
    double averageSpeed = (duration > 0.0) ? distance[n - 1] / duration : 0.0;

    ofstream report("../data/trip_report.txt");
    if (!report) {
        cout << "Error: could not create ../data/trip_report.txt\n";
        return 1;
    }

    // Print the summary to both the screen and report file.
    ostream* outputs[2] = { &cout, &report };
    for (int k = 0; k < 2; ++k) {
        ostream& out = *outputs[k];
        out << fixed << setprecision(2);
        out << "Trip duration:        " << duration << " s\n";
        out << "Distance travelled:   " << distance[n - 1] << " m\n";

        if (duration > 0.0)
            out << "Average speed:        " << averageSpeed << " m/s\n";
        else
            out << "Average speed:        undefined (zero-duration trip)\n";

        if (n > 1) {
            out << "Hardest acceleration: " << hardestAccel
                << " m/s^2 (between t = " << accelStart << " s and t = "
                << accelEnd << " s)\n";
            out << "Hardest braking:      " << hardestBrake
                << " m/s^2 (between t = " << brakeStart << " s and t = "
                << brakeEnd << " s)\n";
        } else {
            out << "Hardest acceleration: unavailable (one reading)\n";
            out << "Hardest braking:      unavailable (one reading)\n";
        }
        out << "Time fully stopped:   " << stoppedTime << " s\n";
    }

    report << "\nFull distance table:\n";
    report << "time(s) speed(m/s) distance(m)\n";
    report << fixed << setprecision(2);
    for (int i = 0; i < n; ++i)
        report << setw(7) << time[i] << " " << setw(10) << speed[i]
               << " " << setw(12) << distance[i] << "\n";

    report.close();
    cout << "Full distance table written to ../data/trip_report.txt\n";
    
    return 0;
}
