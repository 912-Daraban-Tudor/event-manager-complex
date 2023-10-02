//
// Created by tdara on 5/29/2023.
//

#include "EventFile.h"

FileEvent::FileEvent() : Repo{}, filename{""}
{}

void FileEvent::setFilename(const std::string& filename) {
    this->filename = filename;
}