#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Event structure to store event information
struct Event {
    string time;
    string description;
};

// Function to add an event to the calendar
void addEvent(vector<Event>& calendar) {
    Event event;
    cout << "Enter time (e.g., 08:00 AM): ";
    cin >> event.time;
    cin.ignore(); // Clear newline character from the buffer
    cout << "Enter event description: ";
    getline(cin, event.description);
    calendar.push_back(event);
    cout << "Event added successfully!" << endl;
}

// Function to display the schedule for the day
void viewSchedule(const vector<Event>& calendar) {
    if (calendar.empty()) {
        cout << "No events scheduled for today." << endl;
    } else {
        cout << "Today's Schedule:" << endl;
        for (const Event& event : calendar) {
            cout << event.time << " - " << event.description << endl;
        }
    }
}

int main() {
    vector<Event> calendar;
    char choice;

    while (true) {
        cout << "Calendar Application Menu:" << endl;
        cout << "1. Add Event" << endl;
        cout << "2. View Schedule" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addEvent(calendar);
                break;
            case '2':
                viewSchedule(calendar);
                break;
            case '3':
                // Save the calendar events to a file before exiting
                {
                    ofstream file("calendar.txt");
                    if (file.is_open()) {
                        for (const Event& event : calendar) {
                            file << event.time << "," << event.description << endl;
                        }
                        file.close();
                        cout << "Calendar events saved to 'calendar.txt'." << endl;
                    } else {
                        cout << "Error: Unable to save calendar events." << endl;
                    }
                }
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
