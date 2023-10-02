#pragma once
#ifndef A45_912_DARABAN_TUDOR_REPO_H
#define A45_912_DARABAN_TUDOR_REPO_H
#include "Event.h"
#include <vector>
#include <algorithm>
#include <exception>
#include "eventValidator.h"

class Repo {
private:
    vector<Event> events;
public:
    Repo();
    ~Repo();

    void addEvent(const Event& event);
    void removeEvent(const Event& event);
    void updateEvent(const Event& oldEvent, const Event& newEvent);
    string getAll() const;
    string getLink(Event& event);
    Event userDisplayEvent(int month);
    void userParticipate(Event& event);
    void removeEventByTitle(const string& title);
    void userRemoveParticipation(Event event);
    vector<Event> getEvents() const;
    void generateEvents();
};
#endif //A45_912_DARABAN_TUDOR_REPO_H
