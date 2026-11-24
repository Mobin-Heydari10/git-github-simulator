#ifndef COMMIT_H
#define COMMIT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct StagedFile {
    string fileName;
    vector<string> content;
};

class Commit {
private:
    int id;
    string message;
    string author;
    string timestamp;
    int parentId;
    vector<StagedFile> snapshot;

public:
    Commit(int commitId, string commitMessage,
           string commitAuthor, string commitTime,
           int parentCommitId);

    Commit(int commitId, string commitMessage,
           string commitAuthor, string commitTime,
           int parentCommitId,
           vector<StagedFile> files);

    int getId();
    string getMessage();
    string getAuthor();
    string getTimestamp();
    int getParentId();
    vector<StagedFile> getSnapshot();
};

#endif