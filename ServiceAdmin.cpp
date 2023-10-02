
#include "ServiceAdmin.h"
#include <string>
#include <windows.h>
#include "EventFile.h"
#include <iostream>
#include "eventValidator.h"

Service::Service(Repo &repoEvents, Repo &repoUser, FileEvent* eventList) {
    /*
     * Constructor of Service Class, which takes as parameters two Repo objects for admins and users
     * and generates the events
     * */

    this->repo = repoEvents;
    this->repoUser = repoUser;
    this->eventList = eventList;
}

Service::~Service() = default;

void Service::addEvent(const string &title, const string &description, const string &date, const string &time,
                       int peopleGoing, const string& link) {
    /*
     * Add Event function takes all fields of an Event from UI and creates an Event object
     * that is added to the admin repo
     * Function also creates a date and a time object from the strings received as parameters
     * */
    Date date1(date);
    Time time1(time);
    Event event(title, description, date1, time1, peopleGoing, link);
    this->repo.addEvent(event);
}

void Service::removeEvent(const string &title, const string &description, const string &date,
                          const string &time, int peopleGoing, const string &link) {
    /*
     * Function removes an event from the admin repo. It takes all fields of an event object as params
     * and creates an event object that is removed from the repo by calling the removeEvent function
     * */
    Date date1(date);
    Time time1(time);
    Event event(title, description, date1, time1, peopleGoing, link);

    this->repo.removeEvent(event);



}

void Service::updateEvent(const std::string &oldTitle, const std::string &oldDescription, const std::string &titleNew,
                          const std::string &descriptionNew, const std::string &date, const std::string &time,
                          int peopleGoingNew, const std::string &link) {

    /*
     * function takes params all fields of an event obj and creates an event object that is updated with the new fields
     * the old event object is also created and passed as a param to the updateEvent function from repo
     * */
    Date dateNew(date);
    Time timeNew(time);
    Event eventNew(titleNew, descriptionNew, dateNew, timeNew, peopleGoingNew, link);
    Event eventOld(oldTitle, oldDescription, Date(), Time(), 0, "");
    this->repo.updateEvent(eventOld, eventNew);
}



string Service::getAllAdmin() {
    return this->repo.getAll();
}

vector<Event> Service::getEvents() {
    return this->repo.getEvents();
}

string Service::getAllUser() {
    return this->repoUser.getAll();
}


Event Service::userDisplayEventNext(int month) {
    /*
     * Standard user display event function, same as before but no initialization, starting from element at the position
     * this->current
     * */
    return this->repo.userDisplayEvent(month);
}

void Service::userParticipate(Event event) {
    /*
     * The function adds the current event to the user repo and increases the number of people going to the event
     * in the admin repo
     * */
    this->repoUser.addEvent(event);
    this->eventList->addEvent(event);
    this->eventList->writeToFile();
    this->repo.userParticipate(event);
}

void Service::userRemoveParticipation(const string &title, const string &description) {
    /*
     * Function takes all fields of an event object and creates an event object that is removed from the user repo
     * and decreases the number of people going to the event in the admin repo
     * */
    repoUser.removeEventByTitle(title);
    for (auto it : repo.getEvents())
        if (it.getTitle() == title && it.getDescription() == description)
            repo.userRemoveParticipation(Event(title, description, Date(), Time(), 0, ""));
            this->eventList->removeEvent(Event(title, description, Date(), Time(), 0, ""));

}

void Service::userOpenLink(Event event) {
    /*
     * Function takes an event object, extracts the link field and opens the link in the default browser
     * */
    string link = this->repo.getLink(event);
    ShellExecuteA(nullptr, "open", link.c_str(),
                  nullptr, nullptr, SW_SHOWNORMAL);
}

void Service::saveEventListToFile(string filename) {
    if (this->eventList == nullptr)
        return;
    this->eventList->setFilename(filename);
    this->eventList->writeToFile();
}

void Service::openEventListInApp() {
    if (this->eventList == nullptr)
        return;
    this->eventList->displayEventList();
}


