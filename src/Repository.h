#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

struct StagedFile {
    string fileName;
    vector<string> content;
};

class Repository {
private:
    bool initialized;
    string userName;
    string userEmail;

    vector<StagedFile> stagingArea;

public:
    Repository();

    void config(string key, string value);

    string getUserName();
    string getUserEmail();

    void init();
    
    void add(string fileName, vector<string> content);

    vector<StagedFile> getStagingArea();
};

#endif