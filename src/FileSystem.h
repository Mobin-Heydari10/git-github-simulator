#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class File {
public:
    string name;
    vector<string> lines;

    File(string fileName);
};

class Directory {
public:
    string name;
    vector<File> files;
    vector<Directory> directories;

    Directory(string dirName);
};

class FileSystem {
private:
    Directory root;
    string currentPath;

public:
    FileSystem();

    void pwd();
    void mkdir(string dirName);
    void cd(string path);
    void ls();
    void touch(string fileName);
    void echo(string fileName, string text);
    void cat(string fileName);
    void rm(string fileName);
};

#endif