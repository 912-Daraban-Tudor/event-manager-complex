//
// Created by tdara on 5/29/2023.
//

#ifndef A7_912_DARABAN_TUDOR_1_HTMLEVENTLIST_H
#define A7_912_DARABAN_TUDOR_1_HTMLEVENTLIST_H

#include "EventFile.h"

class HTMLEventList : public FileEvent {
public:
    void writeToFile() override;
    void displayEventList() const override;
};
#endif //A7_912_DARABAN_TUDOR_1_HTMLEVENTLIST_H
