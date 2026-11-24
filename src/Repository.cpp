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