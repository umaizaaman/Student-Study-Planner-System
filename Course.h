#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

using namespace std;

/*
==========================================
Class : Course

This class manages:
- Course Details
- Course Information
- Credit Hours
==========================================
*/

class Course
{
private:
    string courseName;
    string courseCode;
    int creditHours;

public:
    Course();
    Course(string courseName, string courseCode, int creditHours);

    void setCourseName(string courseName);
    void setCourseCode(string courseCode);
    void setCreditHours(int creditHours);

    string getCourseName() const;
    string getCourseCode() const;
    int getCreditHours() const;

   void displayCourse(int number) const;

    ~Course();
};

#endif