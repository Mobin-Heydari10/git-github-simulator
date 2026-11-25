#include "Branch.h"

Branch::Branch(string branchName, int lastCommitId) {
    name = branchName;
    commitId = lastCommitId;
}

string Branch::getName() {
    return name;
}

int Branch::getCommitId() {
    return commitId;
}

void Branch::setCommitId(int newCommitId) {
    commitId = newCommitId;
}