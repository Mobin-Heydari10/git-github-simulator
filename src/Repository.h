#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Commit.h"
#include "Branch.h"
using namespace std;

class Repository {
private:
    bool initialized;
    string userName;
    string userEmail;

    vector<StagedFile> stagingArea;
    vector<Commit> commits;

    int nextCommitId;
    int headCommitId;

    vector<Branch> branches;
    string currentBranchName;

public:
    Repository();

    void config(string key, string value);
    string getUserName();
    string getUserEmail();

    void init();

    void add(string fileName, vector<string> content);
    void reset(string fileName);

    vector<StagedFile> getStagingArea();

    void commit(string message);

    vector<Commit> getCommits();
    int getHeadCommitId();

    void status();
    void log();

    void branch(string name = "");
    vector<Branch> getBranches();
};

#endif