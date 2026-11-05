#include <iostream>
using namespace std;

int main() {
    int hour;
    int minute;
    int second;

    int alarmHour;
    int alarmMinute;

    cout << "Enter current time (hh mm ss): ";
    cin >> hour >> minute >> second;

    cout << "Enter alarm time (hh mm): ";
    cin >> alarmHour >> alarmMinute;

    int snoozeCount = 0;
    bool finished = false;


    while (!finished) {
        // Advance the clock by one second.
        second++;

        // Handle second -> minute rollover.
        if (second == 60) {
            second = 0;
            minute++;

            // Handle minute -> hour rollover.
            if (minute == 60) {
                minute = 0;
                hour++;

                // Handle midnight rollover.
                if (hour == 24) {
                    hour = 0;
                }
            }
        }

        /*
            Only check the alarm when seconds == 0.

            Without this condition the alarm could ring repeatedly
            throughout the matching minute.
        */
        if (second == 0 && hour == alarmHour && minute == alarmMinute) {
            cout << "BEEP BEEP BEEP! It's ";

            // Print hour with a leading zero when required.
            if (hour < 10) {
                cout << "0";
            }

            cout << hour << ":";

            // Print minute with a leading zero when required.
            if (minute < 10) {
                cout << "0";
            }

            cout << minute << "!" << endl;

            /*
                If the user has already snoozed three times,
                this is the fourth ring.
            */
            if (snoozeCount == 3) {
                cout << "No more snoozing - up you get!" << endl;
                finished = true;
            } else {
                int choice = 0;

                // Continue asking until 1 or 2 is entered.
                while (choice != 1 && choice != 2) {
                    cout << "1) Snooze 2) Wake up: ";
                    cin >> choice;

                    switch (choice) {
                        case 1: {
                            // Count this snooze.
                            snoozeCount++;

                            cout << "Snoozing for five more minutes..." << endl;

                            // Add five minutes to alarm time.
                            alarmMinute += 5;

                            // Handle hour rollover.
                            if (alarmMinute >= 60) {
                                alarmMinute -= 60;
                                alarmHour++;

                                if (alarmHour == 24) {
                                    alarmHour = 0;
                                }
                            }

                            break;
                        } case 2: {
                            cout << "Good morning! You woke up after " << snoozeCount << " snooze(s)." << endl;

                            finished = true;
                            break;
                        } default: {
                            cout << "Invalid choice. Please enter 1 or 2." << endl;
                        }
                    }
                }
            }
        }
    }

    return 0;
}