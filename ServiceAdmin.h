#pragma once
#ifndef A45_912_DARABAN_TUDOR_SERVICEADMIN_H
#define A45_912_DARABAN_TUDOR_SERVICEADMIN_H
#include "Repo.h"
#include "Event.h"
#include <vector>
#include "EventFile.h"
#include "eventValidator.h"

class Service {
private:
    Repo repo;
    Repo repoUser;
    FileEvent* eventList;
    ValidatorEvent e=ValidatorEvent();
public:
    Service(Repo &repoEvents, Repo &repoUserEvents, FileEvent* fileEvent);
    ~Service();

    void addEvent(const string& title, const string& description, const string& date,
                  const string& time, int peopleGoing, const string& link);
    void removeEvent(const string& title, const string& description, const string& date,
                     const string& time, int peopleGoing, const string& link);
    void updateEvent(const string& oldTitle, const string& oldDescription,
                     const string& title, const string& description, const string& date,
                     const string& time, int peopleGoing, const string& link);

    string getAllAdmin();
    string getAllUser();
    Event userDisplayEventNext(int month);
    void userParticipate(Event event);
    void userRemoveParticipation(const string &title, const string &description);
    vector<Event> getEvents();
    void userOpenLink(Event event);
    void saveEventListToFile(string filename);
    void openEventListInApp();
};


#endif //A45_912_DARABAN_TUDOR_SERVICEADMIN_H
