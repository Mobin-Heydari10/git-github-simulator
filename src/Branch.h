#ifndef BRANCH_H
#define BRANCH_H

#include <iostream>
#include <string>

using namespace std;

class Branch {
private:
    string name;
    int commitId;

public:
    Branch(string branchName, int lastCommitId);

    string getName();
    int getCommitId();

    void setCommitId(int newCommitId);
};

#endif