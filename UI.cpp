
#include "UI.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

UI::UI(const Service& service, string filename) : service{service}
{
    this->filename = filename;
}

UI::~UI() = default;

void UI::run()
{
    readFromFile();
    try {
        while (true) {
            int command{0};
            cout << "1. Admin mode\n2. User mode\n0. Exit\nInput the command: ";
            cin >> command;
            cin.ignore();
            if (command == 0)
                return;
            switch (command) {
                case 1:
                    adminMode();
                    break;
                case 2:
                    userMode();
                    break;
                default:
                    cout << "Invalid command!\n";
                    break;
            }
        }
    }
    catch (const std::exception& exception) {
        cout << exception.what() << "\n";
    }
}

void UI::adminMode() {
    try {
        while (true) {
            int command{0};
            cout << "1. Add event\n2. Remove event\n3. Update event\n4. Display events\n"
                    "5. Save to file\n0. Exit\nEnter a command: ";
            cin >> command;
            cin.ignore();
            if (command == 0)
                break;
            switch (command) {
                case 1:
                    addEventAdmin();
                    break;
                case 2:
                    removeEventAdmin();
                    break;
                case 3:
                    updateEventAdmin();
                    break;
                case 4:
                    displayEventsAdmin();
                    break;
                case 5:
                    writeToFile();
                    break;
                default:
                    cout << "Invalid command!\n";
                    break;
            }
        }
    }
    catch (const std::exception& exception) {
        cout << exception.what() << "\n";
    }
}

void UI::addEventAdmin() {
    std::string title, description, date, time, link;
    int numberOfPeople;
    cout << "Enter the title: ";
    getline(cin, title);
    cout << "Enter the description: ";
    getline(cin, description);
    cout << "Enter the date (DD/MM/YYYY): ";
    getline(cin, date);
    cout << "Enter the time (HH:MM): ";
    getline(cin, time);
    cout << "Enter the number of people: ";
    cin >> numberOfPeople;
    cin.ignore();
    cout << "Enter the link: ";
    getline(cin, link);
    try
    {
        Event test(title, description, date, time, numberOfPeople, link);
        v.validate(test);
        this->service.addEvent(title, description, date, time, numberOfPeople, link);
    }
    catch (const std::exception& exception)
    {
        cout << exception.what() << "\n";
    }
}

void UI::removeEventAdmin() {
    std::string title, description, date, time, link;
    int numberOfPeople;
    cout << "Enter the title: ";
    getline(cin, title);
    cout << "Enter the description: ";
    getline(cin, description);
    cout << "Enter the date (DD/MM/YYYY): ";
    getline(cin, date);
    cout << "Enter the time (HH:MM): ";
    getline(cin, time);
    cout << "Enter the number of people: ";
    cin >> numberOfPeople;
    cin.ignore();
    cout << "Enter the link: ";
    getline(cin, link);
    try
    {
        this->service.removeEvent(title, description, date, time, numberOfPeople, link);
    }
    catch (const std::exception& exception)
    {
        cout << exception.what() << "\n";
    }
}

void UI::updateEventAdmin() {
    std::string oldTitle, oldDescription, newTitle, newDescription, date, time, link;
    int numberOfPeople;
    cout << "Enter the old title: ";
    getline(cin, oldTitle);
    cout << "Enter the old description: ";
    getline(cin, oldDescription);
    cout << "Enter the new title: ";
    getline(cin, newTitle);
    cout << "Enter the new description: ";
    getline(cin, newDescription);
    cout << "Enter the new date (DD/MM/YYYY): ";
    getline(cin, date);
    cout << "Enter the new time (HH:MM): ";
    getline(cin, time);
    cout << "Enter the new number of people: ";
    cin >> numberOfPeople;
    cin.ignore();
    cout << "Enter the new link: ";
    getline(cin, link);

    try
    {
        this->service.updateEvent(oldTitle, oldDescription, newTitle,
                                  newDescription, date, time, numberOfPeople, link);
    }
    catch (const std::exception& exception)
    {
        cout << exception.what() << "\n";
    }
}

void UI::displayEventsAdmin() {
    string result = this->service.getAllAdmin();
    cout << result;
}


void UI::userMode() {
    try {
        while (true) {
            int command{0};
            cout << "1. Display events\n2. See my events\n3. Remove participation\n4. See event list\n0. Exit\nEnter a command: ";
            cin >> command;
            cin.ignore();
            if (command == 0)
                break;
            switch (command) {
                case 1:
                    int month;
                    cout << "Please enter the month you want to search events for: ";
                    cin >> month;
                    userDisplayEventStart(month);
                    break;
                case 2:
                    userSeeMyEvents();
                    break;
                case 3:
                    userRemoveParticipation();
                    break;
                case 4:
                    userDisplayEventList();
                    break;
                default:
                    cout << "Invalid command!\n";
                    break;
            }
        }
    }
    catch (const std::exception& exception)
    {
        cout << exception.what() << "\n";
    }
}

void UI::userDisplayEventList() {
    this->service.saveEventListToFile(filename);
    this->service.openEventListInApp();

}

void UI::userSeeMyEvents() {
    string result = this->service.getAllUser();
    cout << result;
}

void UI::userRemoveParticipation() {
    std::string title, description;
    int numberOfPeople;
    cout << "Enter the title: ";
    getline(cin, title);
    cout << "Enter the description: ";
    getline(cin, description);

    try
    {
        this->service.userRemoveParticipation(title, description);
    }
    catch (const std::exception& exception)
    {
        cout << exception.what() << "\n";
    }
}

void UI::userDisplayEventStart(int month) {
    try {
        Event event_current = this->service.userDisplayEventNext(month);
        cout << event_current.toString() << "\n";
        while (true) {
            int command{0};
            cout << "1. Display next event\n2. Participate\n3. Open link in browser\n0. Exit\nEnter a command: ";
            cin >> command;
            cin.ignore();

            if (command == 0)
                break;
            switch (command) {
                case 1:
                    event_current = userDisplayEventNext(month);
                    break;
                case 2:
                    userParticipate(event_current);
                    break;
                case 3:
                    this->service.userOpenLink(event_current);
                    break;
                default:
                    cout << "Invalid command!\n";
                    break;
            }
        }
    }
    catch (const std::exception& exception) {
        cout << exception.what() << "\n";
    }
}

Event UI::userDisplayEventNext(int month) {
    Event event = service.userDisplayEventNext(month);
    cout << event.toString() + "\n";
    return event;
}

void UI::userParticipate(Event event) {
    this->service.userParticipate(event);
}

void UI::readFromFile() {
    ifstream file("../events.txt");
    if (!file.is_open())
        printf("Error opening file: %s\n", strerror(errno));
    Event event;
    while (file >> event) {
        try {
            this->service.addEvent(event.getTitle(), event.getDescription(), event.getDateToString(),
                                   event.getTimeToString(), event.getPeopleGoing(), event.getLink());
        }
        catch (const std::exception& exception)
        {
            cout << exception.what() << "\n";
        }
    }
    file.close();
}

void UI::writeToFile() {
    ofstream file("../events.txt", ios::trunc);
    if (!file.is_open())
        printf("Error opening file: %s\n", strerror(errno));
    for (auto event: this->service.getEvents()) {
        file << event;
    }
    file.close();
}