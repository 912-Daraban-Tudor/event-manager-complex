
#include "Event.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

Event::Event() : title(""), description(""), date(Date()), time(Time()), peopleGoing(0), link("")
{
}

Event::Event(const string& title, const string& description, const Date& date, const Time& time, int peopleGoing,
             const string& link) : title(title), description(description), date(date), time(time),
             peopleGoing(peopleGoing), link(link)
{
    this->title = title;
    this->description = description;
    this->date = date;
    this->time = time;
    this->peopleGoing = peopleGoing;
    this->link = link;
}

bool Event::operator==(const Event & e)
{
    return (this->title == e.title && this->description == e.description);
}

string Event::toString()
{
    return "Title: " + this->title + " | Description: " + this->description + " | Date: " + to_string(this->date.getDay()) + "/" +
           to_string(this->date.getMonth()) + "/" + to_string(this->date.getYear()) + " | Hour: " +
           to_string(this->time.getMinutes()) + ":" + to_string(this->time.getSeconds()) + " | Atendees:" +
           to_string(this->peopleGoing) + " | Event Link:" + this->link;
}

Event& Event::operator=(const Event& other) {
    if (this != &other) {
        title = other.title;
        description = other.description;
        date = other.date;
        time = other.time;
        peopleGoing = other.peopleGoing;
        link = other.link;
    }
    return *this;
}

vector<string> tokensize(string str, char delimiter){
    vector<string> result;
    stringstream ss(str);
    string token;
    while(getline(ss, token, delimiter)){
        result.push_back(token);
    }
    return result;
}

std::istream& operator>>(std::istream& it, Event& e){
    string line;
    getline(it, line);
    vector<string> tokens = tokensize(line, ',');
    if(tokens.size() != 6){
        return it;
    }
    e.title = tokens[0];
    e.description = tokens[1];
    e.date = tokens[2];
    e.time = tokens[3];
    e.peopleGoing = stoi(tokens[4]);
    e.link = tokens[5];
    return it;
}

/*std::ostream& operator<<(std::ostream& ot, const Event& e){
    ot << e.title << "," << e.description << "," << e.date << ","
    << e.time << "," << e.peopleGoing << "," << e.link << "\n";
    return ot;
}*/

std::ostream& operator<<(std::ostream& ot, const Event& e) {
    std::ostringstream ott;
    ott << e.title << "," << e.description << "," << e.date << ","
        << e.time << "," << e.peopleGoing << "," << e.link << "\n";
    ot << ott.str();
    return ot;
}