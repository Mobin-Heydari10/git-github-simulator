#include "Repository.h"
#include <ctime>

Repository::Repository() {
    initialized = false;
    userName = "";
    userEmail = "";

    nextCommitId=1;
    headCommitId=0;
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

    stagingArea.clear();
    commits.clear();

    nextCommitId=1;
    headCommitId=0;

    cout << "Initialized empty Git repository." << endl;
}
void Repository::add(string fileName, vector<string> content) {

    if (initialized == false) {
        throw runtime_error("Repository is not initialized!");
    }

    if (fileName.empty()) {
        throw runtime_error("File name cannot be empty!");
    }

    for (int i = 0; i < stagingArea.size(); i++) {

        if (stagingArea[i].fileName == fileName) {

            stagingArea[i].content = content;

            cout << "File updated in staging area." << endl;

            return;
        }
    }

    StagedFile file;

    file.fileName = fileName;
    file.content = content;

    stagingArea.push_back(file);

    cout << "File added to staging area." << endl;
}

vector<StagedFile> Repository::getStagingArea() {
    return stagingArea;
}

void Repository::commit(string message) {
    if (initialized == false) {
        throw runtime_error("Repository is not initialized!");
    }

    if (userName.empty() || userEmail.empty()) {
        throw runtime_error("User information is not configured!");
    }

    if (message.empty()) {
        throw runtime_error("Commit message cannot be empty!");
    }

    if (stagingArea.empty()) {
        throw runtime_error("Nothing to commit!");
    }

    if (commits.size() > 0) {
        vector<StagedFile> lastSnapshot =
            commits[commits.size() - 1].getSnapshot();

        bool same = true;

        if (stagingArea.size() != lastSnapshot.size()) {
            same = false;
        }

        if (same == true) {
            for (int i = 0; i < stagingArea.size(); i++) {
                if (stagingArea[i].fileName !=
                    lastSnapshot[i].fileName) {

                    same = false;
                    break;
                }

                if (stagingArea[i].content !=
                    lastSnapshot[i].content) {

                    same = false;
                    break;
                }
            }
        }

        if (same == true) {
            throw runtime_error("Nothing to commit!");
        }
    }

    time_t currentTime = time(0);

    tm* localTime = localtime(&currentTime);

    char timeBuffer[100];

    strftime(timeBuffer, sizeof(timeBuffer),
             "%Y-%m-%d %H:%M:%S", localTime);

    string commitTime = timeBuffer;

    int parentId = headCommitId;

    Commit newCommit(
        nextCommitId,
        message,
        userName + " <" + userEmail + ">",
        commitTime,
        parentId,
        stagingArea
    );

    commits.push_back(newCommit);

    headCommitId = nextCommitId;

    nextCommitId++;

    cout << "[" << headCommitId << "] "
         << message << endl;

    cout << "Commit created successfully." << endl;
}

vector<Commit> Repository::getCommits() {
    return commits;
}

int Repository::getHeadCommitId() {
    return headCommitId;
}

void Repository::reset(string fileName) {

    if (initialized == false) {
        throw runtime_error("Repository is not initialized!");
    }

    if (fileName.empty()) {
        throw runtime_error("File name cannot be empty!");
    }

    for (int i = 0; i < stagingArea.size(); i++) {

        if (stagingArea[i].fileName == fileName) {

            stagingArea.erase(stagingArea.begin() + i);

            cout << "File removed from staging area." << endl;

            return;
        }
    }

    throw runtime_error("File not found in staging area!");
}