//
// Created by tdara on 5/29/2023.
//

#include <fstream>
#include <windows.h>
#include "CSVEventList.h"
#include "repo.h"

using namespace std;

void CSVEventList::writeToFile() {
    ofstream f(this->filename);

    for (auto t: this->getEvents())
        f << t;
    f.close();
}

void CSVEventList::displayEventList() const {
    string aux = "D:\\Facultate\\OOP\\a7-912-Daraban-Tudor-1\\events.csv";
    ShellExecuteA(
            nullptr,
            "open",
            "C:\\Windows\\system32\\notepad.exe",
            aux.c_str(),
            nullptr,
            SW_SHOWNORMAL
    );
}