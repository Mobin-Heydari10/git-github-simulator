#include "FileSystem.h"

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