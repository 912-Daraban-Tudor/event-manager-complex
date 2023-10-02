//
// Created by tdara on 5/29/2023.
//

#include "HTMLEventList.h"
#include <fstream>
#include <windows.h>


using namespace std;

void HTMLEventList::writeToFile() {
    ofstream f(this->filename);
    f << "<!DOCTYPE html>\n";
    f << "<html>\n";
    f << "<head>\n";
    f << "  <title>Events</title>\n";
    f << "</head>\n";
    f << "<body>\n";
    f << "<table border=\"1\">\n";
    f << "  <tr>\n";
    f << "      <td>Title</td>\n";
    f << "      <td>Description</td>\n";
    f << "      <td>Date</td>\n";
    f << "      <td>Time</td>\n";
    f << "      <td>People Going</td>\n";
    f << "      <td>Link</td>\n";
    f << "  </tr>\n";
    for (auto t: this->getEvents())
        f << "  <tr>\n" << "        <td>" << t.getTitle() << "</td>\n" << "     <td>" << t.getDescription() << "</td>\n" << "     <td>"
          << t.getDateToString() << "</td>\n" << "     <td>" << t.getTimeToString() << "</td>\n" << "     <td>"
          << t.getPeopleGoing() << "</td>\n" << "     <td>href=\"" << t.getLink() << "\">Link</a></td>\n" << "  </tr>\n";
    f << "</table>\n";
    f << "</body>\n";
    f << "</html>\n";

    f.close();
}

void HTMLEventList::displayEventList() const {
    string aux = "D:\\Facultate\\OOP\\a7-912-Daraban-Tudor-1\\events.html"; // if the path contains spaces, we must put it inside quotations
    ShellExecuteA(nullptr, nullptr, "C:\\Program Files\\Mozilla Firefox\\firefox.exe", aux.c_str(), nullptr,
                  SW_SHOWMAXIMIZED);
}

