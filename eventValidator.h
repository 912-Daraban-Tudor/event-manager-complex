//
// Created by tdara on 5/29/2023.
//

#ifndef A7_912_DARABAN_TUDOR_1_EVENTVALIDATOR_H
#define A7_912_DARABAN_TUDOR_1_EVENTVALIDATOR_H

#include <string>
#include "event.h"

class ValidationException{
private:
    std::string message;
public:
    ValidationException(std::string message);
    std::string getMessage() const;
};

class ValidationExceptionInherited : public std::exception
{
private:
    std::string message;
public:
    ValidationExceptionInherited(std::string message);
    const char* what() const noexcept override;
};

class ValidatorEvent {
public:
    static void validate(Event e);
};

#endif //A7_912_DARABAN_TUDOR_1_EVENTVALIDATOR_H
