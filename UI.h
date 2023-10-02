#pragma once

#ifndef A45_912_DARABAN_TUDOR_UI_H
#define A45_912_DARABAN_TUDOR_UI_H
#include "ServiceAdmin.h"
#include "eventValidator.h"
class UI{
private:
    Service service;
    string filename;
    ValidatorEvent v=ValidatorEvent();
public:
    UI(const Service& service, string filename);
    ~UI();

    void run();
    void adminMode();
    void userMode();
    void addEventAdmin();
    void removeEventAdmin();
    void updateEventAdmin();
    void displayEventsAdmin();
    void userDisplayEventStart(int month);
    Event userDisplayEventNext(int month);
    void userSeeMyEvents();
    void userParticipate(Event event);
    void userRemoveParticipation();
    void userDisplayEventList();
    void readFromFile();
    void writeToFile();


};
#endif //A45_912_DARABAN_TUDOR_UI_H
