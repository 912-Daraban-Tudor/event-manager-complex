/*
#include <iostream>
#include <cassert>
#include "Event.h"
#include "Repo.h"
#include "ServiceAdmin.h"

void testEventClass() {
    Event event1("Title 1", "Description 1", Date(28, 5, 2023), Time(30, 12), 10, "Link 1");
    Event event2("Title 2", "Description 2", Date(1, 6, 2023), Time(45, 15), 5, "Link 2");

    Event defaultEvent;
    assert(defaultEvent.getTitle().empty());
    assert(defaultEvent.getDescription().empty());
    assert(defaultEvent.getDate().getDay() == 0);
    assert(defaultEvent.getTime().getMinutes() == 0);
    assert(defaultEvent.getPeopleGoing() == 0);
    assert(defaultEvent.getLink().empty());

    assert(event1.getTitle() == "Title 1");
    assert(event1.getDescription() == "Description 1");
    assert(event1.getDate().getDay() == 28);
    assert(event1.getTime().getMinutes() == 30);
    assert(event1.getPeopleGoing() == 10);
    assert(event1.getLink() == "Link 1");

    assert(event1 == event1);
    assert(!(event1 == event2));

    std::string event1String = event1.toString();
    assert(event1String == event1.toString());

    Event event3;
    event3 = event2;
    assert(event3 == event2);

    std::cout << "USER TEST PASSED" << std::endl;
}


void testRepoClass() {
    Repo repo;


    Event event1("Title 1", "Description 1", Date(28, 5, 2023), Time(30, 12), 10, "Link 1");
    Event event2("Title 2", "Description 2", Date(1, 6, 2023), Time(45, 15), 5, "Link 2");
    repo.addEvent(event1);
    repo.addEvent(event2);

    std::string allEvents = repo.getAll();
    assert(allEvents == "Title: Title 1 | Description: Description 1 | Date: 28/5/2023 | Hour: 30:12 | Atendees:10 | "
                        "Event Link:Link 1\nTitle: Title 2 | Description: Description 2 | Date: 1/6/2023 | Hour: 45:15 "
                        "| Atendees:5 | Event Link:Link 2\n");

    repo.removeEvent(event1);
    allEvents = repo.getAll();
    assert(allEvents == "Title: Title 2 | Description: Description 2 | Date: 1/6/2023 | Hour: 45:15 | Atendees:5 | "
                        "Event Link:Link 2\n");


    repo.removeEventByTitle("Title 2");
    allEvents = repo.getAll();
    assert(allEvents.empty());

    // Test updateEvent
    Event updatedEvent("Title 3", "Updated Description", Date(15, 7, 2023),
                       Time(30, 18), 20, "Link 3");
    repo.addEvent(event1);
    repo.updateEvent(event1, updatedEvent);
    allEvents = repo.getAll();
    assert(allEvents == "Title: Title 3 | Description: Updated Description | Date: 15/7/2023 | Hour: 30:18 "
                        "| Atendees:20 | Event Link:Link 3\n");

    try {
        Event displayedEvent = repo.userDisplayEvent(5);
        assert(displayedEvent == updatedEvent);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    repo.userParticipate(updatedEvent);
    allEvents = repo.getAll();
    assert(allEvents == "Title: Title 3 | Description: Updated Description | Date: 15/7/2023 | Hour: 30:18 "
                        "| Atendees:21 | Event Link:Link 3\n");

    std::cout << "REPO TEST PASSED" << std::endl;
}

void testServiceClass() {
    Repo repoEvents;
    Repo repoUser;

    Service service(repoEvents, repoUser);
    service.removeEvent("Party1", "Place 1", "2/2/2", "2:3", 10, "Link 1");
    service.removeEvent("Party2", "Place 2", "2/2/2", "2:3", 10, "Link 1");
    service.removeEvent("Party3", "Place 3", "2/2/2", "2:3", 10, "Link 1");
    service.removeEvent("Party4", "Place 4", "2/2/2", "2:3", 10, "Link 1");
    service.removeEvent("Party5", "Place 5", "2/2/2", "2:3", 10, "Link 1");
    service.removeEvent("Party6", "Place 6", "2/2/2", "2:3", 10, "Link 1");
    service.removeEvent("Party7", "Place 7", "2/2/2", "2:3", 10, "Link 1");
    service.removeEvent("Party8", "Place 8", "2/2/2", "2:3", 10, "Link 1");
    service.removeEvent("Party9", "Place 9", "2/2/2", "2:3", 10, "Link 1");
    service.removeEvent("Party10", "Place 10", "2/2/2", "2:3", 10, "Link 1");

    service.addEvent("Title 1", "Description 1", "28/5/2023", "30:12", 10, "Link 1");
    service.addEvent("Title 2", "Description 2", "1/6/2023", "45:15", 5, "Link 2");


    std::string allEventsAdmin = service.getAllAdmin();

    assert(allEventsAdmin == "Title: Title 1 | Description: Description 1 | Date: 28/5/2023 | Hour: 30:12 | Atendees:10 | "
                             "Event Link:Link 1\nTitle: Title 2 | Description: Description 2 | Date: 1/6/2023 | Hour: 45:15 "
                             "| Atendees:5 | Event Link:Link 2\n");

    service.removeEvent("Title 1", "Description 1", "28/5/2023", "30:12", 10, "Link 1");

    allEventsAdmin = service.getAllAdmin();
    assert(allEventsAdmin == "Title: Title 2 | Description: Description 2 | Date: 1/6/2023 | Hour: 45:15 "
                             "| Atendees:5 | Event Link:Link 2\n");


    service.updateEvent("Title 2", "Description 2", "New Title", "New Description",
                        "1/6/2023", "45:15", 5, "New Link");
    allEventsAdmin = service.getAllAdmin();
    assert(allEventsAdmin == "Title: New Title | Description: New Description | Date: 1/6/2023 | Hour: 45:15 "
                             "| Atendees:5 | Event Link:New Link\n");


    std::string allEventsUser = service.getAllUser();
    assert(allEventsUser == "");


    Event displayedEvent = service.userDisplayEventNext(6);
    assert(displayedEvent == Event("New Title", "New Description", Date(1, 6, 2023), Time(15, 45), 5, "New Link"));


    service.userParticipate(displayedEvent);
    allEventsUser = service.getAllUser();
    assert(allEventsUser == "Title: New Title | Description: New Description | Date: 1/6/2023 | Hour: 45:15 "
                            "| Atendees:5 | Event Link:New Link\n");


    service.userRemoveParticipation("Title 2", "New Description");
    allEventsUser = service.getAllUser();
    assert(allEventsUser == "Title: New Title | Description: New Description | Date: 1/6/2023 | Hour: 45:15 "
                            "| Atendees:5 | Event Link:New Link\n");

    service.userOpenLink(displayedEvent);

    std::cout << "SERVICE TEST PASSED" << std::endl;
}*/
