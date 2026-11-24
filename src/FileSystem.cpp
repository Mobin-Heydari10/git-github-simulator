#include "FileSystem.h"
#include <stdexcept>

File::File(string fileName) {
    name = fileName;
}

Directory::Directory(string dirName) {
    name = dirName;
}

FileSystem::FileSystem() : root("/") {
    currentPath = "/";
}

void FileSystem::pwd() {
    cout << currentPath << endl;
}
void FileSystem::mkdir(string dirName) {

    if (dirName.empty()) {
        throw runtime_error("Directory name cannot be empty!");
    }

    if (dirName == "." || dirName == "..") {
        throw runtime_error("Invalid directory name!");
    }

    for (int i = 0; i < dirName.length(); i++) {
        char c = dirName[i];

        if (!((c >= 'a' && c <= 'z') ||
              (c >= 'A' && c <= 'Z') ||
              (c >= '0' && c <= '9') ||
              c == '_' || c == '-' || c == '.')) {
            throw runtime_error("Invalid directory name!");
        }
    }

    for (int i = 0; i < root.directories.size(); i++) {
        if (root.directories[i].name == dirName) {
            throw runtime_error("Directory already exists!");
        }
    }

    root.directories.push_back(Directory(dirName));

    cout << "Directory created successfully." << endl;
}
void FileSystem::cd(string path) {

    if (path.empty()) {
        throw runtime_error("Path cannot be empty!");
    }

    if (path == "/") {
        currentPath = "/";
        cout << "Changed directory to root." << endl;
        return;
    }

    if (path == "..") {

        if (currentPath == "/") {
            throw runtime_error("Already in root directory!");
        }

        currentPath = "/";
        cout << "Changed directory to root." << endl;
        return;
    }

    if (path == ".") {
        cout << "Already in current directory." << endl;
        return;
    }

    string dirName = path;

    if (path[0] == '/') {
        dirName = path.substr(1);
    }

    for (int i = 0; i < root.directories.size(); i++) {

        if (root.directories[i].name == dirName) {

            currentPath = "/" + dirName;

            cout << "Directory changed successfully." << endl;
            return;
        }
    }

    throw runtime_error("Directory not found!");
}