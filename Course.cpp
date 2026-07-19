#include "Course.h"
#include "CustomException.h"

/*
==========================================
Class : Course

This class manages:
- Course Details
- Course Information
- Credit Hours
==========================================
*/

Course::Course()
    : courseName(""), courseCode(""), creditHours(0)
{

}

Course::Course(string courseName, string courseCode, int creditHours)
{
    setCourseName(courseName);
    setCourseCode(courseCode);
    setCreditHours(creditHours);
}

void Course::setCourseName(string courseName)
{
    if (courseName.empty())
    {
        throw InvalidCourseNameException();
    }

    this->courseName = courseName;
}

void Course::setCourseCode(string courseCode)
{
    if (courseCode.empty())
    {
        throw InvalidCourseCodeException();
    }

    this->courseCode = courseCode;
}

void Course::setCreditHours(int creditHours)
{
    if (creditHours <= 0)
    {
        throw InvalidCreditHoursException();
    }

    this->creditHours = creditHours;
}

string Course::getCourseName() const
{
    return courseName;
}

string Course::getCourseCode() const
{
    return courseCode;
}

int Course::getCreditHours() const
{
    return creditHours;
}

void Course::displayCourse(int number) const
{

    cout << "+------------------------------------------------------+\n";
    cout << "| Course : " << number << endl;
    cout << "| Course Name   : " << courseName << endl;
    cout << "| Course Code   : " << courseCode << endl;
    cout << "| Credit Hours  : " << creditHours << endl;
    cout << "+------------------------------------------------------+\n";

    cout << endl;
}

Course::~Course()
{

}