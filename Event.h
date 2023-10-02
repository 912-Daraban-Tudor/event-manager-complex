#pragma once
#ifndef A45_912_DARABAN_TUDOR_EVENT_H
#define A45_912_DARABAN_TUDOR_EVENT_H
#include <string>
#include <sstream>

using namespace std;

class Date{
private:
    int day;
    int month;
    int year;
public:
    Date() : day(0), month(0), year(0) {}
    Date(std::string date) {
        size_t pos = date.find('/');
        day = stoi(date.substr(0, pos));
        size_t pos2 = date.find('/', pos + 1);
        month = stoi(date.substr(pos + 1, pos2 - pos - 1));
        year = stoi(date.substr(pos2 + 1, date.length() - pos2 - 1));
    }
    Date(int day, int month, int year) : day(day), month(month), year(year) {}

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    void setDay(int day) { this->day = day;};
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; };
    friend std::ostream& operator<<(std::ostream& os, const Date& date) {
        std::ostringstream oss;
        oss << date.day << "/" << date.month << "/" << date.year;
        os << oss.str();
        return os;
    }
    string toString() const {
        std::ostringstream s;
        s << day << "/" << month << "/" << year;
        return s.str();
    }
};

class Time{
private:
    int minutes;
    int seconds;
public:
    Time() : minutes(0), seconds(0) {}
    Time(std::string time){
        size_t pos = time.find(':');
        minutes = stoi(time.substr(0, pos));
        seconds = stoi(time.substr(pos + 1, time.length() - pos - 1));
    }
    Time(int min, int sec) : minutes(min), seconds(sec) {}

    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }
    void setMinutes(int min) { minutes = min; }
    void getSeconds(int sec) { seconds = sec; }
    string toString() const {
        std::ostringstream s;
        s << minutes << ":" << seconds;
        return s.str();
    }
    friend std::ostream& operator<<(std::ostream& os, const Time& time) {
        std::ostringstream oss;
        oss << time.minutes << "/" << time.seconds;
        os << oss.str();
        return os;
    }
};

class Event {
private:
    string title;
    string description;
    Date date;
    Time time;
    int peopleGoing;
    string link;
public:
    Event();
    Event(const string& title, const string& description, const Date& date, const Time& time,
          int peopleGoing, const string& link);

    string getTitle() const { return title; }
    string getDescription() const { return description; }
    Date getDate() const { return date; }
    string getDateToString() const { return date.toString(); }
    string getTimeToString() const { return time.toString(); }
    Time getTime() const { return time; }
    int getPeopleGoing() const { return peopleGoing; }
    string getLink() const { return link; }

    void setTitle(const string& title) { this->title = title; }
    void setDescription(const string& description) { this->description = description; }
    void setDate(const Date& date) { this->date = date; }
    void setTime(const Time& time) { this->time = time; }
    void setPeopleGoing(int peopleGoing) { if (this->peopleGoing > 0) this->peopleGoing = peopleGoing; }
    void setLink(const string& link) { this->link = link; }

    string toString();

    bool operator==(const Event& e);

    string toString() const;

    Event& operator=(const Event& other);

    friend std::istream& operator>>(std::istream& it, Event& e);

    friend std::ostream& operator<<(std::ostream& ot, const Event& e);
};
#endif //A45_912_DARABAN_TUDOR_EVENT_H
