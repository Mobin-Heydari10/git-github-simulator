#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

class Repository {
private:
    bool initialized;
    string userName;
    string userEmail;

public:
    Repository();

    void config(string key, string value);

    string getUserName();
    string getUserEmail();
};

#endif