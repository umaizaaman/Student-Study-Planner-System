#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>

#include "Student.h"

using namespace std;

/*
==========================================
Class : FileManager

This class manages:
- Save Student Data
- Load Student Data
- File Handling
==========================================
*/

class FileManager
{
public:

    FileManager();

    // File Handling Functions

    void saveStudent(const Student& student);

    void loadStudent(Student& student);

    ~FileManager();
};

#endif