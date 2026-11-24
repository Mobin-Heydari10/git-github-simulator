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
void FileSystem::ls() {

    Directory* currentDirectory = &root;

    if (currentPath != "/") {

        string dirName = currentPath.substr(1);

        bool found = false;

        for (int i = 0; i < root.directories.size(); i++) {

            if (root.directories[i].name == dirName) {

                currentDirectory = &root.directories[i];
                found = true;
                break;
            }
        }

        if (!found) {
            throw runtime_error("Current directory not found!");
        }
    }

    if (currentDirectory->directories.empty() &&
        currentDirectory->files.empty()) {

        cout << "Directory is empty." << endl;
        return;
    }

    for (int i = 0; i < currentDirectory->directories.size(); i++) {
        cout << currentDirectory->directories[i].name << endl;
    }

    for (int i = 0; i < currentDirectory->files.size(); i++) {
        cout << currentDirectory->files[i].name << endl;
    }
}
void FileSystem::touch(string fileName) {

    if (fileName.empty()) {
        throw runtime_error("File name cannot be empty!");
    }

    if (fileName == "." || fileName == "..") {
        throw runtime_error("Invalid file name!");
    }

    for (int i = 0; i < fileName.length(); i++) {

        char c = fileName[i];

        if (!((c >= 'a' && c <= 'z') ||
              (c >= 'A' && c <= 'Z') ||
              (c >= '0' && c <= '9') ||
              c == '_' || c == '-' || c == '.')) {

            throw runtime_error("Invalid file name!");
        }
    }

    Directory* currentDirectory = &root;

    if (currentPath != "/") {

        string dirName = currentPath.substr(1);

        bool found = false;

        for (int i = 0; i < root.directories.size(); i++) {

            if (root.directories[i].name == dirName) {

                currentDirectory = &root.directories[i];
                found = true;
                break;
            }
        }

        if (!found) {
            throw runtime_error("Current directory not found!");
        }
    }

    for (int i = 0; i < currentDirectory->files.size(); i++) {

        if (currentDirectory->files[i].name == fileName) {
            throw runtime_error("File already exists!");
        }
    }

    currentDirectory->files.push_back(File(fileName));

    cout << "File created successfully." << endl;
}
void FileSystem::echo(string fileName, string text) {

    if (fileName.empty()) {
        throw runtime_error("File name cannot be empty!");
    }

    Directory* currentDirectory = &root;

    if (currentPath != "/") {

        string dirName = currentPath.substr(1);

        bool found = false;

        for (int i = 0; i < root.directories.size(); i++) {

            if (root.directories[i].name == dirName) {

                currentDirectory = &root.directories[i];
                found = true;
                break;
            }
        }

        if (!found) {
            throw runtime_error("Current directory not found!");
        }
    }

    bool fileFound = false;

    for (int i = 0; i < currentDirectory->files.size(); i++) {

        if (currentDirectory->files[i].name == fileName) {

            currentDirectory->files[i].lines.push_back(text);

            fileFound = true;
            break;
        }
    }

    if (!fileFound) {
        throw runtime_error("File not found!");
    }

    cout << "Text added successfully." << endl;
}
void FileSystem::cat(string fileName) {

    if (fileName.empty()) {
        throw runtime_error("File name cannot be empty!");
    }

    Directory* currentDirectory = &root;

    if (currentPath != "/") {

        string dirName = currentPath.substr(1);

        bool found = false;

        for (int i = 0; i < root.directories.size(); i++) {

            if (root.directories[i].name == dirName) {

                currentDirectory = &root.directories[i];
                found = true;
                break;
            }
        }

        if (!found) {
            throw runtime_error("Current directory not found!");
        }
    }

    bool fileFound = false;

    for (int i = 0; i < currentDirectory->files.size(); i++) {

        if (currentDirectory->files[i].name == fileName) {

            fileFound = true;

            for (int j = 0; j < currentDirectory->files[i].lines.size(); j++) {

                cout << currentDirectory->files[i].lines[j] << endl;
            }

            break;
        }
    }

    if (!fileFound) {
        throw runtime_error("File not found!");
    }
}
void FileSystem::rm(string fileName) {

    if (fileName.empty()) {
        throw runtime_error("File name cannot be empty!");
    }

    Directory* currentDirectory = &root;

    if (currentPath != "/") {

        string dirName = currentPath.substr(1);

        bool found = false;

        for (int i = 0; i < root.directories.size(); i++) {

            if (root.directories[i].name == dirName) {

                currentDirectory = &root.directories[i];
                found = true;
                break;
            }
        }

        if (!found) {
            throw runtime_error("Current directory not found!");
        }
    }

    for (int i = 0; i < currentDirectory->directories.size(); i++) {

        if (currentDirectory->directories[i].name == fileName) {
            throw runtime_error("Cannot remove a directory!");
        }
    }

    bool fileFound = false;

    for (int i = 0; i < currentDirectory->files.size(); i++) {

        if (currentDirectory->files[i].name == fileName) {

            currentDirectory->files.erase(
                currentDirectory->files.begin() + i
            );

            fileFound = true;
            break;
        }
    }

    if (!fileFound) {
        throw runtime_error("File not found!");
    }

    cout << "File removed successfully." << endl;
}