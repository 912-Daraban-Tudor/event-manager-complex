//
// Created by tdara on 5/29/2023.
//

#include "eventValidator.h"
#include "event.h"

ValidationException::ValidationException(std::string message) : message{message} {}

std::string ValidationException::getMessage() const {
    return this->message;
}

ValidationExceptionInherited::ValidationExceptionInherited(std::string message) : message{message} {}

const char *ValidationExceptionInherited::what() const noexcept {
    return message.c_str();
}

void ValidatorEvent::validate(Event e) {
    std::string errors;
    if (e.getTitle().size() < 4)
        errors += std::string("The event title must have at least 4 chars!\n");
    if (e.getDescription().size() < 3)
        errors += std::string("The must gave at least 5 chars!\n");
    if (e.getDate().getMonth() < 1 or e.getDate().getMonth() > 12)
        errors += std::string("The month of the event must be netween 1 and 12!\n");
    if (e.getDate().getDay() < 1 or e.getDate().getDay() > 31)
        errors += std::string("The day must be between 1 and 31!\n");
    if (e.getPeopleGoing() < 0)
        errors += std::string("The number of atendees cannot be less than 0!\n");
    if (e.getLink().find("www") != 0)
        errors += std::string("The link must start with www!\n");

    if (errors.size() > 0)
        throw ValidationException(errors);
}