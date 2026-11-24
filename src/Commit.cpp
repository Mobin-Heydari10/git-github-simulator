#include "Commit.h"

Commit::Commit(int commitId, string commitMessage,
               string commitAuthor, string commitTime,
               int parentCommitId) {

    id = commitId;
    message = commitMessage;
    author = commitAuthor;
    timestamp = commitTime;
    parentId = parentCommitId;
}