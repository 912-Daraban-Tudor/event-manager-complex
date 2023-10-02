
#include "UI.h"
#include "tests.h"
#include <vector>
#include <iostream>
#include "EventFile.h"
#include "CSVEventList.h"
#include "HTMLEventList.h"

using namespace std;

/*int main(){
    testEventClass();
    testRepoClass();
    testServiceClass();
    Repo repo, repoUser;
    Service service(repo, repoUser);
    UI ui(service);
    ui.run();
    return 0;
}*/

int main(){
    cout<<"Choose type of file (CSV/HTML): ";
    string fileType{};
    cin>>fileType;
    if (fileType == "CSV"){
        FileEvent* eventList = new CSVEventList{};
        Repo repo, repoUser;
        Service service(repo, repoUser, eventList);
        string filename{};
        filename="../events.csv";
        UI ui(service, filename);
        ui.run();
        delete eventList;
    }
    else if(fileType == "HTML"){
        FileEvent* eventList = new HTMLEventList{};
        Repo repo, repoUser;
        Service service(repo, repoUser, eventList);
        string filename{};
        filename="../events.html";
        UI ui(service, filename);
        ui.run();
        delete eventList;
    }
}