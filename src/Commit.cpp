#include "Commit.h"

Commit::Commit(int commitId, string commitMessage,
               string commitAuthor, string commitTime,
               int parentCommitId) {

    id = commitId;
    message = commitMessage;
    author = commitAuthor;
    timestamp = commitTime;
    parentId = parentCommitId;
    snapshot.clear();
}

Commit::Commit(int commitId, string commitMessage,
               string commitAuthor, string commitTime,
               int parentCommitId,
               vector<StagedFile> files) {

    id = commitId;
    message = commitMessage;
    author = commitAuthor;
    timestamp = commitTime;
    parentId = parentCommitId;
    snapshot = files;
}

int Commit::getId() {
    return id;
}

string Commit::getMessage() {
    return message;
}

string Commit::getAuthor() {
    return author;
}

string Commit::getTimestamp() {
    return timestamp;
}

int Commit::getParentId() {
    return parentId;
}

vector<StagedFile> Commit::getSnapshot() {
    return snapshot;
}