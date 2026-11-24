#include "Repository.h"

Repository::Repository() {
    initialized = false;
    userName = "";
    userEmail = "";
}

void Repository::config(string key, string value) {

    if (key == "user.name") {
        userName = value;
    }

    else if (key == "user.email") {
        userEmail = value;
    }

    else {
        throw runtime_error("Invalid config key!");
    }
}

string Repository::getUserName() {
    return userName;
}

string Repository::getUserEmail() {
    return userEmail;
}
void Repository::init() {

    if (initialized == true) {
        throw runtime_error("Repository already initialized!");
    }

    initialized = true;

    cout << "Initialized empty Git repository." << endl;
}
void Repository::add(string fileName, vector<string> content) {

    if (initialized == false) {
        throw runtime_error("Repository is not initialized!");
    }

    if (fileName.empty()) {
        throw runtime_error("File name cannot be empty!");
    }

    for (int i = 0; i < stagingArea.size(); i++) {

        if (stagingArea[i].fileName == fileName) {

            stagingArea[i].content = content;

            cout << "File updated in staging area." << endl;

            return;
        }
    }

    StagedFile file;

    file.fileName = fileName;
    file.content = content;

    stagingArea.push_back(file);

    cout << "File added to staging area." << endl;
}

vector<StagedFile> Repository::getStagingArea() {
    return stagingArea;
}

void Repository::reset(string fileName) {

    if (initialized == false) {
        throw runtime_error("Repository is not initialized!");
    }

    if (fileName.empty()) {
        throw runtime_error("File name cannot be empty!");
    }

    for (int i = 0; i < stagingArea.size(); i++) {

        if (stagingArea[i].fileName == fileName) {

            stagingArea.erase(stagingArea.begin() + i);

            cout << "File removed from staging area." << endl;

            return;
        }
    }

    throw runtime_error("File not found in staging area!");
}