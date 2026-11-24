#ifndef COMMIT_H
#define COMMIT_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Commit {
private:
    int id;
    string message;
    string author;
    string timestamp;
    int parentId;
    map<string, vector<string>> snapshot;

public:
    Commit(int commitId, string commitMessage,
           string commitAuthor, string commitTime,
           int parentCommitId);

};

#endif