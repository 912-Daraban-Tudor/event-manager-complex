//
// Created by tdara on 5/29/2023.
//

#ifndef A7_912_DARABAN_TUDOR_1_EVENTFILE_H
#define A7_912_DARABAN_TUDOR_1_EVENTFILE_H
#include "Repo.h"
#include "Event.h"

class FileEvent :
public Repo
{
protected:
    std::string filename;
public:
    FileEvent();
    virtual ~FileEvent() {}

    void setFilename(const std::string& filename);
    virtual void writeToFile() = 0;
    virtual void displayEventList() const = 0;
};
#endif //A7_912_DARABAN_TUDOR_1_EVENTFILE_H
