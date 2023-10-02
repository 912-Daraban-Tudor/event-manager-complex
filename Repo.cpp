//
// Created by tdara on 5/14/2023.
//
#include "Repo.h"
#include <string>
#include <stdexcept>

using namespace std;

Repo::Repo() = default;

Repo::~Repo() = default;


void Repo::addEvent(const Event& event) {
    if (find(events.begin(), events.end(), event) != events.end()) {
        throw exception();
    } else {
        events.push_back(event);
    }
}


void Repo::removeEvent(const Event &event) {
    /*
     * Function that removes an event from the repository by use of the find index function of the DynArr class
     * */
    for (auto it = events.begin(); it != events.end(); it++) {
        if (*it == event) {
            events.erase(it);
            break;
        }
    }
}

void Repo::removeEventByTitle(const string &title) {
    /*
     * Function that removes an event from the repository by title
     * */
    for (auto it = events.begin(); it != events.end(); it++) {
        if (it->getTitle() == title) {
            events.erase(it);
            break;
        }
    }
}

void Repo::updateEvent(const Event &oldEvent, const Event &newEvent) {
    /*
     * Function that changes fields of an object in the repo by use of the find index function of the DynArr class
     * */
    for (auto it = events.begin(); it != events.end(); it++) {
        if (*it == oldEvent) {
            *it = newEvent;
            break;
        }
    }
}


string Repo::getAll() const {
    /*
     * Function that returns a string with all the events in the repo
     * */
    string allEvents;
    for (Event event: events) {
        allEvents += event.toString() + "\n";
    }
    return allEvents;
}

string Repo::getLink(Event& event) {
    /*
     * Function that returns the link of an event
     * */
    for (Event &e: events) {
        if (e == event) {
            return e.getLink();
        }
    }
    return nullptr;
}


Event Repo::userDisplayEvent(int month) {
    static size_t lastReturnedPosition = events.size();
    size_t currentPosition = (lastReturnedPosition) % events.size();
    bool found = false;

    for (auto it = events.begin(); it != events.end(); it++) {
        if (it->getDate().getMonth() == month) {
            found = true;
            break;
        }
    }
    if (found) {
        while (true) {
            if (events[currentPosition].getDate().getMonth() == month) {
                lastReturnedPosition = currentPosition + 1;
                return events[currentPosition];
            }
            currentPosition = (currentPosition + 1) % events.size();
        }
    } else {
        throw runtime_error("No events found");
    }
}



void Repo::userParticipate(Event& event) {
        /**
         * Finds the position of the current user accesed event and increases its position
         * */
    auto it = find(events.begin(), events.end(), event);
    it->setPeopleGoing(it->getPeopleGoing()+1);
}

void Repo::userRemoveParticipation(Event event) {
    for (auto it = events.begin(); it != events.end(); it++) {
        if (it->getTitle() == event.getTitle() && it->getDescription() == event.getDescription()) {
            it->setPeopleGoing(it->getPeopleGoing()-1);
            break;
        }
    }
}


vector<Event> Repo::getEvents() const {
    return events;
}

void Repo::generateEvents() {
    // Generate and add 10 events
    for (int i = 0; i < 10; i++) {
        // Create unique event properties
        string title = "Party" + to_string(i + 1);
        string description = "Place " + to_string(i + 1);
        string date = "15/4/2023";  // Set a specific date for all events
        string time = "20:00";       // Set a specific time for all events
        int participants = rand() % 100 + 1;
        string link = "https://youtu.be/5jnZMW8C6wA";

        // Create the event object
        Date dateObj(date);
        Time timeObj(time);
        Event event(title, description, dateObj, timeObj, participants, link);

        // Add the event to the repository
        addEvent(event);
    }
}